/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** selectio_option.c
*/

#include "my.h"

void selection_music(game_t *game)
{
    if (game->first_item++ == 0) {
        sfMusic_play(game->music[SELECTION_S]);
        sfMusic_play(game->music[SELECTION_S]);
    }
}
