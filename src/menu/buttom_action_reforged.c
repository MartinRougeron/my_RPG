/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttom_action_reforged
*/

#include "my.h"

void call_for_norm(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->menu.menu_pl.r_arrow, NULL);
    if (hitsprite(game->menu.menu_pl.r_arrow,
    (sfWindow*)game->window) && game->menu.parch_3_status == 1)
        sfRenderWindow_drawSprite(game->window,
        game->menu.menu_pl.r_arrow_white, NULL);
}

void call_for_norm_r(game_t *game)
{
    if (hitsprite(game->menu.menu_pl.l_arrow,
        (sfWindow*)game->window) && game->menu.parch_3_status == 1) {
            sfRenderWindow_drawSprite(game->window,
            game->menu.menu_pl.l_arrow_white, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
            game->player.color >= 0) {
                if (game->player.color == 0)
                    game->player.color = 5;
                else
                    game->player.color -= 1;
            }
        }
}

void buttom_r_arrow_action_play(game_t *game)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
    clock = sfClock_create();
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -750) {
        call_for_norm(game);
    }
    if (TIME(clock) < 100)
        return;
    sfClock_restart(clock);
    if (hitsprite(game->menu.menu_pl.r_arrow,
    (sfWindow*)game->window) && game->menu.parch_3_status == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        game->player.color <= 5) {
            game->player.color++;
            if (game->player.color == 6)
                game->player.color = 0;
        }
    }
}

void buttom_l_arrow_action_play(game_t *game)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -750) {
        sfRenderWindow_drawSprite(game->window, game->menu.menu_pl.l_arrow,
        NULL);
        if (hitsprite(game->menu.menu_pl.l_arrow, (sfWindow*)game->window) &&
        game->menu.parch_3_status == 1)
            sfRenderWindow_drawSprite(game->window,
            game->menu.menu_pl.l_arrow_white, NULL);
    }
    if (TIME(clock) < 100)
        return;
    sfClock_restart(clock);
    call_for_norm_r(game);
}

void bottom_play_game(game_t *game)
{
    char *stock;

    if (game->menu.parch_3_status == 1 &&
    sfSprite_getPosition(game->menu.menu_pl.parchments).y > -250)
    sfRenderWindow_drawSprite(game->window, game->menu.menu_pl.play, NULL);
    if (hitsprite(game->menu.menu_pl.play, (sfWindow*)game->window) &&
    game->menu.parch_3_status == 1) {
        sfRenderWindow_drawSprite(game->window,
        game->menu.menu_pl.play_white, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            if (game->player.name[0] == 0)
                game->player.name = "Jean Eudes";
            stock = game->player.name;
            loadplayer(game);
            game->player.name = stock;
            norm_buttom_play(game);
        }
    }
}