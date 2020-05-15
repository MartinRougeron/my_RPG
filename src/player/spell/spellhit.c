/*
** EPITECH PROJECT, 2020
** spell
** File description:
** hit
*/

#include "my.h"

int dospellhit(spell_t *spell, game_t *game)
{
    sfFloatRect bound = sfSprite_getGlobalBounds(spell->sprite);
    sfFloatRect enemie;

    for (int i = 0; i != NBMAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        enemie = sfSprite_getGlobalBounds(game->enemie[i].sprite);
        if (sfFloatRect_intersects(&bound, &enemie, NULL))
            return i;
    }
    return -1;
}

void spellhit(spell_t *spell, game_t *game)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(spell->sprite);
    sfFloatRect enemie;
    int damage = spell->damage;

    if (gottheskill(game->player.tree.unlocked, FINAL_CHAPTER))
        damage *= 1.5;
    if (gottheskill(game->player.tree.unlocked, ARCANOPULSE))
        damage *= (rand() % 100 < 20) ? 5 : 1;
    for (int i = 0; i != MAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        enemie = sfSprite_getGlobalBounds(game->enemie[i].sprite);
        bounds.height += spell->range * 2;
        bounds.width += spell->range * 2;
        bounds.left -= spell->range;
        bounds.top -= spell->range;
        if (sfFloatRect_intersects(&enemie, &bounds, NULL))
            dodamageenemie(game, i, damage);
    }
    clearspell(spell);
}