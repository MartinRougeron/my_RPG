/*
** EPITECH PROJECT, 2020
** "far
** File description:
** water
*/

#include "my.h"

int watermap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/far_water/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[FARWATER][i][y][z],
    MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

void loadwatermap(game_t *game)
{
    game->map.map[FARWATER] = malloc(sizeof(int ****) * SAXONMAXY);
    for (int i = 0; i != SAXONMAXY; i++) {
        game->map.map[FARWATER][i] = malloc(sizeof(int ***) * SAXONMAXX);
        for (int y = 0; y != SAXONMAXX; y++) {
            game->map.map[FARWATER][i][y] =
            malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[FARWATER][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                watermap(game, i, y, z);
            }
        }
    }
}