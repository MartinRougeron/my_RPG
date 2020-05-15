/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handlevelup
*/
#include "my.h"

void menu_lvl_up(game_t *game)
{
    if (game->screen == LEVELUP) {
        drawmap(game);
        animplayer(game);
        animpnj(game);
        drawpnj(game);
        anim_ennemy(game);
        sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
        changedirplayer(game, sfSprite_getTextureRect(game->player.sprite));
        animspell(game);
        enemy_life(game);
        magicshield(game);
        lightspell(game);
        print_life(game);
        levelupscreen(game);
        if (game->is_tuto == LVLUP)
            discover_levelup(game);
        drawsuccessmsg(game);
    }
}
