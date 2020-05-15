/*
** EPITECH PROJECT, 2020
** gold
** File description:
** util
*/

#include "my.h"

void givegold(game_t *game, int gold)
{
    game->player.inventory.gold += gold;
    game->player.drop.gold += gold;
}

void givexp(game_t *game, int xp)
{
    game->player.xp += xp;
    game->player.drop.xp += xp;
    makelevelup(game);
}

void dropitem(game_t *game, drop_t drop)
{
    givegold(game, drop.gold);
    givexp(game, drop.xp);
}