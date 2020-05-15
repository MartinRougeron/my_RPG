/*
** EPITECH PROJECT, 2019
** task02
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int pos_dest = my_strlen(dest);
    char *to = malloc(sizeof(char) * (pos_dest + my_strlen(src) + 1));
    int i = 0;

    for (; dest[i] != '\0'; i++)
        to[i] = dest[i];
    for (int j = 0; src[j] != '\0'; i++, j++)
        to[i] = src[j];
    to[i++] = '\0';
    return (to);
}
