/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** detect_range_ennemies.c
*/

#include "my.h"

void detect_matching_range(game_t *game, sfFloatRect range)
{
    sfFloatRect enemy;
    int damage = game->player.stat.damage + getequipmentdamage(game);

    if (gottheskill(game->player.tree.unlocked, BATTLEFURY))
        damage *= 1.5;
    if (gottheskill(game->player.tree.unlocked, CRITICAL))
        damage *= (rand() % 100 < 20) ? 3.5 : 1;
    for (int i = 0; i < MAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        enemy = sfSprite_getGlobalBounds(game->enemie[i].sprite);
        if (sfFloatRect_intersects(&enemy, &range, NULL)) {
            dodamageenemie(game, i, damage);
        }
    }
}