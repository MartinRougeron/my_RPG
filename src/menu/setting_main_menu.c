/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** setting_main_menu
*/

#include "my.h"

void call_status(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.fond, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.parchemin, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.parchment, NULL);
    creat_new_name(game);
    sfText_setString(game->menu.menu_pl.white_text, game->player.name);
    all_call_else(game);
    all_parch(game);
    all_parch_reforged(game);
    bottom_play_game(game);
    animplayer(game);
}

void call_status_else(game_t *game)
{
    all_call_else(game);
    all_parch(game);
    draw_all_play(game);
    all_parch_reforged(game);
    creat_new_name(game);
    bottom_play_game(game);
    bottom_arrow_action_play(game);
    animplayer(game);
    changeplayertexture(game);
    sfClock_restart(game->menu.parch_clock);
}