/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** take_damage.c
*/

#include "my.h"

void damage_show_e(game_t *game, int i)
{
    if (TIME(game->damage.text_c[i]) < 600) {
        if (TIME(game->damage.text_c[i]) < 200)
            sfText_setColor(game->damage.text[i], sfRed);
        if (TIME(game->damage.text_c[i]) > 350)
            sfText_setColor(game->damage.text[i],
            (sfColor) {254, 150, 160, 255});
        if (TIME(game->damage.text_c[i]) > 500)
            sfText_setColor(game->damage.text[i], sfWhite);
        sfText_setCharacterSize(game->damage.text[i], 20);
        sfRenderWindow_drawText(game->window,
        game->damage.text[i], NULL);
    } else {
        sfText_destroy(game->damage.text[i]);
        game->damage.text[i] = NULL;
        sfClock_destroy(game->damage.text_c[i]);
    }
}

void damage_ennemie_show(game_t *game)
{
    for (int i = 0; i < NBMAXENEMIE; i++) {
        if (game->damage.text[i] == NULL)
            continue;
        if (game->damage.text[i] != NULL) {
            damage_show_e(game, i);
        }
    }
}
