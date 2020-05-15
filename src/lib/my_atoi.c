/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str, int *err)
{
    int neg = (str[0] == '-') ? 1 : 0;
    int len;
    int res = 0;

    (str[0] == '-') ? str++ : 0;
    for (int i = 0; str[i] != 0; i++)
        if (str[i] > '9' || str[i] < '0')
            return -1;
    for (len = 0; str[len] != 0; len++);
    for (int i = 0; str[i] != 0; i++) {
        res += str[i] - 48;
        res *= 10;
    }
    *err = (neg == 1) ? -(res / 10) : res / 10;
    return 0;
}