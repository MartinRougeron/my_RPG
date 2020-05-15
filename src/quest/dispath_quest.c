/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** dispath_quest.c
*/

#include "my.h"

void quest_secondary_2(game_t *game)
{
    static int has = 0;
    static int has_ = 0;

    if (game->all_quest[NBQUEST + 2] == FINISH) return;
    if (!has)
        if (game->player.talking == 50 && game->nbkill >= 10)
            has = 1;
    if (game->player.talking == 50 && game->all_quest[NBQUEST + 2] == 0)
        game->all_quest[NBQUEST + 2] = BEGIN;
    if (game->all_quest[NBQUEST + 2] == BEGIN && game->nbkill >= 10 && !has_++){
        game->player.successmsg = "New objective !";
        game->quest_description[NBQUEST + 2] = "Go back see the magician";
    }
    if (has)
        game->pnj[50].text = "Thanks a lot";
    if (has && game->player.talking == -1) {
        game->player.mage.unlocked += 1;
        game->player.successmsg = "You learn shield spell";
        game->all_quest[NBQUEST + 2] = FINISH;
    }
}

void quest_all(game_t *game)
{
    quest_zero(game);
    quest_one(game);
    quest_two(game);
    quest_three(game);
    quest_four(game);
    quest_five(game);
    quest_six(game);
    quest_seven(game);
    quest_secondary_0(game);
    quest_secondary_2(game);
}