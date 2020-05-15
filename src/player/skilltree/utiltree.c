/*
** EPITECH PROJECT, 2020
** tree
** File description:
** util
*/

#include "my.h"

int gottheskill(int *tab, int nbr)
{
    for (int i = 0; i != NBSKILL; i++)
        if (tab[i] == nbr)
            return 1;
    return 0;
}

int gotdependence(int *dependence, int *unlocked)
{
    for (int i = 0; i != NBSKILL && dependence[i] != -1; i++) {
        if (!gottheskill(unlocked, dependence[i]))
            return 0;
    }
    return 1;
}

int addskill(game_t *game, int y)
{
    for (int i = 0; i != NBSKILL; i++)
        if (game->player.tree.unlocked[i] == -1) {
            game->player.tree.unlocked[i] = y;
            return 1;
        }
    return 0;
}