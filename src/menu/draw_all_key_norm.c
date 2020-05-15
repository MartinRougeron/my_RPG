/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_all_key_norm
*/

#include "my.h"

void norm_k_up(game_t *game)
{
    if (game->menu.status_key == 1) {
        if (test(game)) {
            if (game->key.up == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 1;
            } else if (game->menu.status_keys != 1) {
                norm_k_up_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_down(game_t *game)
{
    if (game->menu.status_key == 2) {
        if (test(game)) {
            if (game->key.down == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 2;
            } else if (game->menu.status_keys != 1) {
                norm_k_down_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_left(game_t *game)
{
    if (game->menu.status_key == 3) {
        if (test(game)) {
            if (game->key.left == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 3;
            } else if (game->menu.status_keys != 1) {
                norm_k_left_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_right(game_t *game)
{
    if (game->menu.status_key == 4) {
        if (test(game)) {
            if (game->key.right == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 4;
            } else if (game->menu.status_keys != 1) {
                norm_k_right_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_inventory(game_t *game)
{
    if (game->menu.status_key == 12) {
        if (test(game)) {
            if (game->key.inventory == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 12;
            } else if (game->menu.status_keys != 1) {
                norm_k_inventory_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}