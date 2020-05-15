/*
** EPITECH PROJECT, 2020
** util
** File description:
** contains
*/

#include "my.h"

int containsint(int block, int *list)
{
    for (int i = 0; list[i] != -1; i++)
        if (list[i] == block)
            return 1;
    return 0;
}