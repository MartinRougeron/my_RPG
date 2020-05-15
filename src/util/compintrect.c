/*
** EPITECH PROJECT, 2020
** compare
** File description:
** compare int rect
*/

#include "my.h"

int cmpintrect(sfIntRect rect, sfIntRect rect2)
{
    if (rect.height != rect2.height)
        return 0;
    if (rect.left != rect2.left)
        return 0;
    if (rect.top != rect2.left)
        return 0;
    if (rect.width != rect2.width)
        return 0;
    return 1;
}

int cmpvector2f(sfVector2f pos1, sfVector2f pos2)
{
    if (pos1.x != pos2.x)
        return 0;
    if (pos1.y != pos2.y)
        return 0;
    return 1;
}