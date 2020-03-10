/*
** EPITECH PROJECT, 2020
** init_struct.c
** File description:
** init struct
*/

#include <stdlib.h>
#include "my.h"

bool my_str_isnum(char const *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    for (; str[i] != '\0' && str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

void init_line(game_t *game, int i)
{
    int nb_spaces = game->nb_lines - i;
    int nb_sticks = i * 2 - 1;
    int j = 0;

    game->tot_sticks += nb_sticks;
    for (; j <= game->nb_lines * 2; j++) {
        if (i == 0 || i == game->nb_lines + 1
            || j == 0 || j == game->nb_lines * 2)
            game->map[i][j] = '*';
        else if (j > nb_spaces && nb_sticks > 0) {
            game->map[i][j] = '|';
            nb_sticks--;
        }
        else
            game->map[i][j] = ' ';
    }
    game->map[i][j] = '\0';
}

bool init_map(game_t *game)
{
    int i = 0;

    if ((game->map = malloc(sizeof(char *) * (game->nb_lines + 3))) == NULL)
        return (false);
    for (; i < game->nb_lines + 2; i++) {
        game->map[i] = malloc(sizeof(char) * (game->nb_lines * 2 + 2));
        if (game->map[i] == NULL)
            return (false);
        init_line(game, i);
        my_printf("%s\n", game->map[i]);
    }
    my_printf("\n");
    game->map[i] = NULL;
    return (true);
}

bool init_struct(game_t *game, char **av)
{
    game->line = 0;
    game->sticks = 0;
    if (my_str_isnum(av[1]) == false || my_str_isnum(av[2]) == false)
        return (false);
    game->nb_lines = my_atoi(av[1]);
    if (game->nb_lines < 2 || game->nb_lines > 99)
        return (false);
    game->max_sticks = my_atoi(av[2]);
    if (game->max_sticks <= 0)
        return (false);
    game->tot_sticks = -game->nb_lines * 2;
    if (init_map(game) == false)
        return (false);
    return (true);
}
