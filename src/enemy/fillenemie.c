/*
** EPITECH PROJECT, 2020
** enemie
** File description:
** fill
*/

#include "my.h"

void fillenemie(enemie_t *enemie, FILE *fd)
{
    size_t size = 0;
    char *str = NULL;
    char *path;
    sfVector2f scale;

    getline(&str, &size, fd);
    removebackn(str);
    path = my_strdup(str);
    getline(&str, &size, fd);
    removebackn(str);
    scale.x = my_getnbr(str) / 10.f;
    getline(&str, &size, fd);
    removebackn(str);
    scale.y = my_getnbr(str) / 10.f;
    enemie->clock_attack = sfClock_create();
    enemie->clockanimation = sfClock_create();
    enemie->sprite = loadspritenemie(path, scale, (sfVector2f) {0, 0});
    sfSprite_setTextureRect(enemie->sprite, (sfIntRect) {0, 0, 32, 32});
    sfSprite_centerorigine(enemie->sprite);
}