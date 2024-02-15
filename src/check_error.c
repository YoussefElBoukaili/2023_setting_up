/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting up
*/

#include "../include/my.h"

int check_buffer(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!(buffer[i] == '.' || buffer[i] == 'o' || buffer[i] == '\n'))
            return 84;
    }
}

int check_car(char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (!(av[1][i] >= '0' && av[1][i] <= '9'))
            return 84;
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (!(av[2][i] == 'o' || av[2][i] == '.'))
            return 84;
    }
    if (my_strlen(av[2]) == 0)
        return 84;
}
