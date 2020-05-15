/*
** EPITECH PROJECT, 2020
** getitem
** File description:
** mana
*/

#include "my.h"

int getarmormana(game_t *game)
{
    static int health = 0;
    int newhealth = 0;

    for (int i = INVENTORY_SIZE; i != INVENTORY_SIZE + NBSLOT; i++) {
        if (getitem[i].sprite == NULL)
            continue;
        newhealth += getitem[i].stat.mana;
    }
    health += newhealth - health;
    return newhealth;
}

int getarmorstamina(game_t *game)
{
    static int health = 0;
    int newhealth = 0;

    for (int i = INVENTORY_SIZE; i != INVENTORY_SIZE + NBSLOT; i++) {
        if (getitem[i].sprite == NULL)
            continue;
        newhealth += getitem[i].stat.stamina;
    }
    health += newhealth - health;
    return newhealth;
}