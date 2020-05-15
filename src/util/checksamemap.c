/*
** EPITECH PROJECT, 2020
** uutil
** File description:
** check same map
*/

#include "my.h"

int samemap(pos_t tab1, pos_t tab2)
{
    if (tab1.x == tab2.x && tab1.y == tab2.y && tab1.map == tab2.map)
        return 1;
    return 0;
}