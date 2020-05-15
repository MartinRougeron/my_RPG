/*
** EPITECH PROJECT, 2020
** save
** File description:
** save
*/

#include "my.h"

char *getplayerpostion(game_t *game)
{
    char *str = my_malloc(50);

    str = my_strcat(str, my_itoa(game->player.position.map));
    str = my_strcat(str, "|");
    str = my_strcat(str, my_itoa(game->player.position.y));
    str = my_strcat(str, "|");
    str = my_strcat(str, my_itoa(game->player.position.x));
    str = my_strcat(str, "|");
    str = my_strcat(str,
    my_itoa((int) sfSprite_getPosition(game->player.sprite).x));
    str = my_strcat(str, "|");
    str = my_strcat(str,
    my_itoa((int) sfSprite_getPosition(game->player.sprite).y));
    str = my_strcat(str, ",");
    return str;
}

char *getplayerstat(game_t *game)
{
    char *str = my_malloc(20);

    str = my_strcat(str, my_itoa(game->player.stat.maxhealth));
    str = my_strcat(str, "|");
    str = my_strcat(str, my_itoa(game->player.stat.maxstamina));
    str = my_strcat(str, "|");
    str = my_strcat(str, my_itoa(game->player.stat.maxmana));
    str = my_strcat(str, ",");
    return str;
}

char *gettreeunlocked(game_t *game)
{
    char *str = my_malloc(35);

    for (int i = 0; i != NBSKILL; i++) {
        if (game->player.tree.unlocked[i] == -1)
            str = my_strcat(str, "-1");
        else
            str = my_strcat(str, my_itoa(game->player.tree.unlocked[i]));
        str = my_strcat(str, "|");
    }
    str = my_strcat(str, ",");
    return str;
}

void createstring(game_t *game, int fd)
{
    char *str = my_malloc(5000);

    str = my_strcat(str, game->player.name);
    str = my_strcat(str, ",");
    str = my_strcat(str, my_itoa(game->player.inventory.gold));
    str = my_strcat(str, ",");
    str = my_strcat(str, getplayerpostion(game));
    str = my_strcat(str, getplayerstat(game));
    str = my_strcat(str, my_itoa(game->player.learnmagic));
    str = my_strcat(str, ",");
    str = my_strcat(str, my_itoa(game->player.xp));
    str = my_strcat(str, ",");
    str = my_strcat(str, my_itoa(game->player.level));
    str = my_strcat(str, ",");
    str = my_strcat(str, my_itoa(game->player.color));
    str = my_strcat(str, ",");
    str = my_strcat(str, my_itoa(game->player.mage.unlocked));
    str = my_strcat(str, ",");
    SAVE_CAT
    write(fd, str, my_strlen(str));
}

void savegame(game_t *game)
{
    int fd;
    FILE *clear = fopen(".load/save.load", "w");

    fclose(clear);
    fd = open(".load/save.load", O_WRONLY);
    if (!fd)
        write(1, "error saving game :c\n\
        Try create a save.load files in the .load folder", 69);
    createstring(game, fd);
    close(fd);
}