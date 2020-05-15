/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parchemin_ac
*/

#include "my.h"

void parchemin_ac_norm(game_t *game)
{
    int a = (sfTime_asMilliseconds(sfClock_getElapsedTime
    (game->menu.parch_clock)));
    if (game->menu.parch_1_status == 1 && sfSprite_getPosition
    (game->menu.buttom_setting_white).x > -410 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfSprite_setPosition(game->menu.buttom_setting_white, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_setting_white). x - 1 * a ,
        sfSprite_getPosition(game->menu.buttom_setting_white).y});
}

void parchemin_action_onn(game_t *game)
{
    int a = (sfTime_asMilliseconds(sfClock_getElapsedTime
    (game->menu.parch_clock)));
    if (game->menu.parch_1_status == 1 && sfSprite_getPosition
    (game->menu.buttom_play_white).x > -332 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfSprite_setPosition(game->menu.buttom_play_white, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_play_white). x - 1 * a ,
        sfSprite_getPosition(game->menu.buttom_play_white).y});
    if (game->menu.parch_1_status == 1 && sfSprite_getPosition
    (game->menu.buttom_setting_black).x > -410 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfSprite_setPosition(game->menu.buttom_setting_black, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_setting_black). x - 1 * a ,
        sfSprite_getPosition(game->menu.buttom_setting_black).y});
    parchemin_ac_norm(game);
}

void parchemin_action_onnn(game_t *game)
{
    int a = (sfTime_asMilliseconds(sfClock_getElapsedTime
    (game->menu.parch_clock)));
    if (game->menu.parch_1_status == 1 && sfSprite_getPosition
    (game->menu.parchemin).x >= -500 &&
    (sfSprite_getPosition(game->menu.parchment).y <= -1350 ||
    sfSprite_getPosition(game->menu.menu_pl.parchments).y <= -1350))
        sfSprite_setPosition(game->menu.parchemin, (sfVector2f)
        {sfSprite_getPosition(game->menu.parchemin). x - 1 * a ,
        sfSprite_getPosition(game->menu.parchemin).y});
    if (game->menu.parch_1_status == 1 && sfSprite_getPosition
    (game->menu.buttom_play_black).x > -332 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfSprite_setPosition(game->menu.buttom_play_black, (sfVector2f)
        {sfSprite_getPosition(game->menu.buttom_play_black).x - 1 * a ,
        sfSprite_getPosition(game->menu.buttom_play_black).y});
}

void parchemin_action_onnnn(game_t *game)
{
    int a = (sfTime_asMilliseconds(sfClock_getElapsedTime
    (game->menu.parch_clock)));
    if (game->menu.parch_1_status == 1 && sfText_getPosition
    (LOAD_MENU.buttom_load_game).x > -400 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfText_setPosition(LOAD_MENU.buttom_load_game, (sfVector2f)
        {sfText_getPosition(LOAD_MENU.buttom_load_game). x - 1 * a ,
        sfText_getPosition(LOAD_MENU.buttom_load_game).y});
    if (game->menu.parch_1_status == 1 && sfText_getPosition
    (LOAD_MENU.buttom_load_game_white).x > -400 &&
    sfSprite_getPosition(game->menu.parchment).y <= -1350)
        sfText_setPosition(LOAD_MENU.buttom_load_game_white,
        (sfVector2f)
        {sfText_getPosition
        (LOAD_MENU.buttom_load_game_white).x - 1 * a ,
        sfText_getPosition(LOAD_MENU.buttom_load_game_white).y});
}