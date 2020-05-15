/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handpause
*/

#include "my.h"

void menu_pause(game_t *game)
{
    if (game->screen == PAUSE) {
        drawmap(game);
        animplayer(game);
        animpnj(game);
        drawpnj(game);
        anim_ennemy(game);
        animspell(game);
        enemy_life(game);
        magicshield(game);
        lightspell(game);
        print_life(game);
        print_pause(game);
    }
}
