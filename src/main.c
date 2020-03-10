/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    game_t game;

    if (ac != 3)
        return (84);
    if (init_struct(&game, av) == false)
        return (84);
    return (matchstick(&game));
}
