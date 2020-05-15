/*
** EPITECH PROJECT, 2020
** part
** File description:
** part
*/

#include "my.h"

sfRectangleShape *initspellpart(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    float size = rand() % 15 + 8;

    sfRectangleShape_setSize(shape, (sfVector2f) {size, size});
    return shape;
}

walkanim_t initpart(facing_t face)
{
    walkanim_t part;

    for (int i = 0; i != NBPARTSPELL; i++) {
        part.shape = initspellpart();
        part.clock = sfClock_create();
        part.speed = (sfVector2f) {rand() % 20, rand() % 6 - 3};
        part.base = rand() % 250;
        part.x = 0;
        part.y = 0;
        if (face == WEST || face == SOUTH) {
            part.speed.x *= -1;
            part.speed.y *= -1;
        }
    }
    return part;
}

walkanim_t setpartcolor(walkanim_t part, int which, facing_t face)
{
    SET_COLOR;
    part.base += sfTime_asMilliseconds(sfClock_restart(part.clock));
    if (part.base < 50)
        sfRectangleShape_setFillColor(part.shape, color[which][0]);
    if (part.base > 50 && part.base < 100)
        sfRectangleShape_setFillColor(part.shape, color[which][1]);
    if (part.base > 100 && part.base < 150)
        sfRectangleShape_setFillColor(part.shape, color[which][2]);
    if (part.base > 150 && part.base < 200)
        sfRectangleShape_setFillColor(part.shape, color[which][3]);
    if (part.base > 200)
        sfRectangleShape_setFillColor(part.shape, color[which][4]);
    if (part.base > 250) {
        sfRectangleShape_destroy(part.shape);
        sfClock_destroy(part.clock);
        part = initpart(face);
        sfRectangleShape_setFillColor(part.shape, color[which][0]);
    }
    return part;
}

void animpart(game_t *game, spell_t spell)
{
    for (int i = 0; i != NBPARTSPELL; i++) {
        spell.part[i] = setpartcolor(spell.part[i], spell.which, spell.face);
        sfRectangleShape_setPosition(spell.part[i].shape,
        sfSprite_getPosition(spell.sprite));
        sfRectangleShape_move(spell.part[i].shape, (sfVector2f) {spell.part[i].
        speed.x + spell.part[i].x,
        spell.part[i].speed.y + spell.part[i].y - 11});
        if (spell.face == NORTH || spell.face == SOUTH)
            sfRectangleShape_move(spell.part[i].shape, (sfVector2f) {-11, 0});
        spell.part[i].x += (spell.face == NORTH || spell.face == SOUTH) ?
        spell.part[i].speed.y : spell.part[i].speed.x;
        spell.part[i].y += (spell.face == NORTH || spell.face == SOUTH) ?
        spell.part[i].speed.x : spell.part[i].speed.y;
        DRAW_SHAPE
        (game->window, spell.part[i].shape, NULL);
    }
}