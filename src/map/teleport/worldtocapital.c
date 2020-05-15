/*
** EPITECH PROJECT, 2020
** tp
** File description:
** world > capital
*/

#include "my.h"

void worldtocapital(game_t *game)
{
    int tiles;
    sfVector2f posact;
    int x, y;

    if (!samemap(game->player.position, (pos_t) {WORLD, 0, 2, 0, 0}))
        return;
    posact = sfSprite_getPosition(game->player.sprite);
    y = (int) roundf((posact.y + 33) / (1080 / MAPTILESY));
    x = (int) ((posact.x - 5) / (1920 / MAPTILESX));
    if (x < 0 || x >= MAPTILESX || y < 0 || y >= MAPTILESY)
        return;
    tiles = game->map.map[game->player.position.map]
    [game->player.position.y][game->player.position.x][1][y][x];
    if ((tiles >= 303 && tiles <= 306) || (tiles >= 336 && tiles <= 339) ||
    (tiles >= 369 && tiles <= 372) || (tiles >= 402 && tiles <= 405)) {
        game->player.position = (pos_t) {CAPITAL, 0, 1, 0, 0};
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {995, 927});
        game->player.face = NORTH;
        destroy_enemie(game);
    }
}

void capitaltoworld(game_t *game)
{
    if (!samemap(game->player.position, (pos_t) {CAPITAL, 0, 1, 0, 0}))
        return;
    if (isaround_vector(sfSprite_getGlobalBounds(game->player.sprite),
    (sfVector2f) {992, 1062}, 30)) {
        game->player.position = (pos_t) {WORLD, 0, 2, 0, 0};
        game->player.face = WEST;
        sfSprite_setPosition(game->player.sprite, (sfVector2f) {632, 559});
    }
}

void processteleport(game_t *game)
{
    worldtocapital(game);
    capitaltoworld(game);
    saxontoworld(game);
    worldtosaxon(game);
    fantometoworld(game);
    worldtofantome(game);
    fartoworld(game);
    worldtofar(game);
    worldtovolcan(game);
}