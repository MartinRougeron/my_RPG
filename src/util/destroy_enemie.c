/*
** EPITECH PROJECT, 2020
** desroy
** File description:
** destroy
*/

#include "my.h"

void destroy_enemie(game_t *game)
{
    for (int i = 0; i != NBMAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        sfSprite_destroy(game->enemie[i].sprite);
        game->enemie[i].sprite = NULL;
    }
}