/*
** EPITECH PROJECT, 2020
** light
** File description:
** light
*/

#include "my.h"
void norm_lightspell(game_t *game, float timepassed)
{
    if (timepassed > LIGHTSPELLDURATION) {
        game->player.light = 0;
        timepassed = 0;
    }
}

sfCircleShape *loadlight(void)
{
    sfCircleShape *shape = NULL;

    if (shape == NULL) {
        shape = sfCircleShape_create();
        sfCircleShape_setRadius(shape, 500);
        sfCircleShape_centerorigine(shape);
        sfCircleShape_setOutlineThickness(shape, 2000);
        sfCircleShape_setOutlineColor(shape, sfBlack);
        sfCircleShape_setFillColor(shape, (sfColor) {249, 215, 28, 100});
    }
    return shape;
}

void lightspell(game_t *game)
{
    static sfCircleShape *shape = NULL;
    static float timepassed = 0;

    if (shape == NULL)
        shape = loadlight();
    if (!game->player.light) {
        sfClock_restart(game->player.clocklight);
        return;
    }
    if (game->screen != GAME)
        sfClock_restart(game->player.clocklight);
    timepassed +=
    sfTime_asMilliseconds(sfClock_restart(game->player.clocklight));
    sfCircleShape_setPosition(shape,
    sfSprite_getPosition(game->player.sprite));
    sfRenderWindow_drawCircleShape(game->window, shape, NULL);
    norm_lightspell(game, timepassed);
}