/*
** EPITECH PROJECT, 2020
** player
** File description:
** util
*/

#include "my.h"

void playertakedamage(game_t *game, int damage)
{
    if (game->player.shield)
        return;
    game->player.stat.health -= damage *
    (1 - (game->player.stat.armor * 1.0 / 100.0));
    addtxtdmg(game, damage *
    (1 - (game->player.stat.armor * 1.0 / 100.0))
    , sfSprite_getPosition(game->player.sprite));
    sfClock_restart(game->player.combat);
}