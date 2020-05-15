/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_all_key
*/

#include "my.h"

int all_call_norm(game_t *game)
{
    if (game->menu.num_key == game->key.changespell)
        return 1;
    if (game->menu.num_key == game->key.changestance)
        return 1;
    if (game->menu.num_key == game->key.inventory)
        return 1;
    if (game->menu.num_key == game->key.attack)
        return 1;
    return 0;
}

int all_call_norm_r(game_t *game)
{
    if (game->menu.num_key == game->key.pause)
        return 1;
    if (game->menu.num_key == game->key.changespell)
        return 1;
    if (game->menu.num_key == game->key.changestance)
        return 1;
    if (game->menu.num_key == game->key.inventory)
        return 1;
    if (game->menu.num_key == game->key.attack)
        return 1;
    return 0;
}

int check_all_key(game_t *game)
{
    if (game->menu.num_key == game->key.interact)
        return 1;
    if (game->menu.num_key == game->key.up)
        return 1;
    if (game->menu.num_key == game->key.down)
        return 1;
    if (game->menu.num_key == game->key.left)
        return 1;
    if (game->menu.num_key == game->key.right)
        return 1;
    if (game->menu.num_key == game->key.map)
        return 1;
    if (game->menu.num_key == game->key.pause)
        return 1;
    all_call_norm(game);
    return 0;
}

int control_all_key_c(game_t *game)
{
    if (game->menu.num_key == game->key.interact)
        return 1;
    if (game->menu.num_key == game->key.up)
        return 1;
    if (game->menu.num_key == game->key.down)
        return 1;
    if (game->menu.num_key == game->key.left)
        return 1;
    if (game->menu.num_key == game->key.right)
        return 1;
    if (game->menu.num_key == game->key.map)
        return 1;
    all_call_norm_r(game);
    return 0;
}