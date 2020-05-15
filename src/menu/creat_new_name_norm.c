/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** creat_new_name_norm
*/

#include "my.h"

void name_norm(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyDelete) ||
        sfKeyboard_isKeyPressed(sfKeyBack))) {
            if (game->menu.menu_pl.name > 0) {
                game->player.name[game->menu.menu_pl.name - 1] = '\0';
                sfText_setString(game->menu.menu_pl.white_text,
                game->player.name);
                game->menu.menu_pl.name -= 1;
            }
            return;
        }
}

void name_norm_r(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            game->menu.status_game = 0;
            return;
        }
        if (game->menu.menu_pl.name < 10) {
            game->menu.status_game = 2;
            all_char_forname(game->player.name, game, game->menu.menu_pl.name);
            if (game->player.name[game->menu.menu_pl.name] != 0)
                game->menu.menu_pl.name += 1;
        }
}
