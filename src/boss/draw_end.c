/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_end.c
*/

#include "my.h"

void finish(game_t *game)
{
    game->screen = GAME;
    game->player.position.map = WORLD;
    game->player.position.x = 2;
    game->player.position.y = 2;
    sfSprite_setPosition(game->player.sprite, (sfVector2f) {1920/2, 700});
}

void draw_end(game_t *game)
{
    static sfSprite *credits = NULL;
    static sfClock *clock = NULL;
    static sfClock *clock_total = NULL;

    if (credits == NULL)
        credits = loadbutton("assets/menu/titlescreen/credits.png",
        (sfVector2f){1, 1}, (sfVector2f) {1920/2, 1080});
    sfSprite_centerorigine(credits);
    if (clock == NULL)
        clock = sfClock_create();
    if (clock_total == NULL)
        clock_total = sfClock_create();
    sfSprite_move(credits, (sfVector2f) {0, TIME(clock) * -0.1});
    sfClock_restart(clock);
    sfRenderWindow_drawSprite(game->window, game->menu.fond, NULL);
    sfRenderWindow_drawSprite(game->window, credits, NULL);
    if (TIME(clock_total) > 5000) {
        finish(game);
    }
}