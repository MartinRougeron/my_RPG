/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttom_action_pause
*/

#include "my.h"

int bottom_resume(game_t *game, int select)
{
    if (select == 0) {
    sfRenderWindow_drawText(game->window, game->pause.resume_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue ||
        sfKeyboard_isKeyPressed(sfKeyReturn)) {
            game->screen = 1;
        }
    } else
    sfRenderWindow_drawText(game->window,
        game->pause.resume, NULL);
    if (hittext(game->pause.resume, (sfWindow*)game->window))
        select = 0;
    return select;
}

int bottom_setting(game_t *game, int select)
{
    if (select == 1) {
    sfRenderWindow_drawText(game->window,
    game->pause.setting_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue ||
        sfKeyboard_isKeyPressed(sfKeyReturn)) {
            game->screen = 7;
        }
    } else
    sfRenderWindow_drawText(game->window, game->pause.setting, NULL);
    if (hittext(game->pause.setting, (sfWindow*)game->window))
        select = 1;
    return select;
}

int bottom_exit(game_t *game, int select)
{
    if (select == 2) {
    sfRenderWindow_drawText(game->window,
    game->pause.exit_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue ||
        sfKeyboard_isKeyPressed(sfKeyReturn)) {
            sfRenderWindow_close(game->window);
    }
    } else
    sfRenderWindow_drawText(game->window,
        game->pause.exit, NULL);
    if (hittext(game->pause.exit, (sfWindow*)game->window))
        select = 2;
    return select;
}