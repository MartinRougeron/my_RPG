/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** enemy_attack.c
*/

#include "my.h"

void damage_player(game_t *game, int i)
{
    int damage = game->enemie[i].damage;

    if (gottheskill(game->player.tree.unlocked, PARADE))
        damage = (rand() % 100 < 10) ? 0 : damage;
    playertakedamage(game, game->enemie[i].damage);
    sfClock_restart(game->enemie[i].clock_attack);
}

void ennemy_ia(game_t *game)
{
    sfVector2f posp = sfSprite_getPosition(game->player.sprite);

    for (int i = 0; i < MAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        if (game->enemie[i].damage == 0)
            continue;
        moveenemie(game, i, posp);
        if (!isaround(game->player.sprite, game->enemie[i].sprite, 30) &&
        TIME(game->enemie[i].clock_attack) > 2000)
            damage_player(game, i);
    }
}