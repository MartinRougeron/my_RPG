/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** discover_taste_of_killing.c
*/

#include "my.h"

void discover_kill(game_t *game)
{
    static int is_kill = 0;
    static int first = 0;

    if (first++ == 0) {
        game->player.successmsg = my_strcat("Kill this enemie\n\nKey ",
        my_strcat(game->menu.key_st.c_attack, " to attack"));
        loadenemie(game, (enemieoption_t) {(drop_t) {10, 15},
        (pos_t) {WORLD, 3, 4, 18, 15}, 0, 0, 5});
    }
    if (game->enemie[0].health <= 0)
        is_kill = 1;
    if (is_kill) {
        game->is_tuto = BUY;
    }
}

void discover_shop(game_t *game)
{
    static int first = 0;

    if (first++ == 0) {
        game->player.successmsg = "With the gold,\n\nYou can go shopping\n\n"
        "to the green guy";
        drawsuccessmsg(game);
    }
    if (game->player.inventory.gold < 10) {
        game->is_tuto = INV;
    }
}

void discover_equip(game_t *game)
{
    static int first = 0;

    if (first++ == 0) {
        game->player.successmsg = "Right click or\n\nPress enter key\n\n"
        "on the item\n\nEquip it";
        drawsuccessmsg(game);
    }
    if (game->player.inventory.item[0].sprite == NULL) {
        game->screen = GAME;
        game->is_tuto = ZOOM;
    }
}

void discover_inventory(game_t *game)
{
    static int first = 0;
    static int first_ = 0;

    if (first++ == 0)
        game->player.successmsg = "Quit the shop with\n\nEchap key";
    if (game->player.talking == -1 && first_++ == 0) {
        game->player.successmsg = my_strcat("Open inventory with\n\nKey ",
        game->menu.key_st.c_inventory);
        game->is_tuto = EQUIP_TUTO;
    }
}

void discover_zoom(game_t *game)
{
    static int first = 0;

    if (first++ == 0) {
        game->player.successmsg =
        "You can zoom\n\nUsing :\n\nCTRL + Mouse Wheel\n\n"
        "to see how cool\n\nyour amor is";
    }
}
