/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_control_norm
*/

#include "my.h"

void norm_k_attack_c(game_t *game)
{
    if (game->menu.status_key == 6) {
        if (test_reforge_control(game)) {
            if (game->key.attack == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->screen = 8;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 6;
            } else if (game->menu.status_keys != 1) {
                norm_k_attack_c_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_parade_c(game_t *game)
{
    if (game->menu.status_key == 7) {
        if (test_reforge_control(game)) {
            if (game->key.map == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->screen = 8;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 7;
            } else if (game->menu.status_keys != 1) {
                norm_k_parade_c_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_pause_c(game_t *game)
{
    if (game->menu.status_key == 8) {
            if (test_reforge_control(game)) {
            if (game->key.pause == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->screen = 8;
            }
        if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 1;
            } else if (game->menu.status_keys != 1) {
                norm_k_pause_c_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_changespell_c(game_t *game)
{
    if (game->menu.status_key == 9) {
        if (test_reforge_control(game)) {
            if (game->key.changespell == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->screen = 8;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 9;
            } else if (game->menu.status_keys != 1) {
                norm_k_changespell_c_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_interact_c(game_t *game)
{
    if (game->menu.status_key == 10) {
        if (test_reforge_control(game)) {
            if (game->key.interact == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->screen = 8;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->screen = 9;
                game->menu.status_key = 1;
            } else if (game->menu.status_keys != 1) {
                norm_k_interact_c_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}