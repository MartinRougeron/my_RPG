/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** dup
*/

#include "my.h"

char *my_strdup(char *str)
{
    char *res = malloc(my_strlen(str) + 1);
    int i = 0;

    for (i = 0; str[i] != 0; i++)
        res[i] = str[i];
    res[i] = 0;
    return res;
}