/*
** EPITECH PROJECT, 2020
** particule
** File description:
** deadparticuke
*/

#include "my.h"

walkanim_t *loadparticule(sfVector2f enemie, sfColor color, int time)
{
    walkanim_t *part = malloc(sizeof(walkanim_t) * 6);
    sfVector2f move[6] = {{-2, 4}, {2.2, 4.6}, {-1.8, 0.2},
    {1.4, -0.3}, {2, -6}, {2.6, -6.4}};

    for (int i = 0; i != 6; i++) {
        part[i].shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(part[i].shape, color);
        sfRectangleShape_setSize(part[i].shape, (sfVector2f) {14, 14});
        part[i].clock = sfClock_create();
        part[i].speed = move[i];
        part[i].timetostay = time;
        sfRectangleShape_centerorigine(part[i].shape);
        sfRectangleShape_setPosition(part[i].shape, enemie);
    }
    return part;
}

void adddeadparticule(game_t *game, sfVector2f enemie, sfColor color, int time)
{
    for (int i = 0; i != MAXENEMIE; i++) {
        if (game->deadanim[i] == NULL) {
            game->deadanim[i] = loadparticule(enemie, color, time);
            break;
        }
    }
}

void playdeadparticule(game_t *game)
{
    for (int i = 0, end = 0; i != MAXENEMIE; i++, end = 0) {
        if (game->deadanim[i] == NULL)
            continue;
        for (int y = 0; y != 6; y++) {
            sfRectangleShape_move(game->deadanim[i][y].shape,
            game->deadanim[i][y].speed);
            DRAW_SHAPE(game->window,
            game->deadanim[i][y].shape, NULL);
            if (TIME(game->deadanim[i][y].clock) >
            game->deadanim[i][y].timetostay) {
                sfRectangleShape_destroy(game->deadanim[i][y].shape);
                sfClock_destroy(game->deadanim[i][y].clock);
                end = 1;
            }
        }
        if (end) {
            free(game->deadanim[i]);
            game->deadanim[i] = NULL;
        }
    }
}