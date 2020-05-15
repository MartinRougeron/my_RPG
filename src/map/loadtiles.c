/*
** EPITECH PROJECT, 2020
** map
** File description:
** load tiles
*/

#include "my.h"

sfIntRect getrect(int len, int size, int id)
{
    sfIntRect rect;
    int x = 0;
    int y = 0;

    rect.height = size;
    rect.width = size;
    for (int i = 0; i != id; i++) {
        x += 1;
        if (x == len) {
            x = 0;
            y += 1;
        }
    }
    rect.left = x * size;
    rect.top = y * size;
    return rect;
}

sfSprite *loadtiles( sfVector2f scale, char *path)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture;

    texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void gentiles(game_t *game)
{
    game->tiles.tiles233 =
    loadtiles((sfVector2f) {2.666, 1.5}, "assets/map/tiles/tilesetrpg.png");
    game->tiles.tiles_iso = malloc(sizeof(sfSprite *) * NB_TILES_ISO);
    game->tiles.tiles_iso[0] = loadbutton("assets/map/tiles/1_.png",
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    game->tiles.tiles_iso[1] = loadbutton("assets/map/tiles/01.png",
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    game->tiles.tiles_iso[2] = loadbutton("assets/map/tiles/2.png",
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    game->tiles.tiles_iso[3] = loadbutton("assets/map/tiles/3.png",
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
}