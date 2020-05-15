/*
** EPITECH PROJECT, 2020
** tp
** File description:
** world > capital
*/

#include "my.h"

void casefarwater(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player.sprite);

    if (game->player.position.x == 0)
        if (pos.x >= 1920) {
            game->player.position.x += 1;
            sfSprite_move(game->player.sprite, (sfVector2f) {-1880, 0});
        }
    if (game->player.position.x == 1)
        if (pos.x <= 0) {
            game->player.position.x -= 1;
            sfSprite_move(game->player.sprite, (sfVector2f) {1880, 0});
        }
}

void worldtofar(game_t *game)
{
    int tiles;
    sfVector2f posact;
    int x, y;

    if (!samemap(game->player.position, (pos_t) {WORLD, 5, 0, 0, 0}))
        return;
    posact = sfSprite_getPosition(game->player.sprite);
    y = (int) roundf((posact.y + 33) / (1080 / MAPTILESY));
    x = (int) ((posact.x - 5) / (1920 / MAPTILESX));
    if (x < 0 || x >= MAPTILESX || y < 0 || y >= MAPTILESY)
        return;
    tiles = game->map.map[game->player.position.map]
    [game->player.position.y][game->player.position.x][1][y][x];
    if ((tiles >= 316 && tiles <= 319) || (tiles >= 349 && tiles <= 352)
    || (tiles >= 283 && tiles <= 286)) {
        game->player.position = (pos_t) {FARWATER, 0, 0, 0, 0};
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {995, 927});
        game->player.face = NORTH;
        destroy_enemie(game);
    }
}

void fartoworld(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player.sprite);

    if (pos.y > 1080 || pos.y < 0) {
        game->player.position = (pos_t) {WORLD, 5, 0, 0, 0};
        game->player.face = SOUTH;
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {1159, 582});
    }
    if ((game->player.position.x == 1 && pos.x >= 1920) ||
    (game->player.position.x == 0 && pos.x <= 0)) {
        game->player.position = (pos_t) {WORLD, 5, 0, 0, 0};
        game->player.face = SOUTH;
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {1159, 582});
    }
    casefarwater(game);
}