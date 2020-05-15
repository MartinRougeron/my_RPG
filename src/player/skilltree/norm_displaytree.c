/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** norm_displaytree
*/

#include "my.h"

void displaytree_r(game_t *game, sfText *text, sfText *nb)
{
    sfRenderWindow_drawText(game->window, text, NULL);
    sfRenderWindow_drawText(game->window, nb, NULL);
    sfText_destroy(text);
    sfText_destroy(nb);
    drawskill(game);
}