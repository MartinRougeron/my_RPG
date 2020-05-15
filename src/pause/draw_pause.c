/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_pause.c
*/

#include "my.h"

void draw_pause_0(game_t *game)
{
    game->pause.resume = loadtext_pause("resume",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 450}, 50);
    game->pause.exit = loadtext_pause("exit",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 600}, 50);
    game->pause.setting = loadtext_pause("setting",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 750}, 50);
    game->pause.resume_white = loadtext_pause_white("resume",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 450}, 50);
    game->pause.exit_white = loadtext_pause_white("exit",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 600}, 50);
    game->pause.setting_white = loadtext_pause_white("setting",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 750}, 50);
    game->pause.control = loadtext_pause("control",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 450}, 50);
    game->pause.control_white = loadtext_pause_white("control",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 450}, 50);
    game->pause.cursor = loadtext_pause("cursor",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 600}, 50);
    game->pause.cursor_white = loadtext_pause_white("cursor",
    (sfVector2f) {1, 1}, (sfVector2f) {820, 600}, 50);
}

void draw_pause_1(game_t *game)
{
    game->control.t_up = loadtext_pause("UP",
    (sfVector2f) {1, 1}, (sfVector2f) {680, 400}, 30);
    game->control.t_down = loadtext_pause("DOWN",
    (sfVector2f){1, 1}, (sfVector2f) {680, 450}, 30);
    game->control.t_left = loadtext_pause("LEFT",
    (sfVector2f){1, 1}, (sfVector2f) {680, 500}, 30);
    game->control.t_right = loadtext_pause("RIGHT",
    (sfVector2f){1, 1}, (sfVector2f) {680, 550}, 30);
}

void draw_pause_2(game_t *game)
{
    game->control.cont.k_up = loadtext_pause(game->menu.key_st.c_up,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 400}, 30);
    game->control.cont.k_down = loadtext_pause(game->menu.key_st.c_down,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 450}, 30);
    game->control.cont.k_left = loadtext_pause(game->menu.key_st.c_left,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 500}, 30);
    game->control.cont.k_right = loadtext_pause(game->menu.key_st.c_right,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 550}, 30);
    game->control.cont.k_inventory =
    loadtext_pause(game->menu.key_st.c_inventory,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 600}, 30);
}

void draw_pause_3(game_t *game)
{
    game->control.cont_w.k_up_w = loadtext_pause_white
    (game->menu.key_st.c_up, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 400}, 30);
    game->control.cont_w.k_down_w = loadtext_pause_white
    (game->menu.key_st.c_down, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 450}, 30);
    game->control.cont_w.k_left_w = loadtext_pause_white
    (game->menu.key_st.c_left, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 500}, 30);
    game->control.cont_w.k_right_w = loadtext_pause_white
    (game->menu.key_st.c_right, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 550}, 30);
    game->control.cont_w.k_inventory_w = loadtext_pause_white
    (game->menu.key_st.c_inventory, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 600}, 30);
    game->control.cont_w.k_attack_w = loadtext_pause_white
    (game->menu.key_st.c_attack, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 650}, 30);
}