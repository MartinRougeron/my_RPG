/*
** EPITECH PROJECT, 2020
** quest
** File description:
** quest
*/

#include "my.h"

int *getactualquest(game_t *game, int *nb)
{
    int *res = malloc(sizeof(int) * (NBQUEST + NBSECONDARY + 1));

    for (int i = 0; i != NBQUEST + NBSECONDARY; i++)
        res[i] = -1;
    for (int i = 0, y = 0; i != NBQUEST + NBSECONDARY; i++) {
        if (game->all_quest[i] == BEGIN) {
            res[y++] = i;
            *nb += 1;
        }
    }
    return res;
}