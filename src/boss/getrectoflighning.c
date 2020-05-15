/*
** EPITECH PROJECT, 2020
** get rect
** File description:
** anim
*/

#include "my.h"

sfIntRect getrectlightning(sfIntRect rect)
{
    rect.left += 700;
    if (rect.left == 1400) {
        rect.left = 0;
        rect.top += 700;
    }
    if (rect.top == 1400)
        rect.top = 0;
    return rect;
}