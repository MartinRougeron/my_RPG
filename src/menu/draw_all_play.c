/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_all_play
*/

#include "my.h"

void draw_all_play(game_t *game)
{
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -800)
        sfRenderWindow_drawSprite(game->window,
        game->menu.menu_pl.frame, NULL);
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -750)
        sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -650)
        sfRenderWindow_drawText(game->window, game->menu.menu_pl.chose_name,
        NULL);
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -600)
        sfRenderWindow_drawText(game->window, game->menu.menu_pl.white_text,
        NULL);
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -400)
        sfRenderWindow_drawSprite(game->window, game->menu.menu_pl.rec, NULL);
}