/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_3.c
*/

#include "my.h"

void quest_three_action(game_t *game)
{
    for (int i = 0; i != INVENTORY_SIZE; i++) {
        if (getitem[i].sprite == NULL)
            continue;
        if (!my_strncmp(game->player.inventory.item[i].name, "Fish", 4))
            game->player.inventory.item[i].sprite = NULL;
    }
    game->player.successmsg = "You brought the fish back\n\nto the capital\n\n"
    "Go back see the fishman\n\nQuest updated";
    game->pnj[7].text = "Triviatan have the amulette, "
    "do you want to fight him ?";
    game->all_quest[10] = BEGIN;
}

void quest_three(game_t *game)
{
    sfVector2f posact = sfSprite_getPosition(game->player.sprite);
    int tilesy = (int) roundf((posact.y + 33) / (1080 / MAPTILESY));
    int tilesx = (int) ((posact.x - 5) / (1920 / MAPTILESX));

    tilesy = (tilesy < 0) ? 0 : tilesy;
    tilesy = (tilesy >= MAPTILESY) ? MAPTILESY - 1 : tilesy;
    tilesx = (tilesx < 0) ? 0 : tilesx;
    tilesx = (tilesx >= MAPTILESX) ? MAPTILESX - 1 : tilesx;
    if (game->all_quest[3] == BEGIN && game->player.talking == 7) {
        additem(game, game->pnj[7].quest.recompense);
        game->all_quest[9] = BEGIN;
        game->all_quest[3] = FINISH;
    }
    if (game->all_quest[9] == BEGIN &&
    (game->player.position.map == CAPITAL)) {
        quest_three_action(game);
        game->all_quest[9] = FINISH;
    }
}