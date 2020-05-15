/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_all_key_norm_r
*/

#include "my.h"

void norm_k_attack(game_t *game)
{
    if (game->menu.status_key == 5) {
        if (test(game)) {
            if (game->key.attack == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 5;
            }
            else if (game->menu.status_keys != 1) {
                norm_k_attack_r(game);
            }
        game->menu.status_keys = 0;
        }
    }
}

void norm_k_parade(game_t *game)
{
    if (game->menu.status_key == 6) {
        if (test(game)) {
            if (game->key.map == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 6;
            } else if (game->menu.status_keys != 1) {
                norm_k_parade_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_pause(game_t *game)
{
    if (game->menu.status_key == 7) {
        if (test(game)) {
            if (game->key.pause == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 7;
            } else if ( game->menu.status_keys != 1) {
                norm_k_pause_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_changspell(game_t *game)
{
    if (game->menu.status_key == 8) {
        if (test(game)) {
            if (game->key.changespell == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 8;
            } else if (game->menu.status_keys != 1) {
                norm_k_changspell_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void norm_k_interact(game_t *game)
{
    if (game->menu.status_key == 9) {
        if (test(game)) {
            if (game->key.interact == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->menu.status_game = 0;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                    game->menu.status_game = 1;
                    game->menu.status_key = 9;
            } else if (game->menu.status_keys != 1) {
                    norm_k_interact_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}