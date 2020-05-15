/*
** EPITECH PROJECT, 2020
** outline
** File description:
** load quest
*/

#include "my.h"

char *loadquest(game_t *game, char *str)
{
    int i = 0;

    for (int y = 0; y != NBQUEST + NBSECONDARY; y++) {
        for (i = 0; str[i] != ','; i++);
        game->all_quest[y] = my_getnbr(my_strncpy(str, i));
        str += i + 1;
    }
    return str;
}