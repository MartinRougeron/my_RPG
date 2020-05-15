/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_item.c
*/

#include "my.h"

item_t create_item(char **name, armorstyle_t style, itemtype_t type,
itemstat_t stat)
{
    item_t this;

    this.cd = sfClock_create();
    this.action = initaction(type);
    this.name = name[0];
    this.sprite = loadbutton(name[2], (sfVector2f){1, 1}, (sfVector2f){0, 0});
    this.type = type;
    this.stat = stat;
    this.descrption = name[1];
    this.path = my_strdup(name[2]);
    this.style = style;
    return this;
}