/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_square
*/

#include "my.h"

void rec_for_color(game_t *game)
{
    sfRectangleShape *rec_for_color;
    sfColor col = sfColor_fromRGBA(0, 0, 0, 160);

    rec_for_color = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rec_for_color, col);
    sfRectangleShape_setSize(rec_for_color, (sfVector2f) {2048, 2048});
    sfRectangleShape_setPosition(rec_for_color, (sfVector2f) {0, 0});
    game->menu.menu_st.rectang = rec_for_color;
}