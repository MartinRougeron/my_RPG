/*
** EPITECH PROJECT, 2020
** got item
** File description:
** got item
*/

#include "my.h"

int gotitem(game_t *game, char *item)
{
    for (int i = 0; i != INVENTORY_SIZE + NBSLOT; i++) {
        if (game->player.inventory.item[i].sprite == NULL)
            continue;
        if (!my_strncmp(game->player.inventory.item[i].name, item,
        my_strlen(item)))
            return i;
    }
    return -1;
}