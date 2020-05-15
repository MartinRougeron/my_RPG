/*
** EPITECH PROJECT, 2020
** anim
** File description:
** anim
*/

#include "my.h"

void animplayer(game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->player.sprite);
    int movesprite = rect.width;
    int frame[4] = {4, 3, 2, NBFRAMESPELL};
    int speedanim[4] = {ANIMWALK, ANIMATTACK, 250, ANIMSPELL};

    if (TIME(game->player.animationclock) > speedanim[game->player.state]) {
        rect.left += movesprite;
        if (rect.left == movesprite * frame[game->player.state])
            rect.left = 0;
        sfSprite_setTextureRect(game->player.sprite, rect);
        sfClock_restart(game->player.animationclock);
    }
}