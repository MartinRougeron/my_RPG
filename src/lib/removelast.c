/*
** EPITECH PROJECT, 2020
** lib
** File description:
** r
*/

#include "my.h"

void removebackn(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == '\n')
            str[i] = 0;
}