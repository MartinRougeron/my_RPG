/*
** EPITECH PROJECT, 2020
** boss
** File description:
** lightning
*/

#include "my.h"

sfRectangleShape **create_lightning_part(sfVector2f pos)
{
    sfRectangleShape **shape = malloc(sizeof(sfRectangleShape *) * 80);
    int size;

    for (int i = 0; i != 80; i++) {
        size = rand() % 10 + 5;
        shape[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(shape[i],
        (sfVector2f) {size, size});
        sfRectangleShape_centerorigine(shape[i]);
        sfRectangleShape_setPosition(shape[i], pos);
        sfRectangleShape_setFillColor(shape[i],
        (sfColor) {102, 178, 255, rand() % 55 + 200});
    }
    return shape;
}

lightning_t create_lightning(sfVector2f pos)
{
    lightning_t lightning;

    lightning.pos = pos;
    lightning.clockanim = sfClock_create();
    lightning.clockspeed = sfClock_create();
    lightning.clockphase = sfClock_create();
    lightning.reset = sfClock_create();
    lightning.sprite = loadbutton("assets/player/lightning.png",
    (sfVector2f) {0.7, 0.7}, (sfVector2f) {0, 0});
    lightning.speed = malloc(sizeof(sfVector2f) * 80);
    for (int i = 0; i != 80; i++)
        lightning.speed[i] = (sfVector2f) {rand() % 40 - 20, -rand() % 15};
    lightning.particule = create_lightning_part(pos);
    sfSprite_setTextureRect(lightning.sprite, (sfIntRect) {0, 0, 700, 700});
    sfSprite_centerorigine(lightning.sprite);
    sfSprite_setPosition(lightning.sprite, pos);
    sfSprite_move(lightning.sprite, (sfVector2f) {0, -140});
    lightning.hit = FALSE;
    return lightning;
}

void setuplightning(game_t *game, sfVector2f pos)
{
    for (int i = 0; i != 60; i++) {
        if (game->dragon.lightning[i].sprite == NULL) {
            game->dragon.lightning[i] = create_lightning(pos);
            break;
        }
    }
}

void play_lightning_part(game_t *game, lightning_t lightning)
{
    int reset = (TIME(lightning.reset) > 300) ? 1 : 0;
    float elapsed =
    sfTime_asMilliseconds(sfClock_restart(lightning.clockspeed)) / 50.0f;

    if (reset)
        sfClock_restart(lightning.reset);
    for (int i = 0; i != 80; i++) {
        if (reset)
            sfRectangleShape_setPosition(lightning.particule[i], lightning.pos);
        sfRectangleShape_move(lightning.particule[i], (sfVector2f)
        {lightning.speed[i].x * elapsed, lightning.speed[i].y * elapsed});
        sfRenderWindow_drawRectangleShape(game->window,
        lightning.particule[i], NULL);
    }
    sfClock_restart(lightning.clockanim);
}

lightning_t play_lightning(game_t *game, lightning_t lightning)
{
    sfIntRect rect = sfSprite_getTextureRect(lightning.sprite);

    if (TIME(lightning.clockphase) < 3000) {
        play_lightning_part(game, lightning);
        return lightning;
    } else if (TIME(lightning.clockphase) < 4500) {
        damage_lightning(game, &lightning);
        if (TIME(lightning.clockanim) > 500) {
            rect = getrectlightning(rect);
            sfSprite_setTextureRect(lightning.sprite, rect);
            sfClock_restart(lightning.clockanim);
        }
        sfRenderWindow_drawSprite(game->window, lightning.sprite, NULL);
    } else {
        destroy_lightning(lightning);
        lightning.sprite = NULL;
    }
    return lightning;
}