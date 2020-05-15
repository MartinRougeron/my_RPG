/*
** EPITECH PROJECT, 2020
** dragon attack
** File description:
** dragon atatck
*/

#include "my.h"

void lightning_attack(game_t *game, dragon_t *dragon)
{
    int x;
    int y;

    if (TIME(dragon->shoot) < 200)
        return;
    sfClock_restart(dragon->shoot);
    x = rand() % 30;
    y = rand() % 30;
    setuplightning(game, convertpos((pos_t) {0, 0, 0, x, y}));
}

void portal_attack(game_t *game, dragon_t *dragon)
{
    sfVector2f pos =
    convertpos((pos_t) {0, 0, 0, rand() % 30, rand() % 30});

    if (TIME(dragon->shoot) < 1500)
        return;
    sfClock_restart(dragon->shoot);
    add_portal(game, pos, rand() % 3 + 2);
}

void fireball_attack(game_t *game, dragon_t *dragon)
{
    sfVector2f place = sfSprite_getPosition(dragon->dragon);

    if (TIME(dragon->shoot) < 800)
        return;
    sfClock_restart(dragon->shoot);
    add_fireball(game, place, sfSprite_getPosition(game->player.sprite));
}

void attack_dragon(game_t *game, dragon_t *dragon)
{
    if (dragon->stance == LIGHTNING)
        lightning_attack(game, dragon);
    if (dragon->stance == PORTAL)
        portal_attack(game, dragon);
    if (dragon->stance == FIREBALL)
        fireball_attack(game, dragon);
}