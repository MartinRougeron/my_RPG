/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** life_ennemies.c
*/


#include "my.h"

void drawlife(game_t *game, int i,
sfRectangleShape *contour, sfRectangleShape *life)
{
    sfVector2f vec;

    vec = sfSprite_getPosition(game->enemie[i].sprite);
    vec.y -= 60;
    vec.x -= 60;
    sfRectangleShape_setSize(life, (sfVector2f)
    {100 * (game->enemie[i].health * 1.0 / game->enemie[i].maxhealth), 10});
    sfRectangleShape_setPosition(contour, vec);
    sfRectangleShape_setPosition(life, vec);
    DRAW_SHAPE(game->window, contour, NULL);
    DRAW_SHAPE(game->window, life, NULL);
}

void enemy_life(game_t *game)
{
    sfRectangleShape *contour = sfRectangleShape_create();
    sfRectangleShape *life = sfRectangleShape_create();

    sfRectangleShape_setFillColor(contour, sfBlack);
    sfRectangleShape_setSize(contour, (sfVector2f) {100, 10});
    sfRectangleShape_setFillColor(life, sfGreen);
    for (int i = 0; i != MAXENEMIE; i++) {
        if (game->enemie[i].sprite == NULL)
            continue;
        if (game->enemie[i].health == game->enemie[i].maxhealth)
            continue;
        drawlife(game, i, contour, life);
    }
    sfRectangleShape_destroy(life);
    sfRectangleShape_destroy(contour);
}