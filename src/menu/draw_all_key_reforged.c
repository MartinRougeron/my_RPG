/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_all_key_reforged
*/

#include "my.h"

void draw_k_attack(game_t *game)
{
    if (game->menu.parch_2_status == 1 && sfSprite_getPosition
    (game->menu.parchment).y > -600)
        sfRenderWindow_drawText(game->window,
        game->menu.key_st.k_attack, NULL);
    if (hittext(game->menu.key_st.k_attack, (sfWindow*)game->window)
    && game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText(game->window,
        game->menu.key_set_w.k_attack_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 5) {
            game->menu.status_game = 1;
            game->menu.status_key = 5;
        }
    }
    norm_k_attack(game);
}

void draw_k_parade(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -540)
        sfRenderWindow_drawText(game->window,
        game->menu.key_st.k_parade, NULL);
    if (hittext(game->menu.key_st.k_parade,
    (sfWindow*)game->window) && game->menu.parch_2_status == 1 &&
    game->menu.status_game != 1) {
        sfRenderWindow_drawText(game->window,
        game->menu.key_set_w.k_parade_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 6) {
            game->menu.status_game = 1;
            game->menu.status_key = 6;
        }
    }
    norm_k_parade(game);
}

void draw_k_pause(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -480)
        sfRenderWindow_drawText(game->window, game->menu.key_st.k_pause, NULL);
    if (hittext(game->menu.key_st.k_pause,
    (sfWindow*)game->window) && game->menu.parch_2_status == 1 &&
    game->menu.status_game != 1) {
        sfRenderWindow_drawText(game->window,
        game->menu.key_set_w.k_pause_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 7) {
            game->menu.status_game = 1;
            game->menu.status_key = 7;
        }
    }
    norm_k_pause(game);
}

void draw_k_changespell(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -420)
        sfRenderWindow_drawText(game->window,
        game->menu.key_st.k_changespell, NULL);
    if (hittext(game->menu.key_st.k_changespell, (sfWindow*)game->window)
    && game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText(game->window,
        game->menu.key_set_w.k_changespell_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 8) {
            game->menu.status_game = 1;
            game->menu.status_key = 8;
        }
    }
    norm_k_changspell(game);
}

void draw_k_interact(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -360)
        sfRenderWindow_drawText(game->window,
        game->menu.key_st.k_interact, NULL);
    if (hittext(game->menu.key_st.k_interact, (sfWindow*)game->window) &&
    game->menu.parch_2_status == 1 && game->menu.status_game != 1) {
        sfRenderWindow_drawText(game->window,
        game->menu.key_set_w.k_interact_w, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
            || game->menu.status_key == 9) {
            game->menu.status_game = 1;
            game->menu.status_key = 9;
        }
    }
    norm_k_interact(game);
}