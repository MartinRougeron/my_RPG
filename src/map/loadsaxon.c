/*
** EPITECH PROJECT, 2020
** loadmap
** File description:
** trivia
*/

#include "my.h"

int fantomemap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/ville_fantome/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[FANTOME][i][y][z],
    MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

void loadfantome(game_t *game)
{
    game->map.map[FANTOME] = malloc(sizeof(int ****) * 1);
    for (int i = 0; i != 1; i++) {
        game->map.map[FANTOME][i] = malloc(sizeof(int ***) * 1);
        for (int y = 0; y != 1; y++) {
            game->map.map[FANTOME][i][y] =
            malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[FANTOME][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                fantomemap(game, i, y, z);
            }
        }
    }
}

int saxonmap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/saxon/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[SAXON][i][y][z],
    MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

void loadsaxonmap(game_t *game)
{
    game->map.map[SAXON] = malloc(sizeof(int ****) * SAXONMAXY);
    for (int i = 0; i != SAXONMAXY; i++) {
        game->map.map[SAXON][i] = malloc(sizeof(int ***) * SAXONMAXX);
        for (int y = 0; y != SAXONMAXX; y++) {
            game->map.map[SAXON][i][y] =
            malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[SAXON][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                saxonmap(game, i, y, z);
            }
        }
    }
}