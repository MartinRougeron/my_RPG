/*
** EPITECH PROJECT, 2020
** save
** File description:
** inv
*/

#include "my.h"

char *saveitemstat(game_t *game, int i)
{
    char *str = my_malloc(50);

    str = my_strcat(str, my_itoa(getitem[i].stat.armor));
    str = my_strcat(str, "-");
    str = my_strcat(str, my_itoa(getitem[i].stat.damage));
    str = my_strcat(str, "-");
    str = my_strcat(str, my_itoa(getitem[i].stat.health));
    str = my_strcat(str, "-");
    str = my_strcat(str, my_itoa(getitem[i].stat.mana));
    str = my_strcat(str, "-");
    str = my_strcat(str, my_itoa(getitem[i].stat.stamina));
    str = my_strcat(str, ":");
    return str;
}

char *savequest(game_t *game)
{
    char *str = my_malloc(100);

    for (int i = 0; i != NBQUEST + NBSECONDARY; i++) {
        str = my_strcat(str, my_itoa(game->all_quest[i]));
        str = my_strcat(str, ",");
    }
    return str;
}

char *cat_inventory(int i, game_t *game, char *str)
{
    str = my_strcat(str, my_itoa(i));
    str = my_strcat(str, ":");
    str = my_strcat(str, getitem[i].path);
    str = my_strcat(str, ":");
    str = my_strcat(str, my_itoa(getitem[i].type));
    str = my_strcat(str, ":");
    return (str);
}

char *getinventory(game_t *game)
{
    char *str = my_malloc(1000);

    for (int i = 0; i != INVENTORY_SIZE + NBSLOT; i++) {
        if (getitem[i].sprite == NULL)
            continue;
        str = cat_inventory(i, game, str);
        if (getitem[i].type == CHESTPLATE) {
            str = my_strcat(str, my_itoa(getitem[i].style));
            str = my_strcat(str, ":");
        }
        str = my_strcat(str, saveitemstat(game, i));
        str = my_strcat(str, getitem[i].name);
        str = my_strcat(str, ":");
        str = my_strcat(str, getitem[i].descrption);
        str = my_strcat(str, ":");
        str = my_strcat(str, "|");
    }
    str = my_strcat(str, "|");
    return str;
}