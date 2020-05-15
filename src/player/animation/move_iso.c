/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_iso.c
*/

#include "my.h"

void move_iso(game_t *game, int i)
{
    if (game->enemie[i].face == NORTH && isometric)
        sfSprite_move(game->enemie[i].sprite, (sfVector2f) {(-4/2)*2, -4/2});
    if (game->enemie[i].face == SOUTH && isometric)
        sfSprite_move(game->enemie[i].sprite, (sfVector2f) {4/2 * 2, 4/2});
    if (game->enemie[i].face == EST && isometric)
        sfSprite_move(game->enemie[i].sprite, (sfVector2f) {-4, (4/2)});
    if (game->enemie[i].face == WEST && isometric)
        sfSprite_move(game->enemie[i].sprite, (sfVector2f) {4, -(4/2)});
}