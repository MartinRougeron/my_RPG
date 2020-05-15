/*
** EPITECH PROJECT, 2020
** center
** File description:
** center
*/

#include "my.h"

void sfSprite_centerorigine(sfSprite *sprite)
{
    sfSprite_setOrigin(sprite, (sfVector2f)
    {sfSprite_getLocalBounds(sprite).width / 2,
    sfSprite_getLocalBounds(sprite).height / 2});
}

void sfText_centerorigine(sfText *sprite)
{
    sfText_setOrigin(sprite, (sfVector2f)
    {sfText_getLocalBounds(sprite).width / 2,
    sfText_getLocalBounds(sprite).height / 2});
}

void sfRectangleShape_centerorigine(sfRectangleShape *sprite)
{
    sfRectangleShape_setOrigin(sprite, (sfVector2f)
    {sfRectangleShape_getLocalBounds(sprite).width / 2,
    sfRectangleShape_getLocalBounds(sprite).height / 2});
}

void sfCircleShape_centerorigine(sfCircleShape *sprite)
{
    sfCircleShape_setOrigin(sprite, (sfVector2f)
    {sfCircleShape_getLocalBounds(sprite).width / 2,
    sfCircleShape_getLocalBounds(sprite).height / 2});
}