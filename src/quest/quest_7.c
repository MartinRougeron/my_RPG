/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_7.c
*/

#include "my.h"

void quest_seven(game_t *game)
{
    int has_all = 0;
    static int first = 0;

    if  (game->player.inventory.item[INVENTORY_SIZE + ARTIFACT1].sprite != NULL
    && game->player.inventory.item[INVENTORY_SIZE + ARTIFCAT2].sprite != NULL
    && game->player.inventory.item[INVENTORY_SIZE + ARTIFACT3].sprite != NULL)
        has_all = 1;
    if (game->player.talking == -1)
        if (has_all && first++ == 0) {
            game->player.successmsg = "You can know go fight\n\nSahrotar"
            "at the volcano";
            game->all_quest[7] = BEGIN;
        }
}