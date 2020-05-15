/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handinventory
*/

#include "my.h"

void menu_inventory(game_t *game)
{
    if (game->screen == INVENTORY) {
        drawmap(game);
        animplayer(game);
        animpnj(game);
        drawpnj(game);
        anim_ennemy(game);
        sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
        animspell(game);
        enemy_life(game);
        magicshield(game);
        lightspell(game);
        print_inventory(game);
        print_life(game);
        if (game->is_tuto == EQUIP_TUTO)
            discover_equip(game);
        drawsuccessmsg(game);
    }
}
