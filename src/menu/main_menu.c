/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#include "my.h"

int test(game_t *game)
{
    sfEvent event;
    int i = 0;

    while (sfRenderWindow_pollEvent(game->window, &event))
        if (event.type == sfEvtKeyPressed) {
            game->menu.num_key = event.key.code;
            game->menu.status_game = 0;
            game->menu.status_key = 0;
            i++;
        }
    return i;
}

int test_reforge(game_t *game)
{
    sfEvent event;
    int i = 0;

    while (sfRenderWindow_pollEvent(game->window, &event))
        if (event.type == sfEvtKeyPressed) {
            game->menu.num_key = event.key.code;
            game->menu.status_key = 0;
            i++;
        }
    return i;
}

void call(game_t *game)
{
    game->menu.parch_1_status = 0;
    game->menu.parch_2_status = 0;
    game->menu.parch_4_status = 0;
    game->menu.parch_3_status = 0;
    game->menu.num_key = 100;
    game->menu.status_game = 0;
    game->player.color = 0;
    game->menu.menu_pl.name = 0;
    game->player.name = my_malloc(11);
}

void all_call_set(game_t *game)
{
    call(game);
    all_set_buttom(game);
    all_set_name(game);
    rec_for_color(game);
    all_set_text(game);
    all_set_text_reforge(game);
    all_set_buttom_reforge(game);
    game->menu.buttom_setting_black =
    loadbutton("assets/menu/buttom/setting_black.png",
    (sfVector2f) {0.4, 0.4}, (sfVector2f) {90, 820});
    all_set_buttom_ref(game);
    set_all_key_base(game);
    all_set_key_text(game);
    all_set_key_text_norm(game);
    all_set_key_text_white(game);
    all_set_key_text_norm_white(game);
    game->menu.parch_clock = sfClock_create();
}

void main_menu(game_t *game)
{
    sfEvent event;

    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfWindow_close((sfWindow *) game->window);
        return;
    }
    if (game->menu.status_game == 1)
        all_call_ckey(game);
    else if (game->menu.status_game == 2)
        call_status(game);
    else
        call_status_else(game);
    while (sfRenderWindow_pollEvent(game->window, &event));
    sfRenderWindow_display(game->window);
}