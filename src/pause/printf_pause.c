/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** printf_pause
*/

#include "my.h"

int movepause(int select)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (TIME(clock) < 200)
        return select;
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        select += (select == 2) ? -2 : 1;
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        select -= (select == 0) ? -2 : 1;
        sfClock_restart(clock);
    }
    return select;
}

void print_pause(game_t *game)
{
    static int select = 0;

    select = movepause(select);
    sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause.pause_sprite, NULL);
    sfRenderWindow_drawText(game->window,
    game->pause.pause_text, NULL);
    select = bottom_resume(game, select);
    select = bottom_exit(game, select);
    select = bottom_setting(game, select);
}

void print_setting(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause.pause_sprite, NULL);
    bottom_cursor_on(game);
    bottom_control(game);
    bottom_volume(game);
}

void print_control(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause.pause_sprite, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_up, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_down, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_left, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_right, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_inventory, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_attack, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_parade, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_pause, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_changespell, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_interact, NULL);
    sfRenderWindow_drawText(game->window, game->control.t_changestance, NULL);
    control_k_up(game), control_k_down(game), control_k_left(game);
    control_k_right(game), control_k_inventory(game);
    control_k_attack(game), control_k_parade(game), control_k_pause(game);
    control_k_changespell(game), control_k_interact(game);
    control_k_changestance(game);
}
