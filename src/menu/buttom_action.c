/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttom_action
*/

#include "my.h"

void bottom_play_action(game_t *game)
{
    if (hitsprite(game->menu.buttom_play_black, (sfWindow*)game->window)) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.buttom_play_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->menu.parch_1_status = 1;
            game->menu.parch_3_status = 1;
        }
    } else
        sfRenderWindow_drawSprite(game->window,
        game->menu.buttom_play_black, NULL);
    return;
}

void bottom_setting_action(game_t *game)
{
    if (hitsprite(game->menu.buttom_setting_white, (sfWindow*)game->window)) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.buttom_setting_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->menu.parch_1_status = 1;
            game->menu.parch_2_status = 1;
        }
    } else
        sfRenderWindow_drawSprite(game->window,
        game->menu.buttom_setting_black, NULL);
    return;
}

void bottom_exit_action(game_t *game)
{
    if (hitsprite(game->menu.buttom_exit_white, (sfWindow*)game->window)) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.buttom_exit_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_drawSprite(game->window,
            game->menu.buttom_setting_white, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                sfWindow_close((sfWindow *) game->window);
        }
    } else
        sfRenderWindow_drawSprite(game->window,
        game->menu.buttom_exit_black, NULL);
    return;
}

void bottom_arrow_action(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -950)
    sfRenderWindow_drawSprite(game->window, game->menu.menu_st.arrow, NULL);
    if (hitsprite(game->menu.menu_st.arrow,
    (sfWindow*)game->window) && game->menu.parch_2_status == 1) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.menu_st.arrow_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->menu.parch_1_status = 2;
            game->menu.parch_2_status = 2;
        }
    }
}

void bottom_arrow_action_play(game_t *game)
{
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -950)
    sfRenderWindow_drawSprite(game->window,
    game->menu.menu_st.arrow, NULL);
    if (hitsprite(game->menu.menu_st.arrow,
    (sfWindow*)game->window) && game->menu.parch_3_status == 1) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.menu_st.arrow_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->menu.parch_1_status = 2;
            game->menu.parch_3_status = 2;
        }
    }
}