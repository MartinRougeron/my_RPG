/*
** EPITECH PROJECT, 2020
** genwindow
** File description:
** genwindow
*/

#include "../include/my.h"

sfRenderWindow *genwindow(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "rpg", sfFullscreen, NULL);
    sfWindow_setFramerateLimit((sfWindow *) window, 60);
    return window;
}

