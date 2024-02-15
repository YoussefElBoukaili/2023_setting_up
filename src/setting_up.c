/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting up
*/

#include "../include/my.h"

static long file_size(const char *filepath)
{
    long size;
    struct stat st;

    if (stat(filepath, &st) == -1)
        return 84;
    return st.st_size;
}

char *read_map(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    off_t size = file_size(filepath);
    char *buffer;
    char *new_buffer;
    int i = 0;

    if (fd == -1 || size == -1 || size == 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    new_buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    while (buffer[i] != '\n') {
        if (buffer[i] < '0' || buffer[i] > '9')
            return NULL;
        i += 1;
    }
    new_buffer = buffer + (i + 1);
    new_buffer[size] = '\0';
    close(fd);
    return new_buffer;
}

int count_height(const char *buffer)
{
    int height = 0;

    for (int k = 0; buffer[k] != '\0'; k++){
        if (buffer[k] == '\n')
            height++;
    }
    return height;
}

int calculate_width(const char *buffer, int height)
{
    int width;
    int index = 0;

    for (int i = 0; i < height; i++) {
        width = 0;
        while (buffer[index] != '\n' && buffer[index] != '\0') {
            width++;
            index++;
        }
        index++;
    }
    return width;
}

char **store_2d(char *buffer)
{
    int height = count_height(buffer);
    int width = calculate_width(buffer, height);
    char **map = malloc(sizeof(char *) * (height + 1));
    int index = 0;

    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * (width + 1));
        for (int j = 0; j < width; j++) {
            map[i][j] = buffer[index];
            index++;
        }
        index++;
        map[i][width] = '\0';
    }
    map[height] = NULL;
    return map;
}

static void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++){
        mini_printf("%s\n", map[i]);
    }
}

static void free_memory(char **map)
{
    for (int i = 0; map[i] != NULL; i++){
        free(map[i]);
    }
    free(map);
}

static void process(char *buffer, char **num_map, coords_t *coords)
{
    find_square(num_map, buffer, coords);
    return_map_normal(num_map, buffer);
    print_x(buffer, num_map, coords);
    print_map(num_map);
}

static void process_map(char *buffer, char **map, coords_t *coords)
{
    char **num_map = numeric_map(map, buffer);

    process(buffer, num_map, coords);
    free_memory(map);
    free_memory(num_map);
}

int main(int ac, char **av)
{
    char *buffer;
    char **map;
    coords_t coords;

    if (ac == 2) {
        if (read_map(av[1]) == NULL)
            return 84;
        buffer = read_map(av[1]);
        if (check_buffer(buffer) == 84)
            return 84;
        map = store_2d(buffer);
        process_map(buffer, map, &coords);
    } else if (ac == 3 && !(check_car(av) == 84 || my_getnbr(av[1]) <= 0)) {
        map = generate_map(my_getnbr(av[1]), av[2]);
        buffer = convert_map_to_buffer(map, my_getnbr(av[1]));
        process_map(buffer, map, &coords);
        free(buffer);
    } else {
        return 84;
    }
}
