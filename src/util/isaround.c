/*
** EPITECH PROJECT, 2020
** util
** File description:
** is around
*/

#include "my.h"

int isaround(sfSprite *sprite1, sfSprite *sprite2, int pixel)
{
    sfVector2f pos1 = sfSprite_getPosition(sprite1);
    sfVector2f pos2 = sfSprite_getPosition(sprite2);

    if (pos1.x >= pos2.x + pixel || pos1.x <= pos2.x - pixel)
        return 1;
    if (pos1.y >= pos2.y + pixel || pos1.y <= pos2.y - pixel)
        return 1;
    return 0;
}

int isaround_vector(sfFloatRect rect1, sfVector2f pos2, int pixel)
{
    sfFloatRect rect2 = (sfFloatRect) {pos2.x, pos2.y, pixel, pixel};

    if (sfFloatRect_intersects(&rect1, &rect2, NULL))
        return 1;
    return 0;
}