/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** anim_enemy.c
*/

#include "my.h"

void anim_ennemy(game_t *game)
{
    sfIntRect rect;
    int movesprite = 128 / 4;

    for (int i = 0; i < MAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        sfRenderWindow_drawSprite(game->window, game->enemie[i].sprite, NULL);
        rect = sfSprite_getTextureRect(game->enemie[i].sprite);
        rect.top = 32 * game->enemie[i].face;
        movesprite = rect.width;
        if (TIME(game->enemie[i].clockanimation) > 250) {
            rect.left += movesprite;
            if (rect.left == movesprite * 3)
                rect.left = 0;
            sfSprite_setTextureRect(game->enemie[i].sprite, rect);
            sfClock_restart(game->enemie[i].clockanimation);
        }
    }
}