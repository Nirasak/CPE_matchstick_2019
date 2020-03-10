/*
** EPITECH PROJECT, 2020
** ia.c
** File description:
** ia
*/

#include <stdlib.h>
#include "my.h"

void misere(game_t *game)
{
    int one_stick = (count_lines_one_stick(game) + 1) % 2;
    int nb_stick_max = 0;
    int line_max = 0;

    for (int i = 1; game->map[i] != NULL; i++)
        if (count_matches_line(game, i) > nb_stick_max) {
            nb_stick_max = count_matches_line(game, i);
            line_max = i;
        }
    game->sticks = nb_stick_max - one_stick;
    game->sticks = game->sticks % (game->max_sticks + 1);
    game->line = line_max;
}

void rmv_a_stick_game(game_t *game)
{
    for (int i = 1; game->map[i] != NULL; i++)
        if (count_matches_line(game, i) > 0) {
            game->sticks = 1;
            game->line = i;
            return;
        }
}

void make_xor_zero(game_t *game, int xor)
{
    int total = 0;

    for (int i = 1; game->map[i] != NULL; i++) {
        total = xor ^ count_matches_line(game, i);
        if (total < count_matches_line(game, i)) {
            game->sticks =
                (count_matches_line(game, i) - total) % (game->max_sticks + 1);
            game->line = i;
            return;
        }
    }
    rmv_a_stick_game(game);
}

void ia(game_t *game)
{
    int xor = get_xor(game);
    int mult_stick = count_lines_mult_sticks(game);

    if (mult_stick <= 1)
        misere(game);
    else if (xor == 0)
        rmv_a_stick_game(game);
    else
        make_xor_zero(game, xor);
    if (game->sticks == 0)
        rmv_a_stick_game(game);
    rmv_matches(game);
    my_printf("AI's turn...\n");
    my_printf(
        "AI removed %d match(es) from line %d\n", game->sticks, game->line);
}
