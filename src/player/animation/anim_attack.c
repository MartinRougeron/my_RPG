/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** anim_attack.c
*/

#include "my.h"

void anim_player_attack(game_t *game, sfIntRect rect)
{
    sfFloatRect range = range_player(game);

    rect.left = 0;
    rect.top = 144 * 2;
    game->player.state = IDLE;
    detect_matching_range(game, range);
    sfSprite_setTextureRect(game->player.sprite, rect);
}