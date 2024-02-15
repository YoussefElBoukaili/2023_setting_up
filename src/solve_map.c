/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting up
*/

#include "../include/my.h"

static void num_map_sub(char **map, int i, int j, char **num_map)
{
    if (map[i][j] == '.')
        num_map[i][j] = '1';
    else if (map[i][j] == 'o')
        num_map[i][j] = '0';
    else
        num_map[i][j] = map[i][j];
}

char **numeric_map(char **map, char *buffer)
{
    int height = count_height(buffer);
    int width = calculate_width(buffer, height);
    char **num_map = malloc(sizeof(char *) * (height + 1));

    for (int i = 0; i < height; i++) {
        num_map[i] = malloc(sizeof(char) * (width + 1));
        for (int j = 0; j < width; j++) {
            num_map_sub(map, i, j, num_map);
        }
        num_map[i][width] = '\0';
    }
    num_map[height] = NULL;
    return num_map;
}

void find_min(char **map, int i, int j, coords_t *coords)
{
    int min = map[i][j - 1];

    if (map[i][j] == '1'){
        if (map[i - 1][j] < min){
            min = map[i - 1][j];
        }
        if (map[i - 1][j - 1] < min){
            min = map[i - 1][j - 1];
        }
        map[i][j] = min + 1;
    }
    if (map[i][j] > coords->biggest_square){
        coords->biggest_square = map[i][j];
        coords->x = i;
        coords->y = j;
    }
}

void find_square(char **map, char *buffer, coords_t *coords)
{
    int height = count_height(buffer);
    int width = calculate_width(buffer, height);

    coords->biggest_square = 0;
    coords->x = 0;
    coords->y = 0;
    for (int i = 1; i < height; ++i) {
        for (int j = 1; j < width; j++) {
            find_min(map, i, j, coords);
        }
    }
    coords->biggest_square -= '0';
}

static void back_to_normal(char **map, int i, int j)
{
    if (map[i][j] != '0')
        map[i][j] = '.';
    else if (map[i][j] == '0')
        map[i][j] = 'o';
}

void return_map_normal(char **map, char *buffer)
{
    int height = count_height(buffer);
    int width = calculate_width(buffer, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            back_to_normal(map, i, j);
        }
    }
}

void print_x(char *buffer, char **map, coords_t *coords)
{
    int height = count_height(buffer);
    int width = calculate_width(buffer, height);

    for (int i = 0; i < coords->biggest_square; i++) {
        for (int j = 0; j < coords->biggest_square; j++) {
            map[coords->x - i][coords->y - j] = 'x';
        }
    }
}
