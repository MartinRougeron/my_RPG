/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rm_skills.c
*/

#include "my.h"

void rm_skills(game_t *game)
{
    for (int i = 0; i < NBSKILL; i++) {
        if (game->player.tree.unlocked[i] != -1)
            game->player.tree.point += 1;
        game->player.tree.unlocked[i] = -1;
    }
}
