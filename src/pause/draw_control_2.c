/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_control_2.c
*/

#include "my.h"

void norm_c_k_changestance_r(game_t *game)
{
    game->menu.key_st.c_changestance =
    all_call_char_key(game->menu.key_st.c_changestance, game);
    game->key.changestance = game->menu.num_key;
    sfText_setString(game->control.cont.k_changestance,
    game->menu.key_st.c_changestance);
    sfText_setString(game->control.cont_w.k_changestance_w,
    game->menu.key_st.c_changestance);
}

void norm_c_k_changestance(game_t *game)
{
    if (game->menu.status_key == 11) {
        if (test_reforge_control(game)) {
            if (game->key.changestance == game->menu.num_key) {
                game->menu.status_keys = 1;
                game->screen = 8;
            }
            if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->screen = 9;
                game->menu.status_key = 11;
            } else if (game->menu.status_keys != 1) {
                norm_c_k_changestance_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}

void control_k_changestance(game_t *game)
{
    sfRenderWindow_drawText(game->window,
    game->control.cont.k_changestance, NULL);
    if (hittext(game->control.cont.k_changestance, (sfWindow*)game->window)) {
        sfRenderWindow_drawText(game->window,
        game->control.cont_w.k_changestance_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->screen = 9;
            game->menu.status_key = 11;
        }
    }
    norm_c_k_changestance(game);
}