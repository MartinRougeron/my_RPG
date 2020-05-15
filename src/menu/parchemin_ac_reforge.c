/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parchemin_ac_reforge
*/

#include "my.h"

void parchments_action_on(game_t *game)
{
    int a = (sfTime_asMilliseconds(
    sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y < -200 &&
    sfSprite_getPosition(game->menu.parchemin).x < -499) {
        sfSprite_setPosition(game->menu.menu_pl.parchments, (sfVector2f)
        {sfSprite_getPosition(game->menu.menu_pl.parchments).x ,
        sfSprite_getPosition(game->menu.menu_pl.parchments).y + 1 * a});
    }
}

void parchments_action_off(game_t *game)
{
    int a = (sfTime_asMilliseconds(
    sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_3_status == 2 && sfSprite_getPosition
    (game->menu.menu_pl.parchments).y >= -1350 &&
    sfSprite_getPosition(game->menu.parchemin).x < -499) {
        sfSprite_setPosition(game->menu.menu_pl.parchments,
        (sfVector2f) {sfSprite_getPosition(game->menu.menu_pl.parchments).x ,
        sfSprite_getPosition(game->menu.menu_pl.parchments).y - 1 * a});
    }
}