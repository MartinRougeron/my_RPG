/*
** EPITECH PROJECT, 2020
** add item
** File description:
** add item
*/

#include "my.h"

int additem(game_t *game, item_t item)
{
    for (int i = 0; i != INVENTORY_SIZE; i++) {
        if (getitem[i].sprite == NULL) {
            getitem[i] = item;
            return 1;
        }
    }
    return 0;
}