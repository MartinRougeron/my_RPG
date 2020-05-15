/*
** EPITECH PROJECT, 2020
** player
** File description:
** change hair color
*/

#include "my.h"

void changehaircolor(color_t color, sfSprite *player)
{
    char *path[6] = {
        "./assets/player/spritesheet_blue.png",
        "./assets/player/spritesheet_gray.png",
        "./assets/player/spritesheet_yellow.png",
        "./assets/player/spritesheet_green.png",
        "./assets/player/spritesheet_purple.png",
        "./assets/player/spritesheet_red.png",
        };
    sfTexture *texture = sfTexture_createFromFile(path[color], NULL);
    sfSprite_setTexture(player, texture, sfFalse);
}
