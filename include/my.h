/*
** EPITECH PROJECT, 2023
** my
** File description:
** my header
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>

typedef struct coords_s {
    int x;
    int y;
    int biggest_square;
} coords_t;

int my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int switch_flag(const char *format, va_list ap);

int mini_printf(const char *format, ...);

static long file_size(const char *filepath);

char *read_map(const char *filepath);

int count_height(const char *buffer);

int calculate_width(const char *buffer, int height);

char **store_2d(char *buffer);

static void num_map_sub(char **map, int i, int j, char **num_map);

char **numeric_map(char **map, char *buffer);

void find_min(char **tab, int i, int j, coords_t *index);

void find_square(char **tab, char *buffer, coords_t *coords);

void return_map_normal(char **map, char *buffer);

static void back_to_normal(char **map, int i, int j);

void print_x(char *buffer, char **map, coords_t *coords);

static void print_map(char **map);

static void free_memory(char **map);

char **generate_map(int n, const char *pattern);

char *convert_map_to_buffer(char **map, int n);

static void process(char *buffer, char **num_map, coords_t *coords);

static int skip(char const **str);

static int check_big(int neg, int res, int digit);

int my_getnbr(char const *str);

int my_strlen(const char *str);

int check_buffer(char *buffer);

int check_car(char **av);

#endif /* MY_H_ */
