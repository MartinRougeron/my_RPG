/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_control
*/

#include "my.h"

void control_k_up(game_t *game)
{
        sfRenderWindow_drawText(game->window, game->control.cont.k_up, NULL);
    if (hittext(game->control.cont.k_up, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, game->control.cont_w.k_up_w,
        NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 1;
        }
    }
    if (game->menu.status_key == 1) {
        draw_key_up(game);
    }
}

void control_k_down(game_t *game)
{
        sfRenderWindow_drawText(game->window, game->control.cont.k_down, NULL);
    if (hittext(game->control.cont.k_down, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, game->control.cont_w.k_down_w,
        NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 2;
        }
    }
    if (game->menu.status_key == 2) {
        draw_key_down(game);
    }
}

void control_k_left(game_t *game)
{
        sfRenderWindow_drawText(game->window, game->control.cont.k_left, NULL);
    if (hittext(game->control.cont.k_left, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, game->control.cont_w.k_left_w,
        NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 3;
        }
    }
    if (game->menu.status_key == 3) {
        draw_key_left(game);
    }
}

void control_k_right(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->control.cont.k_right, NULL);
    if (hittext(game->control.cont.k_right, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, game->control.cont_w.k_right_w,
        NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 4;
        }
    }
    if (game->menu.status_key == 4) {
        draw_key_right(game);
    }
}

void control_k_inventory(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->control.cont.k_inventory,
    NULL);
    if (hittext(game->control.cont.k_inventory, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window,
        game->control.cont_w.k_inventory_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 5;
        }
    }
    if (game->menu.status_key == 5) {
        draw_key_inventory(game);
    }
}