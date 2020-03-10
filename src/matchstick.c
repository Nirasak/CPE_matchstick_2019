/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick
*/

#include <stdlib.h>
#include "my.h"

void print_map(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i++)
        my_printf("%s\n", game->map[i]);
    if (game->tot_sticks != 0)
        my_printf("\n");
}

int matchstick(game_t *game)
{
    int status = 0;

    while (game->tot_sticks > 0) {
        my_printf("Your turn:\n");
        while ((status = player(game)) == 1);
        if (status == -1)
            return (0);
        my_printf("Player removed %d match(es)"
        " from line %d\n", game->sticks, game->line);
        print_map(game);
        if (game->tot_sticks == 0) {
            my_printf("You lost, too bad...\n");
            return (2);
        }
        ia(game);
        print_map(game);
    }
    my_printf("I lost... snif... but I'll get you next time!!\n");
    return (1);
}
