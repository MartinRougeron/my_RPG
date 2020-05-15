/*
** EPITECH PROJECT, 2020
** hud
** File description:
** hide
*/

#include "my.h"

void gethudtohide(game_t *game)
{
    sfFloatRect hud[4] = {
        {1, 1, 526, 121}, {703, 31, 513, 60}, {1525, 7, 390, 146},
        {1263, 28, 120, 60}
    };
    sfFloatRect player = sfSprite_getGlobalBounds(game->player.sprite);

    for (int i = 0; i != 4; i++) {
        if (sfFloatRect_intersects(&player, &hud[i], NULL))
            game->hide[i] = TRUE;
        else
            game->hide[i] = FALSE;
    }
}