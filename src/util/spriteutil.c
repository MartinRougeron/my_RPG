/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** util
*/

#include "my.h"

void sfSprite_setTransparent(sfSprite *sprite, int alpha)
{
    sfSprite_setColor(sprite, (sfColor) {255, 255, 255, alpha});
}

void sfRectangleShape_setTransparent(sfRectangleShape
*sprite, sfColor color, int alpha)
{
    sfRectangleShape_setFillColor
    (sprite, (sfColor) {color.r, color.g, color.b, alpha});
}