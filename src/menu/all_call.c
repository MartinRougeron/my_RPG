/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** all_call
*/

#include "my.h"

void all_call_ckey(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.fond, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.parchemin, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.parchment, NULL);
    DRAW_SHAPE(game->window,
    game->menu.menu_st.rectang, NULL);
    draw_all_text(game);
    all_call_key(game);
    sfRenderWindow_drawText(game->window, game->menu.menu_st.t_key, NULL);
    sfClock_restart(game->menu.parch_clock);
}

void all_call_else(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.fond, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.parchemin, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.parchment, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->menu.menu_pl.parchments, NULL);
    sfRenderWindow_drawSprite(game->window, LOAD_MENU.parche, NULL);
    if (sfSprite_getPosition(game->menu.menu_pl.parchments).y < -1350 &&
    sfSprite_getPosition(game->menu.parchemin).x < -500)
        game->menu.parch_3_status = 0;
}

void all_parch(game_t *game)
{
    if (game->menu.parch_1_status == 1 || game->menu.parch_1_status == 0) {
        parchemin_action_on(game), parchemin_action_onn(game);
        parchemin_action_onnn(game), parchemin_action_onnnn(game);
        bottom_play_action(game), bottom_exit_action(game);
        bottom_setting_action(game), bottom_load_action(game);
    }
    if (game->menu.parch_1_status == 2) {
        parchemin_action_off(game);
        bottom_play_action(game);
        bottom_exit_action(game);
        bottom_setting_action(game);
        bottom_load_action(game);
    }
    if (game->menu.parch_2_status == 1) {
        parchment_action_on(game);
        draw_all_play(game);
        draw_all_text(game);
        all_call_key(game);
        bottom_arrow_action(game);
    }
}

void all_parch_reforged(game_t *game)
{
    if (game->menu.parch_2_status == 2)
        parchment_action_off(game);
    if (game->menu.parch_3_status == 1) {
        parchments_action_on(game);
        buttom_l_arrow_action_play(game);
        buttom_r_arrow_action_play(game);
        draw_all_play(game);
    }
    if (game->menu.parch_3_status == 2)
        parchments_action_off(game);
    if (game->menu.parch_4_status == 1) {
        parchment_load_on(game);
        bottom_ar_action(game);
        bottom_game_action(game);
        bottom_triva_action(game);
        bottom_dragon_action(game);
    }
    if (game->menu.parch_4_status == 2)
        parchment_load_off(game);
}