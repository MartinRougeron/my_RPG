/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_1.c
*/

#include "my.h"

void quest_one(game_t *game)
{
    if (game->all_quest[1] == BEGIN && game->player.talking == 4) {
        game->player.learnmagic = 1;
        game->player.mage.unlocked += 1;
        game->player.stance = RANGE;
        game->player.mage.select = 0;
        game->player.successmsg = my_strcat("You learn fireball\n\n"
        "Try with this ennemy\n\nSwitch between\n\nmelee and magician\n\n"
        "with key", my_strcat(game->menu.key_st.c_changestance,
        "\nQuest updated"));
        loadenemie(game, (enemieoption_t) {(drop_t) {1, 1},
        (pos_t) {WORLD, 1, 1, 25, 25}, 0, 0, 5});
        game->all_quest[1] = FINISH;
        game->all_quest[2] = BEGIN;
    }
}