/*
** EPITECH PROJECT, 2020
** action
** File description:
** use
*/

#include "my.h"

void useaction(game_t *game, int index)
{
    game->player.stat.health += getitem[index].stat.health;
    if (game->player.stat.health > game->player.stat.maxhealth)
        game->player.stat.health = game->player.stat.maxhealth;
    game->player.stat.mana += getitem[index].stat.mana;
    if (game->player.stat.mana > game->player.stat.maxmana)
        game->player.stat.mana = game->player.stat.maxmana;
    game->player.stat.stamina += getitem[index].stat.stamina;
    if (game->player.stat.stamina > game->player.stat.maxstamina)
        game->player.stat.stamina = game->player.stat.maxstamina;
    dropitemaction(game, index);
}