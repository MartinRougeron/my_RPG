/*
** EPITECH PROJECT, 2020
** hitsprite
** File description:
** hitsprite
*/

#include "my.h"

int hitsprite(sfSprite *sprite, sfWindow *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&rect, sfMouse_getPosition((sfWindow*)window).x,
    sfMouse_getPosition((sfWindow*)window).y))
        return 1;
    return 0;
}

int hittext(sfText *text, sfWindow *window)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);

    if (sfFloatRect_contains(&rect, sfMouse_getPosition((sfWindow*)window).x,
    sfMouse_getPosition((sfWindow*)window).y))
        return 1;
    return 0;
}

int hitrect(sfIntRect rect, sfRenderWindow *window)
{
    if (sfIntRect_contains(&rect, sfMouse_getPosition((sfWindow*)window).x,
    sfMouse_getPosition((sfWindow*)window).y))
        return 1;
    return 0;
}