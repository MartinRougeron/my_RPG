/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_main_next.c
*/

#include "my.h"

void load_ennemy(game_t *game)
{
    game->loadedenemie = loadbasicenemie();
    game->weather = SHINE;
    game->weatherclock = sfClock_create();
    game->font.menu = sfFont_createFromFile("assets/menu.ttf");
}
