/*
** EPITECH PROJECT, 2020
** secondary
** File description:
** quest 0
*/

#include "my.h"

void quest_secondary_0(game_t *game)
{
    int id;

    if (game->player.talking == 27 && game->all_quest[NBQUEST] == NOT_BEGIN) {
        if (additem(game, game->pnj[27].quest.recompense))
            game->all_quest[NBQUEST] = BEGIN;
    }
    if (game->all_quest[NBQUEST] == BEGIN && game->player.talking == 26) {
        if ((id = gotitem(game, "Flower lot")) >= 0) {
            game->pnj[26].text = "Thanks you for the flowers";
            game->player.drop = (drop_t) {10, 15};
            game->player.inventory.item[id].sprite = NULL;
            game->all_quest[NBQUEST] = FINISH;
        } else {
            game->pnj[26].text = "You don't have the flowers";
        }
    }
}