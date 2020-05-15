/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_4.c
*/

#include "my.h"

void quest_four(game_t *game)
{
    if (game->all_quest[10] == BEGIN && game->player.talking == 7) {
        game->all_quest[4] = BEGIN;
        game->all_quest[10] = FINISH;
    }
    if (game->player.talking == -1 && game->all_quest[4] == BEGIN) {
        if (draw_confirm(game)) {
            game->player.position.map = TRIVIATANFIGHT;
            game->player.position.y = 0;
            game->player.position.x = 0;
            game->player.successmsg = "You has been telepoted to\n\nTriviatan";
            game->all_quest[4] = FINISH;
        } else
            game->all_quest[4] = NOT_BEGIN;
    }
}