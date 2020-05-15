/*
** EPITECH PROJECT, 2020
** stat
** File description:
** stat
*/

#include "my.h"

void getarmorstat(game_t *game)
{
    game->player.stat.armor = 0;
    for (int i = INVENTORY_SIZE; i != INVENTORY_SIZE + NBSLOT; i++) {
        if (getitem[i].sprite == NULL)
            continue;
        game->player.stat.armor += getitem[i].stat.armor;
    }
}

int getarmorhealth(game_t *game)
{
    int newhealth = 0;

    for (int i = INVENTORY_SIZE; i != INVENTORY_SIZE + NBSLOT; i++) {
        if (getitem[i].sprite == NULL)
            continue;
        newhealth += getitem[i].stat.health;
    }
    return newhealth;
}

int getequipmentdamage(game_t *game)
{
    int res = 0;

    for (int i = 0; i != NBSLOT; i++) {
        if (getitem[i + INVENTORY_SIZE].sprite == NULL)
            continue;
        res += getitem[i + INVENTORY_SIZE].stat.damage;
    }
    return res;
}

void getitemstat(game_t *game)
{
    getarmorstat(game);
    game->player.stat.maxhealth += getarmorhealth(game);
    game->player.stat.maxmana += getarmormana(game);
    game->player.stat.maxstamina += getarmorstamina(game);
}

void removeitemstat(game_t *game)
{
    game->player.stat.maxhealth -= getarmorhealth(game);
    game->player.stat.maxmana -= getarmormana(game);
    game->player.stat.maxstamina -= getarmorstamina(game);
}