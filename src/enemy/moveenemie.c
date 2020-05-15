/*
** EPITECH PROJECT, 2020
** enemie
** File description:
** move
*/

#include "my.h"

void resetrect(game_t *game, int i)
{
    sfIntRect rect = sfSprite_getTextureRect(game->enemie[i].sprite);

    rect.top = 32 * game->enemie[i].face;
    sfSprite_setTextureRect(game->enemie[i].sprite, rect);
}

int checkcolisionenemie(game_t *game, int i)
{
    for (int y = 0; y != NBMAXENEMIE; y++) {
        if (game->enemie[y].sprite == NULL)
            continue;
        if (y == i)
            continue;
        if (!isaround(game->enemie[y].sprite, game->enemie[i].sprite, 30))
            return 1;
    }
    return 0;
}

sfVector2f moveiny(int i, game_t *game, sfVector2f pos, float elapsed)
{
    sfVector2f posp = sfSprite_getPosition(game->player.sprite);

    if (pos.y < posp.y) {
        pos.y += 0.3 * elapsed;
        game->enemie[i].face = SOUTH;
        if (pos.y >= posp.y)
            pos.y = posp.y;
    } else if (pos.y > posp.y) {
        pos.y += -0.3 * elapsed;
        game->enemie[i].face = NORTH;
        if (pos.y <= posp.y)
            pos.y = posp.y;
    }
    return pos;
}

sfVector2f processmove(int i, game_t *game, sfVector2f posp)
{
    float elapsed =
    sfTime_asMilliseconds(sfClock_restart(game->enemie[i].clockmove));
    sfVector2f pos = sfSprite_getPosition(game->enemie[i].sprite);

    if (pos.x < posp.x) {
        pos.x += 0.3 * elapsed;
        game->enemie[i].face = WEST;
        if (pos.x > posp.x)
            pos.x = posp.x;
    } else if (pos.x > posp.x) {
        pos.x += -0.3 * elapsed;
        game->enemie[i].face = EST;
        if (pos.x <= posp.x)
            pos.x = posp.x;
    }
    return moveiny(i, game, pos, elapsed);
}

sfVector2f moveenemie(game_t *game, int i, sfVector2f posp)
{
    sfVector2f possave = sfSprite_getPosition(game->enemie[i].sprite);
    sfVector2f pos = processmove(i, game, posp);

    resetrect(game, i);
    sfSprite_setPosition(game->enemie[i].sprite, pos);
    if (checkcolisionenemie(game, i))
        sfSprite_setPosition(game->enemie[i].sprite, possave);
    return pos;
}