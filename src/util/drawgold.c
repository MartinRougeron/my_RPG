/*
** EPITECH PROJECT, 2020
** util
** File description:
** draw gold
*/

#include "my.h"

void drawgold(game_t *game)
{
    if (game->hide[GOLD] == TRUE) {
        sfSprite_setTransparent(game->hud.gold, 128);
        sfText_setTransparent(game->hud.goldtxt, 128,
        sfText_getColor(game->hud.goldtxt));
    } else {
        sfSprite_setTransparent(game->hud.gold, 255);
        sfText_setTransparent(game->hud.goldtxt, 255,
        sfText_getColor(game->hud.goldtxt));
    }
    sfText_setString(game->hud.goldtxt, my_itoa(game->player.inventory.gold));
    sfRenderWindow_drawSprite(game->window, game->hud.gold, NULL);
    sfRenderWindow_drawText(game->window, game->hud.goldtxt, NULL);
}