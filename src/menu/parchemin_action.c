/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parchemin_action
*/

#include "my.h"

void parchemin_action_on(game_t *game)
{
    int a = (sfTime_asMilliseconds(sfClock_getElapsedTime
    (game->menu.parch_clock)));
    if (game->menu.parch_1_status == 1 && sfSprite_getPosition
    (game->menu.buttom_exit_black).x > -332 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfSprite_setPosition(game->menu.buttom_exit_black, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_exit_black). x - 1 * a ,
        sfSprite_getPosition(game->menu.buttom_exit_black).y});
    if (game->menu.parch_1_status == 1 && sfSprite_getPosition
    (game->menu.buttom_exit_white).x > -332 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfSprite_setPosition(game->menu.buttom_exit_white, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_exit_white). x - 1 * a ,
        sfSprite_getPosition(game->menu.buttom_exit_white).y});
}

void parchemin_action_off(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_1_status == 2 && sfSprite_getPosition
    (game->menu.buttom_exit_black).x < 168 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfSprite_setPosition(game->menu.buttom_exit_black, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_exit_black). x + 1 * a ,
        sfSprite_getPosition(game->menu.buttom_exit_black).y});
    if (game->menu.parch_1_status == 2 && sfSprite_getPosition
    (game->menu.buttom_exit_white).x < 168 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfSprite_setPosition(game->menu.buttom_exit_white, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_exit_white). x + 1 * a ,
        sfSprite_getPosition(game->menu.buttom_exit_white).y});
    parchemin_action_offf(game);
    parchemin_action_offff(game);
    parchemin_action_offfff(game);
}

void parchment_action_on(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_2_status == 1 && sfSprite_getPosition
    (game->menu.parchment).y < -200 && sfSprite_getPosition
    (game->menu.parchemin).x < -499) {
        sfSprite_setPosition(game->menu.parchment, (sfVector2f)
        {sfSprite_getPosition(game->menu.parchment).x ,
        sfSprite_getPosition(game->menu.parchment).y + 1 * a});
    }
}

void parchment_action_off(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_2_status == 2 &&
    sfSprite_getPosition(game->menu.parchment).y >= -1350 &&
    sfSprite_getPosition(game->menu.parchemin).x < -499) {
        sfSprite_setPosition(game->menu.parchment, (sfVector2f)
        {sfSprite_getPosition(game->menu.parchment).x , sfSprite_getPosition
        (game->menu.parchment).y - 1 * a});
    }
}