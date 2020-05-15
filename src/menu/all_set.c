/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** all_set
*/

#include "my.h"

void all_set_buttom(game_t *game)
{
    put_button(game);
    game->menu.menu_st.arrow =
    loadbutton("assets/menu/setting/fleche.png",
    (sfVector2f) {0.3, 0.3}, (sfVector2f) {580, 50});
    game->menu.menu_pl.frame =
    loadbutton("assets/menu/play/cadre.png",
    (sfVector2f) {0.7, 0.7}, (sfVector2f) {800, 200});
    LOAD_MENU.buttom_load_game = loadtext("Load Game", (sfVector2f)
    {1, 1}, (sfVector2f) {100, 570}, 70);
    LOAD_MENU.buttom_load_game_white = loadtext_white("Load Game",
    (sfVector2f) {1, 1}, (sfVector2f) {100, 570}, 70);
    LOAD_MENU.load_game = loadtext("Load Game", (sfVector2f)
    {1, 1}, (sfVector2f) {100, 570}, 70);
    all_set_load(game);
    all_set_load_reforge(game);
}

void all_set_text(game_t *game)
{
    game->menu.menu_st.t_up = loadtext("UP", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 200}, 50);
    game->menu.menu_st.t_down = loadtext("DOWN", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 260}, 50);
    game->menu.menu_st.t_left = loadtext("LEFT", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 320}, 50);
    game->menu.menu_st.t_right = loadtext("RIGHT", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 380}, 50);
    game->menu.menu_st.t_inventory = loadtext("INVENTORY", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 440}, 50);
    game->menu.menu_st.t_attack = loadtext("ATTACK", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 500}, 50);
    game->menu.menu_st.t_parade = loadtext("MAP", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 560}, 50);
}

void all_set_name(game_t *game)
{
    game->menu.menu_pl.white_text = loadtext(game->player.name,
    (sfVector2f) {1, 1}, (sfVector2f) {800, 650}, 50);
}

void all_set_key_text(game_t *game)
{
    game->menu.key_st.k_up = loadtext(game->menu.key_st.c_up,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 200}, 50);
    game->menu.key_st.k_down = loadtext(game->menu.key_st.c_down,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 260}, 50);
    game->menu.key_st.k_left = loadtext(game->menu.key_st.c_left,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 320}, 50);
    game->menu.key_st.k_right = loadtext(game->menu.key_st.c_right,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 380}, 50);
    game->menu.key_st.k_inventory = loadtext(game->menu.key_st.c_inventory,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 440}, 50);
    game->menu.key_st.k_attack = loadtext(game->menu.key_st.c_attack,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 500}, 50);
    game->menu.key_st.k_parade = loadtext(game->menu.key_st.c_parade,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 560}, 50);
    game->menu.key_st.k_pause = loadtext(game->menu.key_st.c_pause,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 620}, 50);
    game->menu.key_st.k_changespell = loadtext(game->menu.key_st.c_changespell,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 680}, 50);
}

void all_set_key_text_white(game_t *game)
{
    game->menu.key_set_w.k_up_w = loadtext_white(game->menu.key_st.c_up,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 200}, 50);
    game->menu.key_set_w.k_down_w = loadtext_white(game->menu.key_st.c_down,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 260}, 50);
    game->menu.key_set_w.k_left_w = loadtext_white(game->menu.key_st.c_left,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 320}, 50);
    game->menu.key_set_w.k_right_w = loadtext_white(game->menu.key_st.c_right,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 380}, 50);
    game->menu.key_set_w.k_inventory_w = loadtext_white(game->menu.key_st.
    c_inventory, (sfVector2f) {1, 1}, (sfVector2f) {1150, 440}, 50);
    game->menu.key_set_w.k_attack_w = loadtext_white
    (game->menu.key_st.c_attack, (sfVector2f) {1, 1},
    (sfVector2f) {1150, 500}, 50);
    game->menu.key_set_w.k_parade_w = loadtext_white(game->menu.key_st.
    c_parade, (sfVector2f) {1, 1}, (sfVector2f) {1150, 560}, 50);
    game->menu.key_set_w.k_pause_w = loadtext_white(game->menu.key_st.c_pause,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 620}, 50);
    game->menu.key_set_w.k_changespell_w = loadtext_white(game->menu.key_st.
    c_changespell, (sfVector2f) {1, 1}, (sfVector2f) {1150, 680}, 50);
}