/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>

typedef struct game
{
    char **map;
    int nb_lines;
    int max_sticks;
    int line;
    int sticks;
    int tot_sticks;
} game_t;

int my_printf(char const *str, ...);
bool init_struct(game_t *game, char **av);
int matchstick(game_t *game);
int my_atoi(char *av);
bool my_str_isnum(char const *str);
int player(game_t *game);
void ia(game_t *game);
int count_matches_line(game_t *game, int i);
int get_xor(game_t *game);
int count_lines_one_stick(game_t *game);
int rmv_matches(game_t *game);
int count_lines_mult_sticks(game_t *game);

#endif
