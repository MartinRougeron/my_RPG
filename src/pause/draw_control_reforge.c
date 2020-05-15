/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_control_reforge
*/

#include "my.h"

void control_k_attack(game_t *game)
{
    sfRenderWindow_drawText(game->window,game->control.cont.k_attack, NULL);
    if (hittext(game->control.cont.k_attack, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window,
        game->control.cont_w.k_attack_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 6;
        }
    }
    norm_k_attack_c(game);
}

void control_k_parade(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->control.cont.k_parade, NULL);
    if (hittext(game->control.cont.k_parade, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, game->control.cont_w.k_parade_w,
        NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 7;
        }
    }
    norm_k_parade_c(game);
}

void control_k_pause(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->control.cont.k_pause, NULL);
    if (hittext(game->control.cont.k_pause, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, game->control.cont_w.k_pause_w,
        NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 8;
        }
    }
    norm_k_pause_c(game);
}

void control_k_changespell(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->control.cont.k_changespell,
    NULL);
    if (hittext(game->control.cont.k_changespell, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window,
        game->control.cont_w.k_changespell_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 9;
        }
    }
    norm_k_changespell_c(game);
}

void control_k_interact(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->control.cont.k_interact, NULL);
    if (hittext(game->control.cont.k_interact, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, 
        game->control.cont_w.k_interact_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 10;
        }
    }
    norm_k_interact_c(game);
}
