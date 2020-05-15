/*
** EPITECH PROJECT, 2020
** util
** File description:
** lightning
*/

#include "my.h"

void destroy_lightning(lightning_t lightning)
{
    sfClock_destroy(lightning.clockanim);
    sfClock_destroy(lightning.clockphase);
    sfClock_destroy(lightning.clockspeed);
    sfClock_destroy(lightning.reset);
    sfSprite_destroy(lightning.sprite);
    for (int i = 0; i != 20; i++)
        sfRectangleShape_destroy(lightning.particule[i]);
    free(lightning.particule);
    free(lightning.speed);
}

void damage_lightning(game_t *game, lightning_t *lightning)
{
    sfVector2f pos = sfSprite_getPosition(game->player.sprite);

    if (lightning->hit == TRUE)
        return;
    if (pos.x < lightning->pos.x + 60 && pos.x > lightning->pos.x -60 &&
    pos.y < lightning->pos.y + 60 && pos.y > lightning->pos.y - 60) {
        lightning->hit = TRUE;
        game->player.stat.health -= 80;
        addtxtdmg(game, 80, pos);
    }
}