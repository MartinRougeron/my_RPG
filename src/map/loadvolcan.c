/*
** EPITECH PROJECT, 2020
** map load
** File description:
** map load
*/

#include "my.h"

int volcanmap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/dragon/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[VOLCAN][i][y][z],
    MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

void loadvolcan(game_t *game)
{
    game->map.map[VOLCAN] = malloc(sizeof(int ****) * 1);
    for (int i = 0; i != 1; i++) {
        game->map.map[VOLCAN][i] = malloc(sizeof(int ***) * 1);
        for (int y = 0; y != 1; y++) {
            game->map.map[VOLCAN][i][y] =
            malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[VOLCAN][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                volcanmap(game, i, y, z);
            }
        }
    }
}