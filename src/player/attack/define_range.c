/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** define_range.c
*/

#include "my.h"

sfFloatRect range_player(game_t *game)
{
    sfFloatRect range = {sfSprite_getPosition(game->player.sprite).x - 42,
    sfSprite_getPosition(game->player.sprite).y - 40, 128 , 128};
    range.height -= 44;
    range.width -= 44;
    range.top -= (game->player.face == NORTH) * 50;
    range.top += (game->player.face == SOUTH) * 50;
    range.left -= (game->player.face == EST) * 50;
    range.left += (game->player.face == WEST) * 50;
    return (range);
}