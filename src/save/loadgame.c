/*
** EPITECH PROJECT, 2020
** saczv
** File description:
** load
*/

#include "my.h"

char *putposition(game_t *game, char *str)
{
    int i = 0, x, y;

    for (i = 0; str[i] != '|'; i++);
    game->player.position.map = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != '|'; i++);
    game->player.position.y = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != '|'; i++);
    game->player.position.x = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != '|'; i++);
    x = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ','; i++);
    y = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    sfSprite_setPosition(game->player.sprite, (sfVector2f) {x, y});
    return str;
}

char *putstat(game_t *game, char *str)
{
    int i;

    for (i = 0; str[i] != '|'; i++);
    game->player.stat.maxhealth = my_getnbr(my_strncpy(str, i));
    game->player.stat.health = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != '|'; i++);
    game->player.stat.stamina = my_getnbr(my_strncpy(str, i));
    game->player.stat.maxstamina = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ','; i++);
    game->player.stat.maxmana = my_getnbr(my_strncpy(str, i));
    game->player.stat.mana = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    return str;
}

char *loadattributes(game_t *game, char *str)
{
    int i;

    for (i = 0; str[i] != ','; i++);
    game->player.learnmagic = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ','; i++);
    game->player.xp = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ','; i++);
    game->player.level = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ','; i++);
    game->player.color = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    for (i = 0; str[i] != ','; i++);
    game->player.mage.unlocked = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    return str;
}

void putsave(game_t *game, char *str)
{
    int i = 0;

    for (i = 0; str[i] != ','; i++);
    game->player.name = my_strncpy(str, i);
    str += i + 1;
    for (i = 0; str[i] != ','; i++);
    game->player.inventory.gold = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    str = putposition(game, str);
    str = putstat(game, str);
    str = loadattributes(game, str);
    for (i = 0; str[i] != ','; i++);
    game->player.tree.point = my_getnbr(my_strncpy(str, i));
    str += i + 1;
    str = loadtree(game, str);
    str = loadquest(game, str);
    loaditem(game, str);
}

void loadsave(game_t *game, char *path)
{
    FILE *fd = fopen(path, "r");
    char *str = NULL;
    char *res = "";
    size_t size = 0;

    if (!fd)
        write(1, "Can't find .load/save.load\n", 27);
    while (getline(&str, &size, fd) != -1)
        res = my_strcat(res, str);
    if (res[0] == '\n')
        return;
    game->is_tuto = 0;
    game->player.mage.select = 0;
    putsave(game, res);
    fclose(fd);
}