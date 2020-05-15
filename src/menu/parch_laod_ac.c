/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parch_laod_ac
*/

#include "my.h"

void parchment_load_on(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_4_status == 1 && sfSprite_getPosition
    (LOAD_MENU.parche).x > 1300 && sfSprite_getPosition
    (game->menu.parchemin).x < -499) {
        sfSprite_setPosition(LOAD_MENU.parche, (sfVector2f)
        {sfSprite_getPosition(LOAD_MENU.parche).x - 1 * a ,
        sfSprite_getPosition(LOAD_MENU.parche).y});
    }
}

void parchment_load_off(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_4_status == 2 &&
    sfSprite_getPosition(LOAD_MENU.parche).x <= 2000) {
        sfSprite_setPosition(LOAD_MENU.parche, (sfVector2f)
        {sfSprite_getPosition(LOAD_MENU.parche).x + 1 * a,
        sfSprite_getPosition(LOAD_MENU.parche).y});
    }
}