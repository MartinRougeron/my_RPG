/*
** EPITECH PROJECT, 2020
** hair
** File description:
** hair
*/

#include "my.h"

void playconfirmsave(game_t *game)
{
    if (game->player.inventory.gold < 20) {
        drawerrormsg((sfColor) {255, 0, 0, 255},
        "Not enough gold", game->window, 70);
        return;
    }
    game->player.inventory.gold -= 20;
    savegame(game);
}

void savepnj(game_t *game)
{
    static int first = 0;

    if (game->player.successmsg == NULL && first == 0) {
        game->player.successmsg = "Do you want to\n\nSave your game\n\nFor "
        "only"
        "20 golds\n\n\n\nNote: You can load your\nsave in the title screen";
        first = 1;
    }
    if (game->player.successmsg == NULL) {
        game->player.talking = -1;
        first = 0;
        if (draw_confirm(game)) {
            playconfirmsave(game);
        }
    }
}

void playconfirm(game_t *game)
{
    if (game->player.inventory.gold < 5) {
        drawerrormsg((sfColor) {255, 0, 0, 255},
        "Not enough gold", game->window, 70);
        return;
    }
    game->player.color += 1;
    game->player.inventory.gold -= 5;
    if (game->player.color >= 6)
        game->player.color = 0;
}

void hairpnj(game_t *game)
{
    static int first = 0;

    if (game->player.successmsg == NULL && first == 0) {
        game->player.successmsg = "Do you want to\n\nChange your hair\n\nS"
        "tyle for 5 gold";
        first = 1;
    }
    if (game->player.successmsg == NULL) {
        game->player.talking = -1;
        first = 0;
        if (draw_confirm(game)) {
            playconfirm(game);
        }
    }
}
