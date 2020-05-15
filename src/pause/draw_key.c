/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_key.c
*/

#include "my.h"

void draw_key_up(game_t *game)
{
    if (test_reforge_control(game)) {
        if (game->key.up == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->screen = 8;
        }
        if (control_all_key_c(game) == 1 && game->menu.status_keys != 1) {
            game->screen = 9;
            game->menu.status_key = 1;
        } else if (game->menu.status_keys != 1) {
            game->menu.key_st.c_up =
            all_call_char_key(game->menu.key_st.c_up, game);
            game->key.up = game->menu.num_key;
            sfText_setString(game->control.cont.k_up,
            game->menu.key_st.c_up);
            sfText_setString(game->control.cont_w.k_up_w,
            game->menu.key_st.c_up);
        }
        game->menu.status_keys = 0;
    }
}

void draw_key_down(game_t *game)
{
    if (test_reforge_control(game)) {
        if (game->key.down == game->menu.num_key) {
            game->menu.status_keys = 2;
            game->screen = 8;
        }
        if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
            game->screen = 9;
            game->menu.status_key = 2;
        } else if (game->menu.status_keys != 1) {
            game->menu.key_st.c_down =
            all_call_char_key(game->menu.key_st.c_down, game);
            game->key.down = game->menu.num_key;
            sfText_setString(game->control.cont.k_down,
            game->menu.key_st.c_down);
            sfText_setString(game->control.cont_w.k_down_w,
            game->menu.key_st.c_down);
        }
        game->menu.status_keys = 0;
    }
}

void draw_key_left(game_t *game)
{
    if (test_reforge_control(game)) {
        if (game->key.left == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->screen = 8;
        }
        if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
            game->screen = 9;
            game->menu.status_key = 3;
        } else if (game->menu.status_keys != 1) {
            game->menu.key_st.c_left =
            all_call_char_key(game->menu.key_st.c_left, game);
            game->key.left = game->menu.num_key;
            sfText_setString(game->control.cont.k_left,
            game->menu.key_st.c_left);
            sfText_setString(game->control.cont_w.k_left_w,
            game->menu.key_st.c_left);
        }
        game->menu.status_keys = 0;
    }
}

void draw_key_right(game_t *game)
{
    if (test_reforge_control(game)) {
        if (game->key.right == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->screen = 8;
        }
        if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
            game->screen = 9;
            game->menu.status_key = 4;
        } else if (game->menu.status_keys != 1) {
            game->menu.key_st.c_right =
            all_call_char_key(game->menu.key_st.c_right, game);
            game->key.right = game->menu.num_key;
            sfText_setString(game->control.cont.k_right,
            game->menu.key_st.c_right);
            sfText_setString(game->control.cont_w.k_right_w,
            game->menu.key_st.c_right);
        }
        game->menu.status_keys = 0;
    }
}

void draw_key_inventory(game_t *game)
{
    if (test_reforge_control(game)) {
        if (game->key.inventory == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->screen = 8;
        }
        if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
            game->screen = 9;
            game->menu.status_key = 5;
        } else if (game->menu.status_keys != 1) {
            game->menu.key_st.c_inventory =
            all_call_char_key(game->menu.key_st.c_up, game);
            game->key.inventory = game->menu.num_key;
            sfText_setString(game->control.cont.k_inventory,
            game->menu.key_st.c_inventory);
            sfText_setString(game->control.cont_w.k_inventory_w,
            game->menu.key_st.c_inventory);
        }
        game->menu.status_keys = 0;
    }
}