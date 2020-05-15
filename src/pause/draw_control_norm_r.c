/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_control_norm_r
*/

#include "my.h"

void norm_k_attack_c_r(game_t *game)
{
    game->menu.key_st.c_attack =
    all_call_char_key(game->menu.key_st.c_attack, game);
    game->key.attack = game->menu.num_key;
    sfText_setString(game->control.cont.k_attack,
    game->menu.key_st.c_attack);
    sfText_setString(game->control.cont_w.k_attack_w,
    game->menu.key_st.c_attack);
}

void norm_k_parade_c_r(game_t *game)
{
    game->menu.key_st.c_parade =
    all_call_char_key(game->menu.key_st.c_parade, game);
    game->key.map = game->menu.num_key;
    sfText_setString(game->control.cont.k_parade,
    game->menu.key_st.c_parade);
    sfText_setString(game->control.cont_w.k_parade_w,
    game->menu.key_st.c_parade);
}

void norm_k_pause_c_r(game_t *game)
{
    game->menu.key_st.c_pause =
    all_call_char_key(game->menu.key_st.c_pause, game);
    game->key.pause = game->menu.num_key;
    sfText_setString(game->control.cont.k_pause,
    game->menu.key_st.c_pause);
    sfText_setString(game->control.cont_w.k_pause_w,
    game->menu.key_st.c_pause);
}

void norm_k_changespell_c_r(game_t *game)
{
    game->menu.key_st.c_changespell =
    all_call_char_key(game->menu.key_st.c_changespell, game);
    game->key.changespell = game->menu.num_key;
    sfText_setString(game->control.cont.k_changespell,
    game->menu.key_st.c_changespell);
    sfText_setString(game->control.cont_w.k_changespell_w,
    game->menu.key_st.c_changespell);
}

void norm_k_interact_c_r(game_t *game)
{
    game->menu.key_st.c_interact =
    all_call_char_key(game->menu.key_st.c_interact, game);
    game->key.interact = game->menu.num_key;
    sfText_setString(game->control.cont.k_interact,
    game->menu.key_st.c_interact);
    sfText_setString(game->control.cont_w.k_interact_w,
    game->menu.key_st.c_interact);
}