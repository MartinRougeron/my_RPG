/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handskilltree
*/

#include "my.h"

void menu_skill_tree(game_t *game)
{
    if (game->screen == SKILLTREE) {
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
        print_life(game);
        inmenutree(game);
    }
}
