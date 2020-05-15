/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** util
*/

#include "my.h"

void dropitemaction(game_t *game, int index)
{
    sfSprite_destroy(getitem[index].sprite);
    getitem[index].sprite = NULL;
}

item_t equipcopy(item_t item)
{
    item_t cpy;

    cpy.action = initaction(EQUIPED);
    cpy.cd = sfClock_create();
    cpy.cost = item.cost;
    cpy.stat = item.stat;
    cpy.descrption = item.descrption;
    cpy.name = item.name;
    cpy.sprite = sfSprite_copy(item.sprite);
    cpy.type = item.type;
    cpy.style = item.style;
    cpy.path = my_strdup(item.path);
    return cpy;
}

item_t uneqipcopy(item_t item)
{
    item_t cpy;

    cpy.action = initaction(item.type);
    cpy.cd = sfClock_create();
    cpy.cost = item.cost;
    cpy.stat = item.stat;
    cpy.descrption = item.descrption;
    cpy.name = item.name;
    cpy.sprite = sfSprite_copy(item.sprite);
    cpy.type = item.type;
    cpy.style = item.style;
    cpy.path = my_strdup(item.path);
    return cpy;
}

void equipitemaction(game_t *game, int index)
{
    if (getitem[INVENTORY_SIZE + getitem[index].type].sprite != NULL)
        return;
    getitem[INVENTORY_SIZE + getitem[index].type] = equipcopy(getitem[index]);
    sfSprite_destroy(getitem[index].sprite);
    getitem[index].sprite = NULL;
}

void unequipitemaction(game_t *game, int index)
{
    for (int i = 0; i != INVENTORY_SIZE; i++)
        if (getitem[i].sprite == NULL) {
            getitem[i] = uneqipcopy(getitem[index]);
            sfSprite_destroy(getitem[index].sprite);
            getitem[index].sprite = NULL;
            break;
        }
}