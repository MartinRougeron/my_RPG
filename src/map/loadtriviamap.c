/*
** EPITECH PROJECT, 2020
** loadmap
** File description:
** trivia
*/

#include "my.h"

int filltriviamap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/triviamap/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[TRIVIATANFIGHT][i][y][z],
    MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

int housemap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/house/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[HOUSE][i][y][z],
    MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

void loadtriviamap(game_t *game)
{
    game->map.map[TRIVIATANFIGHT] = malloc(sizeof(int ****) * TRIVIAMAPY);
    for (int i = 0; i != TRIVIAMAPY; i++) {
        game->map.map[TRIVIATANFIGHT][i] = 
        malloc(sizeof(int ***) * TRIVIAMAPX);
        for (int y = 0; y != TRIVIAMAPX; y++) {
            game->map.map[TRIVIATANFIGHT][i][y] =
            malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[TRIVIATANFIGHT][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                filltriviamap(game, i, y, z);
            }
        }
    }
}

void loadhousemap(game_t *game)
{
    game->map.map[HOUSE] = malloc(sizeof(int ****) * HOUSEMAPY);
    for (int i = 0; i != HOUSEMAPY; i++) {
        game->map.map[HOUSE][i] = malloc(sizeof(int ***) * HOUSEMAPX);
        for (int y = 0; y != HOUSEMAPX; y++) {
            game->map.map[HOUSE][i][y] =
            malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[HOUSE][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                housemap(game, i, y, z);
            }
        }
    }
}