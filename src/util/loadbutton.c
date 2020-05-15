/*
** EPITECH PROJECT, 2020
** load
** File description:
** button
*/

#include "my.h"

sfSprite *loadskill(char *path, sfVector2f scale, sfVector2f position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_centerorigine(sprite);
    return sprite;
}

sfSprite *loadspritenemie(char *path, sfVector2f scale, sfVector2f position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfSprite *loadspriterect(char *path, sfVector2f scale,
sfVector2f position, sfIntRect rect)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, &rect);

    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_centerorigine(sprite);
    return sprite;
}

sfText *loadnbofcmpt(char *text_t, sfVector2f position, int i)
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
    sfText_centerorigine(text);
    return text;
}

sfText *loadtxtname(char *text_t, sfVector2f position, int i)
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
    sfText_setOrigin(text, (sfVector2f)
    {sfText_getLocalBounds(text).width / 2, 0});
    return text;
}