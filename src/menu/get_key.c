/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_key
*/

#include "my.h"

int test_reforge_control(game_t *game)
{
    sfEvent event;
    int i = 0;

    while (sfRenderWindow_pollEvent(game->window, &event))
        if (event.type == sfEvtKeyPressed) {
            game->menu.num_key = event.key.code;
            game->screen = 8;
            game->menu.status_key = 0;
            i++;
        }
    return i;
}