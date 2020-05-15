/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** moves.c
*/

#include "my.h"

void move_up(game_t *game, float speed, int elapsed)
{
    if (isometric == 0)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {0, -speed * elapsed});
    else if (isometric == 1)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {(-speed/2 * elapsed) * 2, -speed/2 * elapsed});
}

void move_down(game_t *game, float speed, int elapsed)
{
    if (isometric == 0)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {0, speed * elapsed});
    else if (isometric == 1)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {speed/2 * elapsed * 2, speed/2 * elapsed});
}

void move_left(game_t *game, float speed, int elapsed)
{
    if (isometric == 0)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {-speed * elapsed, 0});
    else if (isometric == 1)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {-speed * elapsed, (speed/2 * elapsed)});
}

void move_right(game_t *game, float speed, int elapsed)
{
    if (isometric == 0)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {speed * elapsed, 0});
    else if (isometric == 1)
        sfSprite_move(game->player.sprite, (sfVector2f)
        {speed * elapsed, -(speed/2 * elapsed)});
}
