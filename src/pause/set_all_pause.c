/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_all_pause
*/

#include "my.h"

void set_all_pause(game_t *game)
{
    set_all_control(game), set_all_control_key(game);
    set_all_control_key_w(game);
    game->pause.status_cursor = 0;
    game->pause.status_vol = 0;
    game->menu.status_keys = 0;
    game->menu.status_key = 0;
    game->pause.volume_off = loadbutton("assets/pause/volume_off.png",
    (sfVector2f) {1.2, 1.2}, (sfVector2f) {720, 820});
    game->pause.volume_high = loadbutton("assets/pause/volume_high.png",
    (sfVector2f) {1.2, 1.2}, (sfVector2f) {720, 820});
    game->pause.volume_low = loadbutton("assets/pause/volume_low.png",
    (sfVector2f) {1.2, 1.2}, (sfVector2f) {720, 820});
    game->pause.volume_mid = loadbutton("assets/pause/volume_mid.png",
    (sfVector2f) {1.2, 1.2}, (sfVector2f) {720, 820});
    game->pause.pause_text = loadtext_pause("menu pause",
    (sfVector2f) {1, 1}, (sfVector2f) {720, 230}, 50);
    game->pause.pause_sprite =
    loadbutton("assets/gui/pause_sprite.png",
    (sfVector2f) {4.5, 4.5}, (sfVector2f) {550, 180});
    draw_pause_0(game);
}

void set_all_control(game_t *game)
{
    draw_pause_1(game);
    game->control.t_inventory = loadtext_pause("INVENTORY",
    (sfVector2f){1, 1}, (sfVector2f) {680, 600}, 30);
    game->control.t_attack = loadtext_pause("ATTACK",
    (sfVector2f){1, 1}, (sfVector2f) {680, 650}, 30);
    game->control.t_parade = loadtext_pause("PARADE",
    (sfVector2f){1, 1}, (sfVector2f) {680, 700}, 30);
    game->control.t_pause = loadtext_pause("PAUSE",
    (sfVector2f){1, 1}, (sfVector2f) {680, 750}, 30);
    game->control.t_changespell = loadtext_pause("CHANGESPELL",
    (sfVector2f){1, 1}, (sfVector2f) {680, 800}, 30);
    game->control.t_interact = loadtext_pause("INTERACT",
    (sfVector2f){1, 1}, (sfVector2f) {680, 850}, 30);
    game->control.t_changestance = loadtext_pause("CHANGESTANCE",
    (sfVector2f){1, 1}, (sfVector2f) {680, 900}, 30);
}

void set_all_control_key(game_t *game)
{
    draw_pause_2(game);
    game->control.cont.k_attack = loadtext_pause(game->menu.key_st.c_attack,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 650}, 30);
    game->control.cont.k_parade = loadtext_pause(game->menu.key_st.c_parade,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 700}, 30);
    game->control.cont.k_pause = loadtext_pause(game->menu.key_st.c_pause,
    (sfVector2f) {1, 1}, (sfVector2f) {1100, 750}, 30);
    game->control.cont.k_changespell = loadtext_pause
    (game->menu.key_st.c_changespell, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 800}, 30);
    game->control.cont.k_interact = loadtext_pause
    (game->menu.key_st.c_interact, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 850}, 30);
    game->control.cont.k_changestance = loadtext_pause
    (game->menu.key_st.c_changestance, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 900}, 30);
}

void set_all_control_key_w(game_t *game)
{
    draw_pause_3(game);
    game->control.cont_w.k_parade_w = loadtext_pause_white
    (game->menu.key_st.c_parade, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 700}, 30);
    game->control.cont_w.k_pause_w = loadtext_pause_white
    (game->menu.key_st.c_pause, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 750}, 30);
    game->control.cont_w.k_changespell_w = loadtext_pause_white
    (game->menu.key_st.c_changespell, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 800}, 30);
    game->control.cont_w.k_interact_w = loadtext_pause_white
    (game->menu.key_st.c_interact, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 850}, 30);
    game->control.cont_w.k_changestance_w = loadtext_pause_white
    (game->menu.key_st.c_changestance, (sfVector2f) {1, 1},
    (sfVector2f) {1100, 900}, 30);
}