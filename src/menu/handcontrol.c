/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handcontrol
*/

#include "my.h"

void menu_control(game_t *game)
{
    if (game->screen == CONTROL) {
        drawmap(game);
        animplayer(game);
        animpnj(game);
        drawpnj(game);
        anim_ennemy(game);
        animspell(game);
        enemy_life(game);
        magicshield(game);
        lightspell(game);
        sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
        print_life(game);
        print_control(game);
    }
}
