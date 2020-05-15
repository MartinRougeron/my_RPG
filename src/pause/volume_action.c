/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** volume_action
*/

#include "my.h"

void bottom_volume(game_t *game)
{
    static sfClock *clock = NULL;

    MUSIC_CHOICE;
    if (clock == NULL)
    clock = sfClock_create();
    if (TIME(clock) < 100)
        return;
    sfClock_restart(clock);
    if (hitsprite(game->pause.volume_high, (sfWindow*)game->window)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            if (game->pause.status_vol != 3)
                game->pause.status_vol++;
            else
                game->pause.status_vol = 0;
        }
    }
}