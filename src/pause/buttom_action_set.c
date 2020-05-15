/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttom_action_set
*/

#include "my.h"

void bottom_control(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->pause.control, NULL);
    if (hittext(game->pause.control, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window,
        game->pause.control_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 8;
        }
    }
}

void bottom_cursor_on(game_t *game)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    sfRenderWindow_drawText(game->window, game->pause.cursor, NULL);
    if (hittext(game->pause.cursor, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window, game->pause.cursor_white, NULL);
        if (TIME(clock) < 100) return;
        sfClock_restart(clock);
    }
    if (hittext(game->pause.cursor, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window,
        game->pause.cursor_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfRenderWindow_setMouseCursorVisible(game->window,
            ((game->pause.status_cursor == 0) ? sfFalse : sfTrue));
            game->pause.status_cursor = ((game->pause.status_cursor == 0) ? 1 :
            0);
        }
    }
}
