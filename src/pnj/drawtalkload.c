/*
** EPITECH PROJECT, 2020
** load
** File description:
** drawtalk
*/

#include "my.h"

sfText *loadtexttalk(void)
{
    sfText *text = sfText_create();

    sfText_setFont(text, sfFont_createFromFile("./assets/menu.ttf"));
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 15);
    sfText_centerorigine(text);
    return text;
}

sfRectangleShape *loadguitalk(void)
{
    sfRectangleShape *gui = sfRectangleShape_create();

    sfRectangleShape_setTexture(gui,
    sfTexture_createFromFile("assets/gui/panel_Example1.png", NULL),
    sfTrue);
    sfRectangleShape_centerorigine(gui);
    return gui;
}