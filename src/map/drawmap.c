/*
** EPITECH PROJECT, 2020
** map
** File description:
** draw
*/

#include "my.h"

sfVector2f transform_to_isometric_inv(int x, int y)
{
    sfVector2f new;

    new = (sfVector2f) {
        x/128 + y/64,
        y/64 - x/128
    };
    return new;
}

sfVector2f transform_to_isometric_map(int x, int y)
{
    sfVector2f new;

    new = (sfVector2f) {
    (x - y) * 64,
    (x + y) * 64 * 0.5
    };
    return new;
}

void placetiles_iso(game_t *game, int y, int x, int z)
{
    if (MAP_POS != -1) {
        sfSprite_setScale(game->tiles.tiles_iso[MAP_POS],
        (sfVector2f) {2, 2});
        sfSprite_setPosition(game->tiles.tiles_iso[MAP_POS],
        transform_to_isometric_map
        (x, y)), sfSprite_move(game->tiles.tiles_iso[MAP_POS],
        (sfVector2f){800, -300});
        sfRenderWindow_drawSprite(game->window, game->tiles.tiles_iso[MAP_POS],
        NULL);
    }
}

void placetiles(game_t *game, int y, int x, int z)
{
    if (MAP_POS != -1) {
        sfSprite_setTextureRect(game->tiles.tiles233,
        getrect(33, 24, MAP_POS));
        sfSprite_setScale(game->tiles.tiles233, (sfVector2f) {2.666, 1.5});
        sfSprite_setPosition(game->tiles.tiles233,
        (sfVector2f) {x * (1920 / MAPTILESX), y * (1080 / MAPTILESY)});
        sfRenderWindow_drawSprite(game->window, game->tiles.tiles233, NULL);
    }
}

void drawmap(game_t *game)
{
    for (int y = 0; y != MAPTILESY; y++)
        for (int x = 0; x != MAPTILESX; x++)
            for (int z = 0; z != NBLAYER; z++)
                (!isometric) ? placetiles(game, y, x, z) :
                placetiles_iso(game, y, x, z);
}