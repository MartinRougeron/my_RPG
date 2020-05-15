/*
** EPITECH PROJECT, 2020
** weather
** File description:
** rain
*/

#include "my.h"

sfRectangleShape *createshape(sfVector2f position, sfVector2f scale)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, scale);
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setFillColor(shape,
    sfColor_fromRGBA(0, 0, 255, rand() %
    (int)sfRectangleShape_getSize(shape).y * 5));
    return shape;
}

void makerain(game_t *game)
{
    static float speed[NBRAIN];
    static sfRectangleShape *shape[NBRAIN] = {NULL};

    if (shape[0] == NULL)
        for (int i = 0; i != NBRAIN; i++) {
            shape[i] = createshape((sfVector2f) {rand() % 1920, rand() % 1080},
            (sfVector2f) {(rand() % 15) / 10.f + 1, (rand() % 500) 
            / 10.f + 3});
            speed[i] = pow(sfRectangleShape_getSize(shape[i]).x, 2);
        }
    for (int i = 0; i != NBRAIN; i++) {
        sfRectangleShape_move(shape[i], (sfVector2f) {0, speed[i] + 2});
        if (sfRectangleShape_getPosition(shape[i]).y > HEIGHT)
            sfRectangleShape_setPosition(shape[i],
            (sfVector2f) {sfRectangleShape_getPosition(shape[i]).x, -40});
        DRAW_SHAPE(game->window, shape[i], NULL);
    }
}

void dofade(game_t *game)
{
    static sfRectangleShape *black = NULL;
    static sfClock *fade = NULL;
    static int fade_value = 0;

    if (black == NULL) {
        black = createshape((sfVector2f){0, 0}, (sfVector2f){1920, 1080});
        fade = sfClock_create();
    }
    if (TIME(fade) > 350 && ((fade_value <= 50 && game->weather == RAIN) ||
    (fade_value > 0 && game->weather == SHINE)))
        fade_value += (game->weather == RAIN) ? 1 : -1;
    sfRectangleShape_setFillColor(black, sfColor_fromRGBA(0, 0, 0, 
    fade_value));
    DRAW_SHAPE(game->window, black, NULL);
}

void dorain(game_t *game)
{
    dofade(game);
    if (TIME(game->weatherclock) > 200000 && game->weather == SHINE) {
        game->weather = (rand() % 100 < 10) ? RAIN : SHINE;
        sfClock_restart(game->weatherclock);
    }
    if (TIME(game->weatherclock) > 100000 && game->weather == RAIN) {
        game->weather = SHINE;
        sfClock_restart(game->weatherclock);
    }
    if (game->weather == RAIN)
        makerain(game);
}