/*
** EPITECH PROJECT, 2020
** util
** File description:
** restart
*/

#include "my.h"

void restarclock(game_t *game)
{
    for (int i = 0; i != NBMAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        sfClock_restart(game->enemie[i].clockmove);
    }
    for (int i = 0; i != 30; i++) {
        if (game->player.mage.spell[i].sprite == NULL)
            continue;
        sfClock_restart(game->player.mage.spell[i].moveclock);
    }
    sfClock_restart(game->player.moveclock);
}