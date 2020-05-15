/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** dragon_phase.c
*/

#include "my.h"

sfIntRect dragon_phase(game_t *game, dragon_t *dragon, sfIntRect rect,
                    int side)
{
    if (dragon->stance == WANDERING) {
        if (TIME(dragon->phase) > 3000) {
            dragon->stance = rand() % 3;
            rect.left = 0;
            sfSprite_setPosition(dragon->dragon, (sfVector2f)
            {side, rand() % 850 + 150});
            if (side == 100)
                sfSprite_setScale(dragon->dragon, (sfVector2f) {-2.5, 2.5});
            else
                sfSprite_setScale(dragon->dragon, (sfVector2f) {2.5, 2.5});
            sfClock_restart(dragon->phase);
        }
    }
    if (damage_dragon(game, dragon))
        sfClock_restart(dragon->takedmg);
    return (rect);
}
