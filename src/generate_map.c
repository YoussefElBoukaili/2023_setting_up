/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting up
*/

#include "../include/my.h"

char **generate_map(int n, const char *pattern)
{
    int pattern_length = my_strlen(pattern);
    char **map = malloc(sizeof(char *) * (n + 1));
    int total_chars = 0;

    for (int i = 0; i != n; i++) {
        map[i] = malloc(sizeof(char) * (n + 1));
        for (int j = 0; j != n; j++){
            map[i][j] = pattern[total_chars % pattern_length];
            total_chars++;
        }
        map[i][n] = '\0';
    }
    map[n] = NULL;
    return map;
}

char *convert_map_to_buffer(char **map, int n)
{
    char *buffer = malloc(sizeof(char) * (n * n + n + 1));
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buffer[index] = map[i][j];
            index++;
        }
        buffer[index] = '\n';
        index++;
    }
    buffer[index] = '\0';
    return buffer;
}
