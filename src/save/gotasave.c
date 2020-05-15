/*
** EPITECH PROJECT, 2020
** save
** File description:
** got a save
*/

#include "my.h"

int got_a_save(void)
{
    FILE *fd = fopen("./.load/save.load", "r");

    if (!fd)
        return 0;
    fclose(fd);
    return 1;
}