/*
** EPITECH PROJECT, 2020
** getnbr
** File description:
** getnbr
*/

#include "my.h"

char *my_strncpy(char const *src, int n)
{
    int i = 0;
    char *cpy = malloc(n + 1);

    if (src == NULL)
        return (NULL);
    for (; src[i] != 0 && i < n; i++)
        cpy[i] = src[i];
    cpy[i] = '\0';
    return cpy;
}

bool test_if_num(char c)
{
    return c >= '0' && c <= '9' ? TRUE : FALSE;
}

int my_getnbr(char const *str)
{
    int neg = 0;
    long res = 0;
    int result = 0;

    if (str == NULL || str[0] == '\0')
        return 0;
    for (int i = 0; str[i]; i++) {
        neg = str[i] == '-' ? neg + 1 : neg;
        if (!(test_if_num(str[i])) && res != 0)
            break;
        else if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + str[i] - 48;
    }
    result = (int)res;
    if (result != res)
        return 0;
    result = neg % 2 == 1 ? -result : result;
    return result;
}