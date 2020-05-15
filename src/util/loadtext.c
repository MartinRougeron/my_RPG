/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loadtext
*/

#include "my.h"

sfText *loadtext(char *text_t, sfVector2f scale, sfVector2f position, int i)
{
    sfText *text;
    sfFont *text_font;

    text = sfText_create();
    text_font = sfFont_createFromFile("assets/menu/setting/VINERITC.TTF");
    sfText_setFont(text, text_font);
    sfText_setString(text, text_t);
    sfText_setScale(text, scale);
    sfText_setPosition(text, position);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, i);
    return text;
}

sfText *loadtext_pause(char *text_t, sfVector2f scale,
sfVector2f position, int i)
{
    sfText *text;
    sfFont *text_font;

    text = sfText_create();
    text_font = sfFont_createFromFile("assets/menu.ttf");
    sfText_setFont(text, text_font);
    sfText_setString(text, text_t);
    sfText_setScale(text, scale);
    sfText_setPosition(text, position);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, i);
    return text;
}

sfText *loadtext_pause_white(char *text_t, sfVector2f scale,
sfVector2f position, int i)
{
    sfText *text;
    sfFont *text_font;

    text = sfText_create();
    text_font = sfFont_createFromFile("assets/menu.ttf");
    sfText_setFont(text, text_font);
    sfText_setString(text, text_t);
    sfText_setScale(text, scale);
    sfText_setPosition(text, position);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, i);
    return text;
}

sfText *loadtext_white(char *text_t, sfVector2f scale,
sfVector2f position, int i)
{
    sfText *text;
    sfFont *text_font;

    text = sfText_create();
    text_font = sfFont_createFromFile("assets/menu/setting/VINERITC.TTF");
    sfText_setFont(text, text_font);
    sfText_setString(text, text_t);
    sfText_setScale(text, scale);
    sfText_setPosition(text, position);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, i);
    return text;
}

sfText *loadtext_grey(char *text_t, sfVector2f scale,
sfVector2f position, int i)
{
    sfText *text;
    sfFont *text_font;
    sfColor color = sfColor_fromRGB(45, 45, 45);

    text = sfText_create();
    text_font = sfFont_createFromFile("assets/menu/setting/VINERITC.TTF");
    sfText_setFont(text, text_font);
    sfText_setString(text, text_t);
    sfText_setScale(text, scale);
    sfText_setPosition(text, position);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, i);
    return text;
}