/*
** EPITECH PROJECT, 2020
** annex_ia.c
** File description:
** ia
*/

#include <stdlib.h>
#include "my.h"

int get_xor(game_t *game)
{
    int count = 0;
    int result = 0;

    for (int i = 1; game->map[i] != NULL; i++)
        if ((count = count_matches_line(game, i)) != 1)
            result = result ^ count;
    return (result);
}

int count_lines_mult_sticks(game_t *game)
{
    int count = 0;

    for (int i = 1; game->map[i] != NULL; i++)
        if (count_matches_line(game, i) > 1)
            count++;
    return (count);
}

int count_lines_one_stick(game_t *game)
{
    int count = 0;

    for (int i = 1; game->map[i] != NULL; i++)
        if (count_matches_line(game, i) == 1)
            count++;
    return (count);
}
