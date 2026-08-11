#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

int get_digit_value(char c) {
    if (c >= '0' && c <= '9') 
	    return c - '0';
    if (c >= 'a' && c <= 'z') 
	    return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') 
	    return c - 'A' + 10;
    return -1;
}

int ft_atoi_base(char *str, char *base) {
    int result = 0;
    int base_len = 0;
    int digit;

    while (base[base_len]) base_len++;
    if (base_len < 2) 
	    return 0;

    while (*str == ' ' || (*str >= 9 && *str <= 13)) 
	    str++;
    
    while (*str) {
        digit = get_digit_value(*str);
        if (digit < 0 || digit >= base_len) 
		break;
        result = result * base_len + digit;
        str++;
    }
    return result;
}

void ft_putnbr_base(int nbr, char *base) {
    int base_len = 0;
    long n;

    while (base[base_len]) base_len++;
    if (base_len < 2) 
	    return;

    n = nbr;
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n >= base_len) {
        ft_putnbr_base(n / base_len, base);
    }
    ft_putchar(base[n % base_len]);
}

int main(void) {
    char input_str[100];
    char src_base[20];
    char dest_base[20];
    int decimal_value;

    printf("================================\n");
    printf("   ADVANCED BASE CONVERTER C    \n");
    printf("================================\n");
    
    printf("Enter the number to convert: ");
    if (scanf("%99s", input_str) != 1) 
	    return 1;

    printf("Enter source base (e.g., 0123456789 for decimal): ");
    if (scanf("%19s", src_base) != 1) 
	    return 1;

    printf("Enter destination base (e.g., 01 for binary, 0123456789ABCDEF for hex): ");
    if (scanf("%19s", dest_base) != 1) 
	    return 1;

    decimal_value = ft_atoi_base(input_str, src_base);

    printf("\n--------------------------------\n");
    printf("Result:\n");
    ft_putnbr_base(decimal_value, dest_base);
    printf("\n--------------------------------\n");

    return 0;
}
