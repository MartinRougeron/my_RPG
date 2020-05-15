/*
** EPITECH PROJECT, 2019
** graphic
** File description:
** load_sprite.c
*/

#include "my.h"
#include "struct.h"

sfSprite *loadbutton(char *path, sfVector2f scale, sfVector2f position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}