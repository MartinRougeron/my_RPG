/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handkey
*/

#include "my.h"

void menu_key(game_t *game)
{
    if (game->screen == KEY) {
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
        sfRenderWindow_drawRectangleShape(game->window,
        game->menu.menu_st.rectang, NULL);
        sfRenderWindow_drawText(game->window, game->menu.menu_st.t_key, NULL);
    }
}
