/*
** EPITECH PROJECT, 2020
** imput
** File description:
** imput
*/

#include "my.h"

void changescreen(game_t *game, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(game->key.tree))
        action_tree_input(game);
    if (sfKeyboard_isKeyPressed(game->key.pause))
        action_pause_input(game);
    if (sfKeyboard_isKeyPressed(game->key.inventory)) {
        if (game->screen != INVENTORY && game->is_tuto != INV)
            game->screen = INVENTORY;
        else {
            game->screen = GAME;
            game->player.inventory.lastclick = -1;
        }
    }
    if (game->screen == INVENTORY) {
        inventoryinput(game, event);
        return;
    }
}

void imput(game_t *game, sfEvent event)
{
    static float zoom_in = 0;

    if (event.type == sfEvtKeyPressed) {
        action_input(game);
        changescreen(game, event);
    }
    if (game->player.talking != -1 && sfKeyboard_isKeyPressed(sfKeyEscape))
        game->player.talking = -1;
    if (sfView_getSize(game->view).x < 1920)
        zoom_in = 1;
    if (game->is_tuto == ZOOM && sfView_getSize(game->view).x >= 1920 &&
    zoom_in) {
            game->is_tuto = LVLUP;
            game->player.xp += 1;
            makelevelup(game);
        }
    if (event.type == sfEvtMouseWheelMoved)
        zoom(game, event);
}