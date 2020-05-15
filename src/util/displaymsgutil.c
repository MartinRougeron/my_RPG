/*
** EPITECH PROJECT, 2020
** util
** File description:
** dips
*/

#include "my.h"

void processendmsg(game_t *game, int *end, char *str, int *i)
{
    waitimput(game);
    *end = 0;
    *i = 0;
    free(str);
}

void waitimput(game_t *game)
{
    sfEvent event;
    sfClock *cool_down = sfClock_create();

    while (sfRenderWindow_waitEvent(game->window, &event)) {
        for (int i = 0; i != NBMAXENEMIE; i++)
            if (game->enemie[i].sprite != NULL)
                sfClock_restart(game->enemie[i].clockmove);
        sfClock_restart(game->player.moveclock);
        if ((event.type == sfEvtKeyPressed ||
        event.type == sfEvtMouseButtonPressed) && TIME(cool_down) > 600)
            break;
    }
    imput(game, event);
    game->player.stat.health = game->playerpvstart;
    sfClock_destroy(cool_down);
}