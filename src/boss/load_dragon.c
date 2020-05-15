/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_dragon.c
*/

#include "my.h"

dragon_t load_dragon(dragon_t dragon)
{
    dragon.lightning = malloc(sizeof(lightning_t) * 80);
    for (int i = 0; i != 80; i++)
        dragon.lightning[i].sprite = NULL;
    dragon.fireball = malloc(sizeof(fireball_t) * 20);
    for (int i = 0; i != 20; i++)
        dragon.fireball[i].sprite = NULL;
    dragon.portal = malloc(sizeof(portal_t) * 20);
    for (int i = 0; i != 20; i++)
        dragon.portal[i].portal = NULL;
    dragon.phase = sfClock_create();
    dragon.dragon = sfSprite_create();
    dragon.anim = sfClock_create();
    dragon.shoot = sfClock_create();
    dragon.takedmg = sfClock_create();
    dragon.die = sfClock_create();
    dragon.health = DRAGONHEALTH;
    dragon.maxhealth = DRAGONHEALTH;
    dragon.stance = WANDERING;
    return (dragon);
}