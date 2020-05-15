/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_music.c
*/

#include "my.h"

sfMusic **create_music(char **path, int nb)
{
    sfMusic **fill = malloc(sizeof(sfMusic *) * nb);

    for (int i = 0; i < nb; i++) {
        fill[i] =  sfMusic_createFromFile(path[i]);
    }
    return (fill);
}