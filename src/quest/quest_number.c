/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_number.c
*/

#include "my.h"

void quest_nbr(game_t *game, sfSprite **sprite, int nbquest, sfClock *clock)
{
    if (game->questselect != 0) {
        sfRenderWindow_drawSprite(game->window, sprite[0], NULL);
        if (sfKeyboard_isKeyPressed(sfKeyLeft) && TIME(clock) > 200) {
            game->questselect--;
            sfClock_restart(clock);
        }
    }
    if (game->questselect != nbquest - 1) {
        sfRenderWindow_drawSprite(game->window, sprite[1], NULL);
        if (sfKeyboard_isKeyPressed(sfKeyRight) && TIME(clock) > 200) {
            game->questselect++;
            sfClock_restart(clock);
        }
    }
}