/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting up
*/

#include "../include/my.h"

int my_strlen(const char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}
