/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** a simple printf function
*/

#include "../include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        my_putstr("-2147483648");
    }
    if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10){
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return 0;
}

int switch_flag(const char *format, va_list ap)
{
    int num = 0;

    switch (*format) {
        case 'd':
        case 'i':
            num += my_put_nbr(va_arg(ap, int));
            break;
        case 'c':
            num += my_putchar(va_arg(ap, int));
            break;
        case 's':
            num += my_putstr(va_arg(ap, char *));
            break;
        case '%':
            num += my_putchar('%');
            break;
    }
    return num;
}

int mini_printf(const char *format, ...)
{
    int num = 0;
    va_list ap;

    va_start(ap, format);
    while (*format != '\0'){
        if (*format == '%'){
            format++;
            num += switch_flag(format, ap);
        } else {
            num += my_putchar(*format);
        }
        format++;
    }
    va_end(ap);
    return num;
}
