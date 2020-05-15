/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** all_key_norm_r
*/

#include "my.h"

void norm_k_up_r(game_t *game)
{
    game->menu.key_st.c_up =
    all_call_char_key(game->menu.key_st.c_up, game);
    game->key.up = game->menu.num_key;
    sfText_setString(game->menu.key_st.k_up, game->menu.key_st.c_up);
    sfText_setString(game->menu.key_set_w.k_up_w,
    game->menu.key_st.c_up);
}

void norm_k_down_r(game_t *game)
{
    game->menu.key_st.c_down =
    all_call_char_key(game->menu.key_st.c_down, game);
    game->key.down = game->menu.num_key;
    sfText_setString(game->menu.key_st.k_down,
    game->menu.key_st.c_down);
    sfText_setString(game->menu.key_set_w.k_down_w,
    game->menu.key_st.c_down);
}

void norm_k_left_r(game_t *game)
{
    game->menu.key_st.c_left =
    all_call_char_key(game->menu.key_st.c_left, game);
    game->key.left = game->menu.num_key;
    sfText_setString(game->menu.key_st.k_left,
    game->menu.key_st.c_left);
    sfText_setString(game->menu.key_set_w.k_left_w,
    game->menu.key_st.c_left);
}

void norm_k_right_r(game_t *game)
{
    game->menu.key_st.c_right =
    all_call_char_key(game->menu.key_st.c_right, game);
    game->key.right = game->menu.num_key;
    sfText_setString(game->menu.key_st.k_right,
    game->menu.key_st.c_right);
    sfText_setString(game->menu.key_set_w.k_right_w,
    game->menu.key_st.c_right);
}

void norm_k_inventory_r(game_t *game)
{
    game->menu.key_st.c_inventory =
    all_call_char_key(game->menu.key_st.c_inventory, game);
    game->key.inventory = game->menu.num_key;
    sfText_setString(game->menu.key_st.k_inventory,
    game->menu.key_st.c_inventory);
    sfText_setString(game->menu.key_set_w.k_inventory_w,
    game->menu.key_st.c_inventory);
}