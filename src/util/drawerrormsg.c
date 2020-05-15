/*
** EPITECH PROJECT, 2020
** draw error msg
** File description:
** draw
*/

#include "my.h"

sfText *createtext(unsigned int size, sfRenderWindow *window, char * msg,
sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setCharacterSize(text, size);
    sfText_setString(text, msg);
    sfText_setFont(text, font);
    sfText_setOrigin(text, (sfVector2f)
    {sfText_getGlobalBounds(text).width / 2,
    sfText_getGlobalBounds(text).height / 2});
    sfText_setPosition(text, (sfVector2f)
    {sfRenderWindow_getSize(window).x / 2, 200});
    return text;
}

int removeb(sfText *text, sfClock *clock)
{
    sfColor getcol;

    getcol = sfText_getColor(text);
    if (getcol.a - 2 <= 0) {
        sfText_destroy(text);
        sfClock_destroy(clock);
        text = NULL;
        return 1;
    }
    else {
        getcol.a -= 2;
        sfText_setColor(text, getcol);
    }
    return 0;
}

void drawerrormsg(sfColor color, char *msg, sfRenderWindow *window,
unsigned int size)
{
    static sfFont *font = NULL;
    static sfText *text;
    static sfClock *clock;

    if (font == NULL)
        font = sfFont_createFromFile("assets/Optimus.otf");
    if (msg != NULL)  {
        text = createtext(size, window, msg, font);
        sfText_setColor(text, color);
        clock = sfClock_create();
    }
    if (text != NULL && msg == NULL){
        sfRenderWindow_drawText(window, text, NULL);
        if (TIME(clock) < 500)
            return;
        if (removeb(text, clock) == 1)
            text = NULL;
    }
}