/*
** EPITECH PROJECT, 2020
** anim
** File description:
** dragon
*/

#include "my.h"

void anim_wandering(dragon_t *dragon)
{
    sfIntRect rect = sfSprite_getTextureRect(dragon->dragon);

    rect.top = 256;
    if (TIME(dragon->anim) > 500) {
        rect.left += 128;
        if (rect.left == 512)
            rect.left = 128;
        sfClock_restart(dragon->anim);
    }
    sfSprite_setTextureRect(dragon->dragon, rect);
}

void anim_lightning(dragon_t *dragon)
{
    sfIntRect rect = sfSprite_getTextureRect(dragon->dragon);

    rect.top = 0;
    if (TIME(dragon->anim) > 500) {
        rect.left += 128;
        if (rect.left == 640)
            rect.left = 0;
        sfClock_restart(dragon->anim);
    }
    sfSprite_setTextureRect(dragon->dragon, rect);
}

void anim_fireball(dragon_t *dragon)
{
    sfIntRect rect = sfSprite_getTextureRect(dragon->dragon);

    rect.top = 384;
    if (TIME(dragon->anim) > 500) {
        rect.left += 128;
        if (rect.left == 256)
            rect.left = 128;
        sfClock_restart(dragon->anim);
    }
    sfSprite_setTextureRect(dragon->dragon, rect);
}

void anim_dragon_portal(dragon_t *dragon)
{
    sfIntRect rect = sfSprite_getTextureRect(dragon->dragon);

    rect.top = 512;
    if (TIME(dragon->anim) > 500) {
        rect.left += 128;
        if (rect.left == 512 + 128)
            rect.left = 0;
        sfClock_restart(dragon->anim);
    }
    sfSprite_setTextureRect(dragon->dragon, rect);
}

void anim_dragon(dragon_t *dragon)
{
    if (dragon->stance == WANDERING)
        anim_wandering(dragon);
    if (dragon->stance == LIGHTNING)
        anim_lightning(dragon);
    if (dragon->stance == FIREBALL)
        anim_fireball(dragon);
    if (dragon->stance == PORTAL)
        anim_dragon_portal(dragon);
    if (TIME(dragon->takedmg) < 300)
        sfSprite_setTextureRect(dragon->dragon, (sfIntRect)
        {0, 256, 128, 128});
}
