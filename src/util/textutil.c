/*
** EPITECH PROJECT, 2020
** util
** File description:
** text
*/

#include "my.h"

void sfText_setTransparent(sfText *sprite, int alpha, sfColor color)
{
    sfText_setColor(sprite, (sfColor) {color.r, color.g, color.b, alpha});
}

sfText *createsimpletext(char *text_t, sfVector2f position, int i)
{
    sfText *text;
    static sfFont *text_font = NULL;

    text = sfText_create();
    if (text_font == NULL)
        text_font = sfFont_createFromFile("assets/menu.ttf");
    sfText_setFont(text, text_font);
    sfText_setString(text, text_t);
    sfText_setPosition(text, position);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, i);
    return text;
}