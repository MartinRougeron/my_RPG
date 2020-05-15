/*
** EPITECH PROJECT, 2020
** take damage
** File description:
** take
*/

#include "my.h"

sfRectangleShape *loaddamageshape(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, (sfVector2f) {1920, 1080});
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineColor(shape, (sfColor) {138, 3, 3, 200});
    sfRectangleShape_setOutlineThickness(shape, -50);
    return shape;
}

sfRectangleShape *animblood(game_t *game, sfRectangleShape *shape)
{
    static sfClock *clock = NULL;
    sfColor color;

    if (clock == NULL)
        clock = sfClock_create();
    if (shape != NULL) {
        DRAW_SHAPE(game->window, shape, NULL);
        if (TIME(clock) > 50) {
            color = sfRectangleShape_getOutlineColor(shape);
            color.a -= 5;
            sfRectangleShape_setOutlineColor(shape, color);
            sfClock_restart(clock);
        }
        if (sfRectangleShape_getOutlineColor(shape).a < 50) {
            sfRectangleShape_destroy(shape);
            shape = NULL;
        }
    }
    return shape;
}

void astakedamage(game_t *game)
{
    static sfRectangleShape *shape = NULL;

    if (game->playerpvstart > game->player.stat.health) {
        if (shape != NULL)
            sfRectangleShape_destroy(shape);
        shape = loaddamageshape();
    }
    shape = animblood(game, shape);
}