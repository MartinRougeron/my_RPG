/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** input
*/

#include "my.h"

void inventoryinput(game_t *game, sfEvent event)
{
    if (event.type != sfEvtKeyPressed)
        return;
    if (event.key.code == sfKeyEscape) {
        if (game->player.inventory.lastclick != -1)
            game->player.inventory.lastclick = -1;
        else
            game->screen = GAME;
    }
}