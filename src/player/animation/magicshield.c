/*
** EPITECH PROJECT, 2020
** magic
** File description:
** shield
*/

#include "my.h"

void norm(game_t *game, sfIntRect rect)
{
    if (rect.left == 192 * 5) {
            rect.left = 0;
            rect.top += 192;
    }
    if (rect.top == 192 * 4) {
            rect.left = 0;
            rect.top = 0;
    }
}

void animshield(game_t *game, sfSprite *shield)
{
    static sfClock *clock = NULL;
    sfIntRect rect = sfSprite_getTextureRect(shield);

    if (clock == NULL)
        clock = sfClock_create();
    sfSprite_setPosition(shield, (sfVector2f) {sfSprite_getPosition
    (game->player.sprite).x, sfSprite_getPosition
    (game->player.sprite).y + 15});
    if (TIME(clock) > 50) {
        rect.left += 192;
        norm(game, rect);
        sfSprite_setTextureRect(shield, rect);
        sfClock_restart(clock);
    }
}

void magicshield(game_t *game)
{
    static sfSprite *shield = NULL;
    static float time = 0;

    if (shield == NULL) {
        shield = loadskill("assets/player/magicshield.png",
        (sfVector2f) {0.72, 1.1}, (sfVector2f) {0, 0});
        sfSprite_setTextureRect(shield, (sfIntRect) {0, 0, 192, 192});
        sfSprite_centerorigine(shield);
    }
    if (game->screen != GAME || !game->player.shield)
        sfClock_restart(game->player.clockshield);
    if (!game->player.shield)
        return;
    animshield(game, shield);
    sfRenderWindow_drawSprite(game->window, shield, NULL);
    time += sfTime_asMilliseconds(sfClock_restart(game->player.clockshield));
    if (time > SHIELDSPELLDURATION) {
        time = 0;
        game->player.shield = 0;
    }
}