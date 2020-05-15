/*
** EPITECH PROJECT, 2020
** map
** File description:
** loadmap
*/

#include "my.h"

FILE *getfile(int y, int x, int z, char *str)
{
    char *path = my_strcat(str, my_strcat(my_itoa(z),
    my_strcat("-", my_strcat(my_itoa(y), my_strcat("-", my_itoa(x))))));
    FILE *fd = fopen(path, "r");

    if (fd == NULL) {
        return fd;
    }
    return fd;
}

char *processmaprecup(char *s, int **map, char *act, sfVector2i pt)
{
    for (int z = 0, w = 0; s[z] != 0; z++) {
        if (s[z] == ',') {
            map[pt.x][pt.y++] = atoi(act);
            free(act);
            act = my_malloc(10);
            w = 0;
        } else
            act[w++] = s[z];
    }
    return act;
}

int getmap(FILE *fd, int **map, int maxy, int maxx)
{
    char *act = my_malloc(10);
    char *s = NULL;
    size_t n = 0;

    getline(&s, &n, fd);
    for (int i = 0, y = 0; i != maxy; i++, y = 0) {
        map[i] = malloc(sizeof(int) * maxx);
        if (s == NULL)
            return -1;
        act = processmaprecup(s, map, act, (sfVector2i) {i, y});
        free(s);
        s = NULL;
        getline(&s, &n, fd);
    }
    fclose(fd);
    return 1;
}

int fillmap(game_t *game, int i, int y, int z)
{
    FILE *fd;

    fd = getfile(i, y, z, "./assets/map/world/");
    if (fd == NULL)
        return -1;
    if (getmap(fd, game->map.map[WORLD][i][y][z], MAPTILESY, MAPTILESX) == -1)
        return -1;
    return 1;
}

int loadmap(game_t *game)
{
    game->map.map = malloc(sizeof(int *****) * NBWORLD);
    game->map.map[WORLD] = malloc(sizeof(int ****) * MAPMAXY);
    for (int i = 0; i != MAPMAXY; i++) {
        game->map.map[WORLD][i] = malloc(sizeof(int ***) * MAPMAXX);
        for (int y = 0; y != MAPMAXX; y++) {
            game->map.map[WORLD][i][y] = malloc(sizeof(int **) * NBLAYER);
            for (int z = 0; z != NBLAYER; z++) {
                game->map.map[WORLD][i][y][z] =
                malloc(sizeof(int *) * MAPTILESY);
                fillmap(game, i, y, z);
            }
        }
    }
    return 1;
}
