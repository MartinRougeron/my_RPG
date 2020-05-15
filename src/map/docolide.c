/*
** EPITECH PROJECT, 2020
** colide
** File description:
** colide
*/

#include "my.h"

void norm_docolidewithblock(sfVector2f pos, facing_t dir)
{
    if (dir == NORTH)
        pos.y += 20;
    if (dir == SOUTH)
        pos.y -= 20;
    if (dir == EST)
        pos.x += 20;
    if (dir == WEST)
        pos.x -= 20;
}

facing_t choosefacing(sfVector2f pos, sfVector2f posp)
{
    facing_t face;

    if (pos.x > posp.x)
        face = WEST;
    if (pos.x < posp.x)
        face = EST;
    if (pos.y > posp.y)
        face = SOUTH;
    if (pos.y < posp.y)
        face = NORTH;
    return face;
}

sfVector2f movevector(sfVector2f pos, facing_t dir)
{
    if (dir == NORTH)
        pos.y += 20;
    if (dir == SOUTH)
        pos.y -= 20;
    if (dir == EST)
        pos.x += 20;
    if (dir == WEST)
        pos.x -= 20;
    return pos;
}

sfVector2f docolidewithblock(game_t *game, sfVector2f pos, sfVector2f posp)
{
    facing_t dir = choosefacing(pos, posp);
    int tilesy = (int) roundf((pos.y + 33) / (1080 / MAPTILESY));
    int tilesx = (int) ((pos.x - 5) / (1920 / MAPTILESX));

    if (tilesy < 0 || tilesx < 0 || tilesy >= MAPTILESY || tilesx >= MAPTILESX)
        return pos;
    for (int i = 0; i != NBLAYER; i++)
        while ((containsint(game->map.map[game->player.position.map]
        [game->player.position.y]
        [game->player.position.x][i][tilesy][tilesx], game->nowalktiles))) {
            norm_docolidewithblock(pos, dir);
            pos = movevector(pos, dir);
            tilesy = (int) roundf((pos.y + 33) / (1080 / MAPTILESY));
            tilesx = (int) ((pos.x - 5) / (1920 / MAPTILESX));
            if (tilesy < 0 || tilesx < 0 || tilesy >= MAPTILESY
            || tilesx >= MAPTILESX)
                return pos;
        }
    return pos;
}
