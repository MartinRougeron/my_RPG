/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_new_key
*/

#include "my.h"

void draw_all_text(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -900)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_up, NULL);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -840)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_down, NULL);
    draw_all_text_r(game);
    draw_all_text_reforge(game);
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -300)
        sfRenderWindow_drawText(game->window,
        game->menu.menu_st.t_changestance, NULL);
}

void all_call_key(game_t *game)
{
    draw_k_attack(game);
    draw_k_changespell(game);
    draw_k_changestance(game);
    draw_k_down(game);
    draw_k_interact(game);
    draw_k_inventory(game);
    draw_k_left(game);
    draw_k_parade(game);
    draw_k_pause(game);
    draw_k_right(game);
    draw_k_up(game);
}

char *all_call_char_key(char *sprite, game_t *game)
{
    sprite = text_k_key(sprite, game);
    sprite = text_k_keys(sprite, game);
    sprite = text_k_keyss(sprite, game);
    sprite = text_kekeys(sprite, game);
    sprite = text_key(sprite, game);
    sprite = text_key_key(sprite, game);
    sprite = text_keys(sprite, game);
    sprite = text_keys_key(sprite, game);
    sprite = text_keyss(sprite, game);
    sprite = text_ks_keys(sprite, game);
    sprite = text_k_keys_n(sprite, game);
    sprite = text_k_keys_norm(sprite, game);
    return sprite;
}

void draw_k_changestance(game_t *game)
{
    if (game->menu.parch_2_status == 1 &&
    sfSprite_getPosition(game->menu.parchment).y > -300)
        sfRenderWindow_drawText(game->window,
        game->menu.key_st.k_changestance, NULL);
    if (hittext(game->menu.key_st.k_changestance,
    (sfWindow*)game->window) && game->menu.parch_2_status == 1 &&
    game->menu.status_game != 1) {
        sfRenderWindow_drawText(
        game->window, game->menu.key_set_w.k_changestance_w, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        || game->menu.status_key == 11) {
            game->menu.status_game = 1;
            game->menu.status_key = 11;
        }
    }
    norm_k_changestance(game);
}

void set_all_key_base(game_t *game)
{
    game->menu.key_st.c_up = "Up";
    game->menu.key_st.c_down = "Down";
    game->menu.key_st.c_left = "Left";
    game->menu.key_st.c_right = "Right";
    game->menu.key_st.c_inventory = "Tab";
    game->menu.key_st.c_attack = "T";
    game->menu.key_st.c_parade = "Mright";
    game->menu.key_st.c_pause = "Escape";
    game->menu.key_st.c_changespell = "R";
    game->menu.key_st.c_interact = "E";
    game->menu.key_st.c_changestance = "C";
}