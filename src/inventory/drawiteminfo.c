/*
** EPITECH PROJECT, 2020
** inv
** File description:
** draw item info
*/

#include "my.h"

void drawiteminfo(game_t *game, item_t item)
{
    sfText *text[2] = {NULL, NULL};

    if (text[0] == NULL) {
        text[0] = createsimpletext("", (sfVector2f) {620, 860}, 15);
        text[1] = createsimpletext("", (sfVector2f) {620, 889}, 15);
    }
    sfText_setString(text[0], item.name);
    sfText_setString(text[1], item.descrption);
    sfRenderWindow_drawText(game->window, text[0], NULL);
    sfRenderWindow_drawText(game->window, text[1], NULL);
}