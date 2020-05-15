/*
** EPITECH PROJECT, 2020
** player
** File description:
** clear spell
*/

#include "my.h"

void clearspell(spell_t *spell)
{
    sfClock_destroy(spell->animclock);
    sfClock_destroy(spell->moveclock);
    sfSprite_destroy(spell->sprite);
    for (int i = 0; i != NBPARTSPELL; i++) {
        if (spell->part[i].shape != NULL) {
            sfRectangleShape_destroy(spell->part[i].shape);
            sfClock_destroy(spell->part[i].clock);
        }
    }
    free(spell->part);
    spell->sprite = NULL;
}