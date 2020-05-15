/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttom_action_load
*/

#include "my.h"

void bottom_load_action(game_t *game)
{
    if (hittext(LOAD_MENU.buttom_load_game_white,
    (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window,
        LOAD_MENU.buttom_load_game_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->menu.parch_1_status = 1;
            game->menu.parch_4_status = 1;
        }
    } else
        sfRenderWindow_drawText(game->window,
        LOAD_MENU.buttom_load_game, NULL);
    return;
}

void bottom_ar_action(game_t *game)
{
    if (game->menu.parch_4_status == 1 &&
    sfSprite_getPosition(LOAD_MENU.parche).x < 1400)
    sfRenderWindow_drawSprite(game->window, LOAD_MENU.aro, NULL);
    if (hitsprite(LOAD_MENU.aro,
    (sfWindow*)game->window) && game->menu.parch_4_status == 1) {
        sfRenderWindow_drawSprite(game->window,
        LOAD_MENU.aro_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->menu.parch_1_status = 2;
            game->menu.parch_4_status = 2;
        }
    }
}

void bottom_game_action(game_t *game)
{
    if (!got_a_save() &&
    sfSprite_getPosition(LOAD_MENU.parche).x < 1400)
        sfRenderWindow_drawText(game->window,
        LOAD_MENU.load_game_grey, NULL);
    else {
        if (game->menu.parch_4_status == 1 &&
        sfSprite_getPosition(LOAD_MENU.parche).x < 1400)
            sfRenderWindow_drawText(game->window,
            LOAD_MENU.load_game, NULL);
        if (hittext(LOAD_MENU.load_game,
        (sfWindow*)game->window) && game->menu.parch_4_status == 1) {
            sfRenderWindow_drawText(game->window,
            LOAD_MENU.load_game_white, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
                loadsave(game, "./.load/save.load");
                load_main(game, game->window);
                game->screen = GAME;
            }
        }
    }
}

void bottom_triva_action(game_t *game)
{
    if (!got_a_save() &&
    sfSprite_getPosition(LOAD_MENU.parche).x < 1400)
        sfRenderWindow_drawText(game->window,
        LOAD_MENU.load_triviatan_grey, NULL);
    else {
        if (game->menu.parch_4_status == 1 &&
        sfSprite_getPosition(LOAD_MENU.parche).x < 1400)
            sfRenderWindow_drawText(game->window,
            LOAD_MENU.load_triviatan, NULL);
        if (hittext(LOAD_MENU.load_triviatan,
        (sfWindow*)game->window) && game->menu.parch_4_status == 1) {
            sfRenderWindow_drawText(game->window,
            LOAD_MENU.load_triviatan_white, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
                loadsave(game, "./.load/trivia.load");
                load_main(game, game->window);
                game->screen = GAME;
            }
        }
    }
}

void bottom_dragon_action(game_t *game)
{
    if (!got_a_save() &&
    sfSprite_getPosition(LOAD_MENU.parche).x < 1400)
        sfRenderWindow_drawText(game->window,
        LOAD_MENU.load_dragon_grey, NULL);
    else {
        if (game->menu.parch_4_status == 1 &&
        sfSprite_getPosition(LOAD_MENU.parche).x < 1400)
            sfRenderWindow_drawText(game->window,
            LOAD_MENU.load_dragon, NULL);
        if (hittext(LOAD_MENU.load_dragon,
        (sfWindow*)game->window) && game->menu.parch_4_status == 1) {
            sfRenderWindow_drawText(game->window,
            LOAD_MENU.load_dragon_white, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
                loadsave(game, "./.load/dragon.load");
                load_main(game, game->window);
                game->screen = GAME;
            }
        }
    }
}