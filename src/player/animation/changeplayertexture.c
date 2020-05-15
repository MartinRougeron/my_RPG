/*
** EPITECH PROJECT, 2020
** player
** File description:
** change player
*/

#include "my.h"

char *getpath(color_t color, armorstyle_t style)
{
    char *stylep[4] = {"none/", "red/", "blue/", "soldier/"};
    char *colorp[6] = {"spritesheet_blue.png", "spritesheet_gray.png",
    "spritesheet_yellow.png", "spritesheet_green.png",
    "spritesheet_purple.png", "spritesheet_red.png"};
    char *path = my_strcat("assets/player/",
    my_strcat(stylep[style], colorp[color]));

    return path;
}

void changeplayertexture(game_t *game)
{
    static armorstyle_t style = ARMORNONE;
    static color_t color = BLUE;
    armorstyle_t newstyle;
    sfTexture *texture;

    if (getitem[INVENTORY_SIZE + CHESTPLATE].sprite == NULL)
        newstyle = ARMORNONE;
    else
        newstyle = getitem[INVENTORY_SIZE + CHESTPLATE].style;
    if (newstyle != style || color != game->player.color) {
        style = newstyle;
        color = game->player.color;
        texture = sfTexture_createFromFile(getpath(color, style), NULL);
        sfSprite_setTexture(game->player.sprite, texture, sfFalse);
    }
}