/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** call_buttons.c
*/

#include "my.h"

void put_button(game_t *game)
{
    game->menu.buttom_play_black =
    loadbutton("assets/menu/buttom/play_black2.png",
    (sfVector2f) {0.62, 0.62}, (sfVector2f) {168, 700});
    game->menu.fond =
    loadbutton("assets/menu/titlescreen/fond.jpg",
    (sfVector2f) {1.5, 1.5}, (sfVector2f) {0, 0});
    game->menu.parchemin =
    loadbutton("assets/menu/titlescreen/parchemin5.png",
    (sfVector2f) {0.6, 0.9}, (sfVector2f) {-15, 500});
    game->menu.parchment =
    loadbutton("assets/menu/titlescreen/Parchment.png",
    (sfVector2f) {1.3, 1.2}, (sfVector2f) {500, -1350});
    game->menu.menu_pl.parchments =
    loadbutton("assets/menu/titlescreen/Parchment.png",
    (sfVector2f) {1.3, 1.2}, (sfVector2f) {500, -1350});
    LOAD_MENU.parche = loadbutton("assets/menu/titlescreen/"
    "parchemin5.png", (sfVector2f) {0.7, 0.7}, (sfVector2f) {2000, 600});
}