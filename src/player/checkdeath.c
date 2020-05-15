/*
** EPITECH PROJECT, 2020
** player
** File description:
** death
*/

#include "my.h"

void dodeath(game_t *game)
{
    if (game->player.stat.health <= 0) {
        game->screen = TITLE_SCREEN;
        sfSprite_setPosition(game->player.sprite,
        (sfVector2f) {930, 319});
        game->player.face = SOUTH;
        all_call_set(game);
        game->dragon = create_dragon();
        game->triviantan = loadtriviatan();
        destroy_enemie(game);
        for (int i = 0; i != INVENTORY_SIZE + NBSLOT; i++)
            getitem[i].sprite = NULL;
    }
}