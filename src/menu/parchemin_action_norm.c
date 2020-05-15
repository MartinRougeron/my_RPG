/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parchemin_action_norm
*/

#include "my.h"

void parchemin_action_offf(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_1_status == 2 && sfSprite_getPosition
    (game->menu.buttom_play_white).x < 168 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfSprite_setPosition(game->menu.buttom_play_white, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_play_white). x + 1 * a ,
        sfSprite_getPosition(game->menu.buttom_play_white).y});
    if (game->menu.parch_1_status == 2 && sfSprite_getPosition
    (game->menu.buttom_setting_black).x < 90 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfSprite_setPosition(game->menu.buttom_setting_black, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_setting_black). x + 1 * a ,
        sfSprite_getPosition(game->menu.buttom_setting_black).y});
    if (game->menu.parch_1_status == 2 && sfSprite_getPosition
    (game->menu.buttom_setting_white).x < 90 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfSprite_setPosition(game->menu.buttom_setting_white, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_setting_white). x + 1 * a ,
        sfSprite_getPosition(game->menu.buttom_setting_white).y});
}

void parchemin_action_offff(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_1_status == 2 && sfSprite_getPosition
    (game->menu.buttom_play_black).x < 168 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfSprite_setPosition(game->menu.buttom_play_black, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_play_black). x + 1 * a ,
        sfSprite_getPosition(game->menu.buttom_play_black).y});
    if (game->menu.parch_1_status == 2 && sfSprite_getPosition
    (game->menu.parchemin).x <= -15 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfSprite_setPosition(game->menu.parchemin, (sfVector2f)
        {sfSprite_getPosition(game->menu.parchemin). x + 1 * a ,
        sfSprite_getPosition(game->menu.parchemin).y});
}

void parchemin_action_offfff(game_t *game)
{
    int a =
    (sfTime_asMilliseconds(sfClock_getElapsedTime(game->menu.parch_clock)));
    if (game->menu.parch_1_status == 2 && sfText_getPosition
    (LOAD_MENU.buttom_load_game).x < 100 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfText_setPosition(LOAD_MENU.buttom_load_game, (sfVector2f)
        {sfText_getPosition(LOAD_MENU.buttom_load_game). x + 1 * a ,
        sfText_getPosition(LOAD_MENU.buttom_load_game).y});
    if (game->menu.parch_1_status == 2 && sfText_getPosition
    (LOAD_MENU.buttom_load_game_white).x < 100 && sfSprite_getPosition
    (game->menu.parchment).y <= -1350 && game->menu.parch_3_status != 2)
        sfText_setPosition(LOAD_MENU.buttom_load_game_white, (sfVector2f)
        {sfText_getPosition(LOAD_MENU.buttom_load_game_white). x + 1 * a ,
        sfText_getPosition(LOAD_MENU.buttom_load_game_white).y});
}