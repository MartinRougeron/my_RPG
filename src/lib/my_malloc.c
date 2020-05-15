/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** malloc
*/

#include "my.h"

char *my_malloc(int size)
{
    char *res = malloc(size);

    for (int i = 0; i != size; i++)
        res[i] = 0;
    return res;
}