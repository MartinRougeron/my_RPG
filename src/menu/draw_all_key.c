/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_all_key
*/

#include "my.h"

void draw_k_up(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -900)
        sfRenderWindow_drawText(game->window, game->menu.key_st.k_up, NULL);
    if (hittext(game->menu.key_set_w.k_up_w, (sfWindow*)game->window) &&
    game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText
        (game->window, game->menu.key_set_w.k_up_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue ||
        game->menu.status_key == 1) {
            game->menu.status_game = 1;
            game->menu.status_key = 1;
        }
    }
    norm_k_up(game);
}

void draw_k_down(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -840)
        sfRenderWindow_drawText(game->window, game->menu.key_st.k_down, NULL);
    if (hittext(game->menu.key_st.k_down, (sfWindow*)game->window)
    && game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText
        (game->window, game->menu.key_set_w.k_down_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 2) {
            game->menu.status_game = 1;
            game->menu.status_key = 2;
        }
    }
    norm_k_down(game);
}

void draw_k_left(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -780)
        sfRenderWindow_drawText(game->window, game->menu.key_st.k_left, NULL);
    if (hittext(game->menu.key_st.k_left, (sfWindow*)game->window) &&
    game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText
        (game->window, game->menu.key_set_w.k_left_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue ||
        game->menu.status_key == 3) {
            game->menu.status_game = 1;
            game->menu.status_key = 3;
        }
    }
    norm_k_left(game);
}

void draw_k_right(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -720)
        sfRenderWindow_drawText(game->window, game->menu.key_st.k_right, NULL);
    if (hittext(game->menu.key_st.k_right, (sfWindow*)game->window)
    && game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText(game->window,
        game->menu.key_set_w.k_right_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 4) {
            game->menu.status_game = 1;
            game->menu.status_key = 4;
        }
    }
    norm_k_right(game);
}

void draw_k_inventory(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -660)
        sfRenderWindow_drawText(game->window,
        game->menu.key_st.k_inventory, NULL);
    if (hittext(game->menu.key_st.k_inventory, (sfWindow*)game->window)
    && game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText(game->window,
        game->menu.key_set_w.k_inventory_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 12) {
            game->menu.status_game = 1;
            game->menu.status_key = 12;
        }
    }
    norm_k_inventory(game);
}