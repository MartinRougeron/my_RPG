/*
** EPITECH PROJECT, 2020
** map
** File description:
** util
*/

#include "my.h"

sfVector2f convertpos(pos_t pos)
{
    sfVector2f res = {pos.onmapx * (WIDTH / MAPTILESX),
    pos.onmapy * (HEIGHT / MAPTILESY)};

    return res;
}