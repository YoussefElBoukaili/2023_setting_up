/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** my_getnbr
*/

#include "../include/my.h"

static int skip(char const **str)
{
    int neg = 1;

    while (**str != '\0' && (**str < 48 || **str > 57)) {
        if (**str == 45) {
            neg *= -1;
        }
        (*str)++;
    }
    return neg;
}

static int check_big(int neg, int res, int digit)
{
    int int_max = 2147483647;
    int int_min = -2147483648;

    if ((res > (int_max - digit) / 10) && neg == 1) {
        return 1;
    }
    if ((res > (int_min - digit) / 10) && neg == -1) {
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int neg = skip(&str);
    int res = 0;
    int digit;

    while (*str >= '0' && *str <= '9') {
        digit = *str - '0';
        if (check_big(neg, res, digit) == 1) {
            return 0;
        }
        res = res * 10 + digit;
        str++;
    }
    res *= neg;
    return res;
}
