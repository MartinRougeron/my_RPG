/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** util
*/

#include "my.h"

void loadinventory(player_t *game)
{
    item_t *item = malloc(sizeof(item_t) * (INVENTORY_SIZE + NBSLOT));

    for (int i = 0; i != INVENTORY_SIZE + NBSLOT; i++)
        item[i].sprite = NULL;
    game->inventory.gold = 0;
    game->inventory.item = item;
    game->inventory.lastclick = -1;
    game->inventory.clockaction = sfClock_create();
}

sfRectangleShape *loadui(void)
{
    sfRectangleShape *uichoice;

    uichoice = sfRectangleShape_create();
    sfRectangleShape_setFillColor(uichoice, (sfColor) {0, 0, 0, 128});
    sfRectangleShape_setOutlineThickness(uichoice, 4);
    sfRectangleShape_setOutlineColor(uichoice, (sfColor) {0, 0, 0, 255});
    return uichoice;
}

item_t copyexactitem(item_t item)
{
    item_t cpy;

    cpy.action = initaction(item.type);
    cpy.cd = sfClock_create();
    cpy.cost = item.cost;
    cpy.descrption = my_strdup(item.descrption);
    cpy.name = my_strdup(item.name);
    cpy.sprite = sfSprite_copy(item.sprite);
    cpy.stat = item.stat;
    cpy.style = item.style;
    cpy.type = item.type;
    cpy.path = my_strdup(item.path);
    return cpy;
}

sfText **loadaction(void)
{
    sfText **text = malloc(sizeof(sfText *) * MAXACTION);

    for (int i = 0; i != MAXACTION; i++) {
        text[i] = loadtxtname("", (sfVector2f) {0, 0}, 15);
        sfText_setColor(text[i], (sfColor) {255, 255, 255, 200});
    }
    return text;
}