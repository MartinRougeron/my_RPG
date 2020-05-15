/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** norm
*/

#include "my.h"

void norm_buttom_play(game_t *game)
{
    game->screen = GAME;
    TRIVIATANT = loadtriviatan();
    game->dragon = create_dragon();
    game->is_tuto = 1;
    sfSprite_setPosition(game->player.sprite, (sfVector2f) {930, 401});
}

void draw_all_text_r(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -780)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_left, NULL);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -720)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_right, NULL);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -660)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_inventory, NULL);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -600)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_attack, NULL);
}

void draw_all_text_reforge(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -540)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_parade, NULL);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -480)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_pause, NULL);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -420)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_changespell, NULL);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -360)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_interact, NULL);
}

void norm_k_changestance_r(game_t *game)
{
    game->menu.key_st.c_changestance =
    all_call_char_key(game->menu.key_st.c_changestance, game);
    game->key.changestance = game->menu.num_key;
    sfText_setString(game->menu.key_st.k_changestance,
    game->menu.key_st.c_changestance);
    sfText_setString(game->menu.key_set_w.k_changestance_w,
    game->menu.key_st.c_changestance);
}

void norm_k_changestance(game_t *game)
{
    if (game->menu.status_key == 11) {
        if (test(game)) {
            if (game->key.changestance == game->menu.num_key) {
            game->menu.status_keys = 1;
            game->menu.status_game = 0;
            }
        if (check_all_key(game) == 1 && game->menu.status_keys != 1) {
                game->menu.status_game = 1;
                game->menu.status_key = 7;
            } else if (game->menu.status_keys != 1) {
                norm_k_changestance_r(game);
            }
            game->menu.status_keys = 0;
        }
    }
}