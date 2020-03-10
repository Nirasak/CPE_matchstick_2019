/*
** EPITECH PROJECT, 2020
** player.c
** File description:
** player
*/

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"

int get_info(game_t *game, int i)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
        return (-1);
    if (my_str_isnum(line) == false) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (i == 0)
        game->line = my_atoi(line);
    if (i == 1)
        game->sticks = my_atoi(line);
    return (0);
}

int count_matches_line(game_t *game, int line)
{
    int sticks = 0;

    for (int i = 0; i <= game->nb_lines * 2; i++)
        if (game->map[line][i] == '|')
            sticks++;
    return (sticks);
}

int rmv_matches(game_t *game)
{
    int sticks = count_matches_line(game, game->line);

    if (sticks < game->sticks) {
        my_printf("Error: not enough matches on this line\n");
        return (1);
    }
    sticks = game->sticks;
    for (int i = game->nb_lines * 2; i >= 0; i--)
        if (game->map[game->line][i] == '|' && sticks > 0) {
            game->map[game->line][i] = ' ';
            sticks--;
            game->tot_sticks--;
        }
    return (0);
}

int get_matches(game_t *game, char *str)
{
    int status = get_info(game, 1);

    if (status != 0)
        return (status);
    if (game->sticks <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (1);
    }
    if (game->sticks > game->max_sticks) {
        my_printf(
            "Error: you cannot remove more "
            "than %d matches per turn\n", game->max_sticks);
        return (1);
    }
    free(str);
    return (rmv_matches(game));
}

int player(game_t *game)
{
    int status = 0;

    my_printf("Line: ");
    if ((status = get_info(game, 0)) != 0)
        return (status);
    if (game->line <= 0 || game->line > game->nb_lines) {
        my_printf("Error: this line is out of range\n");
        return (1);
    }
    my_printf("Matches: ");
    return (get_matches(game, NULL));
}
