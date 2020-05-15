/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_2.c
*/

#include "my.h"

void quest_two(game_t *game)
{
    static int talk = 0;

    if (game->player.talking == 6 && game->all_quest[2] == BEGIN)
        talk = 1;
    if (game->all_quest[2] == BEGIN && game->player.talking == -1 && talk) {
        game->player.mage.unlocked += 1;
        game->player.stance = RANGE;
        game->player.mage.select = 1;
        game->player.successmsg = my_strcat("You get an amulette and\n\n"
        "you learn iceball!\n\n Try with this ennemy\n\nSwitch spells\n\n"
        "with key", game->menu.key_st.c_changespell);
        additem(game, game->pnj[6].quest.recompense);
        loadenemie(game, (enemieoption_t) {(drop_t) {1, 1},
        (pos_t) {WORLD, 1, 1, 25, 25}, 0, 0, 5});
        game->all_quest[2] = FINISH;
        game->all_quest[3] = BEGIN;
    }
}