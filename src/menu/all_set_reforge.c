/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** all_set_reforge
*/

#include "my.h"

void all_set_text_reforge(game_t *game)
{
    game->menu.menu_st.t_pause = loadtext("PAUSE", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 620}, 50);
    game->menu.menu_st.t_changespell = loadtext("CHANGESPELL", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 680}, 50);
    game->menu.menu_st.t_interact = loadtext("INTERACT", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 750}, 50);
    game->menu.menu_st.t_changestance = loadtext("CHANGESTANCE", (sfVector2f)
    {1, 1}, (sfVector2f) {600, 820}, 50);
    game->menu.menu_st.t_key = loadtext_white("Chose any keys", (sfVector2f)
    {1, 1}, (sfVector2f) {800, 550}, 40);
    game->menu.menu_pl.chose_name = loadtext("Chose your name", (sfVector2f)
    {1, 1}, (sfVector2f) {800, 450}, 40);
}

void all_set_buttom_reforge(game_t *game)
{
    game->menu.buttom_exit_white =
    loadbutton("assets/menu/buttom/exit_white2.png",
    (sfVector2f) {0.4, 0.4}, (sfVector2f) {168, 950});
    game->menu.buttom_exit_black =
    loadbutton("assets/menu/buttom/exit_black2.png",
    (sfVector2f) {0.4, 0.4}, (sfVector2f) {168, 950});
    game->menu.menu_pl.play_white =
    loadbutton("assets/menu/buttom/play_white2.png",
    (sfVector2f) {0.51, 0.51}, (sfVector2f) {850, 800});
    game->menu.menu_pl.play =
    loadbutton("assets/menu/buttom/play_black2.png",
    (sfVector2f) {0.62, 0.62}, (sfVector2f) {850, 800});
    game->menu.buttom_play_white =
    loadbutton("assets/menu/buttom/play_white2.png",
    (sfVector2f) {0.51, 0.51}, (sfVector2f) {168, 700});
    game->menu.buttom_setting_white =
    loadbutton("assets/menu/buttom/setting_white.png",
    (sfVector2f) {0.4, 0.4}, (sfVector2f) {90, 820});
}

void all_set_buttom_ref(game_t *game)
{
    game->menu.menu_pl.rec =
    loadbutton("assets/menu/play/recan.png",
    (sfVector2f) {1.5, 1.2}, (sfVector2f) {750, 600});
    game->menu.menu_st.arrow_white =
    loadbutton("assets/menu/setting/fleche_white.png",
    (sfVector2f) {0.3, 0.3}, (sfVector2f) {580, 50});
    game->menu.menu_pl.l_arrow =
    loadbutton("assets/menu/setting/l_fleche.png",
    (sfVector2f) {0.3, 0.3}, (sfVector2f) {740, 280});
    game->menu.menu_pl.r_arrow =
    loadbutton("assets/menu/setting/r_fleche.png",
    (sfVector2f) {0.3, 0.3}, (sfVector2f) {1065, 280});
    game->menu.menu_pl.l_arrow_white =
    loadbutton("assets/menu/setting/l_fleche_white.png",
    (sfVector2f) {0.3, 0.3}, (sfVector2f) {740, 280});
    game->menu.menu_pl.r_arrow_white =
    loadbutton("assets/menu/setting/r_fleche_white.png",
    (sfVector2f) {0.3, 0.3}, (sfVector2f) {1065, 280});
}

void all_set_key_text_norm(game_t *game)
{
    game->menu.key_st.k_interact = loadtext(game->menu.key_st.c_interact,
    (sfVector2f) {1, 1}, (sfVector2f) {1150, 750}, 50);
    game->menu.key_st.k_changestance = loadtext(game->menu.key_st.
    c_changestance, (sfVector2f) {1, 1}, (sfVector2f) {1150, 820}, 50);
}

void all_set_key_text_norm_white(game_t *game)
{
    game->menu.key_set_w.k_interact_w = loadtext_white(game->menu.key_st.
    c_interact, (sfVector2f) {1, 1}, (sfVector2f) {1150, 750}, 50);
    game->menu.key_set_w.k_changestance_w = loadtext_white(game->menu.key_st.
    c_changestance, (sfVector2f) {1, 1}, (sfVector2f) {1150, 820}, 50);
}