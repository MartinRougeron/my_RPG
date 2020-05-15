/*
** EPITECH PROJECT, 2020
** tp
** File description:
** world > capital
*/

#include "my.h"

void worldtosaxon(game_t *game)
{
    int tiles;
    sfVector2f posact;
    int x, y;

    if (!samemap(game->player.position, (pos_t) {WORLD, 3, 0, 0, 0}))
        return;
    posact = sfSprite_getPosition(game->player.sprite);
    y = (int) roundf((posact.y + 33) / (1080 / MAPTILESY));
    x = (int) ((posact.x - 5) / (1920 / MAPTILESX));
    if (x < 0 || x >= MAPTILESX || y < 0 || y >= MAPTILESY)
        return;
    tiles = game->map.map[game->player.position.map]
    [game->player.position.y][game->player.position.x][1][y][x];
    if ((tiles >= 237 && tiles <= 240) || (tiles >= 270 && tiles <= 273)) {
        game->player.position = (pos_t) {SAXON, 0, 0, 0, 0};
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {995, 927});
        game->player.face = NORTH;
        destroy_enemie(game);
    }
}

void saxontoworld(game_t *game)
{
    if (!samemap(game->player.position, (pos_t) {SAXON, 0, 0, 0, 0}))
        return;
    if (isaround_vector(sfSprite_getGlobalBounds(game->player.sprite),
    (sfVector2f) {992, 1062}, 30)) {
        game->player.position = (pos_t) {WORLD, 3, 0, 0, 0};
        game->player.face = SOUTH;
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {960, 250});
    }
}

void worldtofantome(game_t *game)
{
    int tiles;
    sfVector2f posact;
    int x, y;

    if (!samemap(game->player.position, (pos_t) {WORLD, 4, 2, 0, 0}))
        return;
    posact = sfSprite_getPosition(game->player.sprite);
    y = (int) roundf((posact.y + 33) / (1080 / MAPTILESY));
    x = (int) ((posact.x - 5) / (1920 / MAPTILESX));
    if (x < 0 || x >= MAPTILESX || y < 0 || y >= MAPTILESY)
        return;
    tiles = game->map.map[game->player.position.map]
    [game->player.position.y][game->player.position.x][1][y][x];
    if ((tiles >= 225 && tiles <= 226) || (tiles >= 258 && tiles <= 259)) {
        game->player.position = (pos_t) {FANTOME, 0, 0, 0, 0};
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {995, 927});
        game->player.face = NORTH;
        destroy_enemie(game);
    }
}

void fantometoworld(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player.sprite);

    if (!samemap(game->player.position, (pos_t) {FANTOME, 0, 0, 0, 0}))
        return;
    if (pos.x >= 1920 || pos.x < 0 || pos.y > 1080 || pos.y < 0) {
        game->player.position = (pos_t) {WORLD, 4, 2, 0, 0};
        game->player.face = SOUTH;
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {1300, 600});
    }
}