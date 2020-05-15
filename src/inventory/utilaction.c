/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** action util
*/

#include "my.h"

action_t *initaction(itemtype_t type)
{
    action_t *action = malloc(sizeof(action_t) * MAXACTION);

    for (int i = 0; i != MAXACTION; i++)
        action[i] = NONE;
    if (type == AMULETTE || type == SWORD || type == HELMET ||
    type == CHESTPLATE || type == LEGGINGS || type == BOOTS)
        for (int i = 0; i != MAXACTION; i++)
            action[i] = ACTIONSWORD[i];
    if (type == ARTIFACT1 ||
    type == ARTIFCAT2 || type == ARTIFACT3)
        for (int i = 0; i != MAXACTION; i++)
            action[i] = ACTIONAMUQUEST[i];
    if (type == POTION)
        for (int i = 0; i != MAXACTION; i++)
            action[i] = ACTIONPOTION[i];
    if (type == EQUIPED)
        for (int i = 0; i != MAXACTION; i++)
            action[i] = ACTIONUNEQUP[i];
    return action;
}

int getnbaction(game_t *game, int index)
{
    for (int i = 0; i != MAXACTION; i++)
        if (getitem[index].action[i] == NONE)
            return ((i == 0) ? 1 : i);
    return MAXACTION;
}