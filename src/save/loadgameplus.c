/*
** EPITECH PROJECT, 2020
** load
** File description:
** game
*/

#include "my.h"

char *getitemstamplus(char *str, item_t *item)
{
    int i;

    for (i = 0; str[i] != '-'; i++);
    item->stat.health = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != '-'; i++);
    item->stat.mana = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ':'; i++);
    item->stat.stamina = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    return str;
}

char *getitemstat1(char *str, item_t *item)
{
    int i;

    for (i = 0; str[i] != ':'; i++);
    item->type = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    if (item->type == CHESTPLATE) {
        for (i = 0; str[i] != ':'; i++);
        item->style = my_getnbr(my_strncpy(str, i));
        str += i + 1;
    }
    for (i = 0; str[i] != '-'; i++);
    item->stat.armor = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != '-'; i++);
    item->stat.damage = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    item->action = initaction(item->type);
    return getitemstamplus(str, item);
}

void computecreateitem(game_t *game, char *str)
{
    item_t ite;
    int id, i;

    for (i = 0; str[i] != ':'; i++);
    id = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ':'; i++);
    ite.path = my_strncpy(str, i);
    str += i + 1;
    ite.sprite = loadbutton(ite.path, (sfVector2f){1, 1}, (sfVector2f){0, 0});
    ite.path = my_strdup(ite.path);
    str = getitemstat1(str, &ite);
    for (i = 0; str[i] != ':'; i++);
    ite.name = my_strncpy(str, i);
    str += i + 1;
    for (i = 0; str[i] != ':'; i++);
    ite.descrption = my_strncpy(str, i);
    str += i + 1;
    NAME_FT
    getitem[id] = ite;
}

void loaditem(game_t *game, char *str)
{
    int i = 0;

    for (i = 0; str[i] != 0; i++) {
        if (str[i] == '|' && str[i + 1] != 0) {
            computecreateitem(game, my_strncpy(str, i));
            str += i + 1;
            i = 0;
        }
    }
}

char *loadtree(game_t *game, char *str)
{
    int i;

    for (int y = 0; y != NBSKILL; y++) {
        for (i = 0; str[i] != '|'; i++);
        game->player.tree.unlocked[y] = my_getnbr(my_strncpy(str, i));
        str += i + 1;
    }
    str++;
    return str;
}