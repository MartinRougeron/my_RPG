/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_6.c
*/

#include "my.h"

void script_chest(game_t *game)
{
    if (game->player.talking == 25 && game->all_quest[8] == BEGIN) {
        additem(game, game->pnj[25].quest.recompense);
        game->player.successmsg = "You recieve jewelery !";
        loadenemie(game, (enemieoption_t) {(drop_t) {2, 2},
        (pos_t) {WORLD, 2, 3, 10, 15}, 1, 10, 30});
        loadenemie(game, (enemieoption_t) {(drop_t) {2, 2},
        (pos_t) {WORLD, 2, 3, 15, 10}, 1, 10, 30});
        loadenemie(game, (enemieoption_t) {(drop_t) {2, 2},
        (pos_t) {WORLD, 2, 3, 20, 15}, 1, 10, 30});
        loadenemie(game, (enemieoption_t) {(drop_t) {2, 2},
        (pos_t) {WORLD, 2, 3, 15, 20}, 1, 10, 30});
        game->all_quest[8] = FINISH;
    }
}

void quest_six_action(game_t *game, int has)
{
    static int first = 0;

    if (game->all_quest[6] == BEGIN && game->all_quest[8] != FINISH
    && game->player.talking == -1 && !first) {
        game->player.successmsg = "Go find the Jewlerie\n\nin the Lost City!";
        first = 1;
    }
    if (game->player.talking == 24 && game->all_quest[6] == BEGIN && has) {
        game->player.successmsg = "You get the third amulette!\n\nEquip now the three amulet";
        game->pnj[24].text = "Thanks you warrior";
        for (int i = 0; i <= INVENTORY_SIZE + AMULETTE; i++) {
            if (game->player.inventory.item[i].sprite == NULL)
                continue;
            if (!my_strncmp(getitem[i].name, "Jewelery stolen", 9))
                getitem[i].sprite = NULL;
        }
        additem(game, game->pnj[24].quest.recompense);
        game->all_quest[6] = FINISH;
    } if (game->all_quest[8] == BEGIN && game->player.talking == 25)
        script_chest(game);
    return;
}

void msg_player(game_t *game)
{
    if (game->all_quest[6] == NOT_BEGIN && game->player.talking == 24) {
        game->all_quest[6] = BEGIN;
        game->pnj[24].text = "I see you're a warrior"
        "I have the a misssion for you, Take my family's jewelry, it's"
        "in the Lost City";
        game->all_quest[8] = BEGIN;
        game->all_quest[NBQUEST + 1] = FINISH;
    } else if (game->all_quest[6] == NOT_BEGIN
    && game->player.talking == 24 && game->all_quest[5] != FINISH)
        game->pnj[24].text = "Go back when you defeted Trivitant";
}

void quest_six(game_t *game)
{
    int has = 0;

    for (int i = 0; i <= INVENTORY_SIZE + AMULETTE; i++) {
        if (game->player.inventory.item[i].sprite == NULL)
            continue;
        if (!my_strncmp(game->player.inventory.item[i].name, "Jewelery Stolen", 9))
            has = 1;
    }
    msg_player(game);
    quest_six_action(game, has);
}
