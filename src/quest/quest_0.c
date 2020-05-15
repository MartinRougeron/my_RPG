/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_0.c
*/

#include "my.h"

void quest_zero(game_t *game)
{
    static int first = 0;

    if (game->all_quest[0] == BEGIN &&
    game->player.position.map == CAPITAL) {
        game->player.successmsg = "You just reach Hilford\n\n"
        "The capital of the Kingdom\n\nYou should talk to the pnj";
        game->all_quest[11] = BEGIN;
        game->all_quest[0] = FINISH;
    }
    if (game->player.talking == 18 && game->all_quest[11] == BEGIN) {
        game->all_quest[11] = FINISH;
        game->all_quest[1] = BEGIN;
    }
    if (game->player.talking == -1 && game->all_quest[11] == FINISH &&
    game->all_quest[1] == BEGIN && !first) {
        first = 1;
        game->player.successmsg = "Go at west of Saxon Dale\n\nto learn magic";
    }
}