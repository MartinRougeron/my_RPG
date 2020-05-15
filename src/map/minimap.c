/*
** EPITECH PROJECT, 2020
** map
** File description:
** minimap
*/

#include "my.h"

sfSprite *createminimap(void)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite,
    sfTexture_createFromFile("assets/map/minimap.png", NULL), sfTrue);
    sfSprite_centerorigine(sprite);
    sfSprite_setScale(sprite, (sfVector2f) {0.12, 0.12});
    sfSprite_setPosition(sprite, (sfVector2f) {WIDTH / 2, HEIGHT / 2});
    return sprite;
}

sfRectangleShape *createshapesel(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineColor(shape, sfYellow);
    sfRectangleShape_setOutlineThickness(shape, 3);
    sfRectangleShape_setSize(shape, (sfVector2f) {86.3, 86.3});
    return shape;
}

sfRectangleShape *createshapeborder(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    sfRectangleShape_setOutlineThickness(shape, 5);
    sfRectangleShape_setSize(shape, (sfVector2f) {518.1, 518.4});
    sfRectangleShape_setPosition(shape, (sfVector2f) {701, 281});
    return shape;
}

void displayminimap(game_t *game)
{
    static sfSprite *sprite = NULL;
    static sfRectangleShape *select;
    static sfRectangleShape *border;

    if (game->player.map != 1)
        return;
    if (sprite == NULL) {
        sprite = createminimap();
        select = createshapesel();
        border = createshapeborder();
    }
    sfRectangleShape_setPosition(select, (sfVector2f)
    {701 + game->player.position.x * 86.3,
    281 + game->player.position.y * 86.3});
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window, select, NULL);
    sfRenderWindow_drawRectangleShape(game->window, border, NULL);
}