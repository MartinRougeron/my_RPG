/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse str
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    char char1;
    char char2;
    int size;

    for (size = 0; str[size] != '\0'; size++);
    for (int i = 0; i < size / 2; i++){
        char1 = str[i];
        char2 = str[size - 1 - i];
        str[i] = char2;
        str[size - 1 - i] = char1;
    }
    return (str);
}
