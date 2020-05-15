/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** all_set_laod
*/

#include "my.h"

void all_set_load(game_t *game)
{
    LOAD_MENU.load_game = loadtext("Load Game", (sfVector2f)
    {1, 1}, (sfVector2f) {1450, 700}, 70);
    LOAD_MENU.load_game_grey = loadtext_grey("Load Game",
    (sfVector2f) {1, 1}, (sfVector2f) {1450, 700}, 70);
    LOAD_MENU.load_game_white = loadtext_white("Load Game",
    (sfVector2f) {1, 1}, (sfVector2f) {1450, 700}, 70);
    LOAD_MENU.load_triviatan = loadtext("Load triviatan",
    (sfVector2f) {1, 1}, (sfVector2f) {1380, 810}, 70);
    LOAD_MENU.load_triviatan_grey = loadtext_grey("Load triviatan",
    (sfVector2f) {1, 1}, (sfVector2f) {1380, 810}, 70);
    LOAD_MENU.load_triviatan_white = loadtext_white("Load triviatan",
    (sfVector2f) {1, 1}, (sfVector2f) {1380, 810}, 70);
    LOAD_MENU.load_dragon = loadtext("Load dragon", (sfVector2f)
    {1, 1}, (sfVector2f) {1420, 920}, 70);
    LOAD_MENU.load_dragon_grey = loadtext_grey("Load dragon",
    (sfVector2f) {1, 1}, (sfVector2f) {1420, 920}, 70);
    LOAD_MENU.load_dragon_white = loadtext_white("Load dragon",
    (sfVector2f) {1, 1}, (sfVector2f) {1420, 920}, 70);
}

void all_set_load_reforge(game_t *game)
{
    LOAD_MENU.aro =
    loadbutton("assets/menu/setting/fleche.png",
    (sfVector2f) {0.2, 0.2}, (sfVector2f) {1350, 650});
    LOAD_MENU.aro_white =
    loadbutton("assets/menu/setting/fleche_white.png",
    (sfVector2f) {0.2, 0.2}, (sfVector2f) {1350, 650});
}