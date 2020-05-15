/*
** EPITECH PROJECT, 2020
** player
** File description:
** walking anim
*/

#include "my.h"

void freewalkanim(walkanim_t *anim)
{
    for (int i = 0; i != NBPARTWALKANIM; i++) {
        sfRectangleShape_destroy(anim[i].shape);
    }
}

void norm_r(game_t *game, int i, walkanim_t *anim)
{
    sfRectangleShape_move(anim[i].shape, (sfVector2f){
    (game->player.face == EST) ? 30 :
    (game->player.face == WEST) ? -50 : 0,
    (game->player.face == NORTH) ? 40 :
    (game->player.face == SOUTH) ? -100 : 0
    });
    DRAW_SHAPE(game->window,
    anim[i].shape, NULL);
}

walkanim_t *loadwalkanim(int y, game_t *game)
{
    walkanim_t *anim = malloc(sizeof(walkanim_t) * NBPARTWALKANIM);
    int size;

    for (int i = 0; i != NBPARTWALKANIM; i++) {
        size = rand() % 15 + 8;
        anim[i].shape = sfRectangleShape_create();
        anim[i].y = 0;
        anim[i].x = 0;
        anim[i].speed = (sfVector2f) {rand() % 4 - 2, rand() % 4 - 6};
        sfRectangleShape_setFillColor(anim[i].shape,
        (sfColor) {222, 184, 135, rand() % 255 + 200});
        sfRectangleShape_setSize(anim[i].shape, (sfVector2f) {size, size});
        sfRectangleShape_setPosition(anim[i].shape, (sfVector2f)
        {sfSprite_getPosition(game->player.sprite).x, y - 10});
        anim[i].base = -10;
    }
    return anim;
}

walkanim_t *movewalkanim(game_t *game, walkanim_t *anim, sfVector2f posp)
{
    int exist = 0;

    for (int i = 0; i != NBPARTWALKANIM; i++) {
        if (anim[i].base < anim[i].y) {
            exist = 1;
            sfRectangleShape_move(anim[i].shape, anim[i].speed);
            anim[i].base += anim[i].speed.y;
            anim[i].x += anim[i].speed.x;
            anim[i].speed.y += 0.5;
            sfRectangleShape_setPosition(anim[i].shape, (sfVector2f)
            {posp.x + anim[i].x, posp.y + anim[i].base + 60});
            norm_r(game, i, anim);
        }
    }
    if (!exist) {
        freewalkanim(anim);
        anim = loadwalkanim(posp.y + 70, game);
    }
    return anim;
}

void walkinganim(game_t *game)
{
    static walkanim_t *anim = NULL;

    if (anim == NULL)
        anim =
        loadwalkanim(sfSprite_getPosition(game->player.sprite).y + 70, game);
    anim = movewalkanim(game, anim, sfSprite_getPosition(game->player.sprite));
}