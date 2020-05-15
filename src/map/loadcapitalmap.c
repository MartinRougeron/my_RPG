/*
** EPITECH PROJECT, 2020
** loadmap
** File description:
** trivia
*/

#include "my.h"

int capitalmap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/capital/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[CAPITAL][i][y][z],
    MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

void loadcapitalmap(game_t *game)
{
    game->map.map[CAPITAL] = malloc(sizeof(int ****) * CAPITALMAXY);
    for (int i = 0; i != CAPITALMAXY; i++) {
        game->map.map[CAPITAL][i] = malloc(sizeof(int ***) * CAPITALMAXX);
        for (int y = 0; y != CAPITALMAXX; y++) {
            game->map.map[CAPITAL][i][y] =
            malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[CAPITAL][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                capitalmap(game, i, y, z);
            }
        }
    }
}