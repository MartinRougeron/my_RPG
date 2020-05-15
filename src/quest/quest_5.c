/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_5.c
*/

#include "my.h"

void quest_five(game_t *game)
{
    if (game->all_quest[5] == BEGIN && game->player.position.map == FARWATER) {
        game->player.successmsg = "You get an amulette";
        drawsuccessmsg(game);
        additem(game,  create_item((char *[]) {"Fire amulet", "+10 health",
        "assets/amulettes/amulette2.png"}, ARMORNONE, ARTIFCAT2,
        (itemstat_t) {0, 10, 0, 0, 0}));
        game->all_quest[5] = FINISH;
        game->all_quest[NBQUEST + 1] = BEGIN;
    }
}