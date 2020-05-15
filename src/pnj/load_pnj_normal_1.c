/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_pnj_normal_1.c
*/

#include "my.h"

void load_pnj_normal_4(game_t *game)
{
    game->pnj[32] = loadpnj("assets/pnj/Male/Male 12-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 0, 0, 22, 8}, SOUTH);
    game->pnj[32].save = 1;
    game->pnj[34] = loadpnj("assets/pnj/Male/Male 12-3.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 1, 0, 20, 24}, WEST);
    game->pnj[34].text = "Someone said this world is just a video game."
    "Is it true ?";
    game->pnj[35] = loadpnj("assets/pnj/Male/Male 13-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 1, 0, 20, 8}, NORTH);
    game->pnj[35].text = "My poor cat died because of the evil dragon";
    game->pnj[36] = loadpnj("assets/pnj/Animal/Cat 01-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 1, 0, 18, 7}, SOUTH);
    game->pnj[36].text = "Meow meow! (Don't eat hay)";
    game->pnj[37] = loadpnj("assets/pnj/Male/Male 12-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 1, 0, 23, 9}, SOUTH);
    game->pnj[37].text = "I was a great soldier but now I'm too old to"
    "kill a dragon";
    game->pnj[38] = loadpnj("assets/pnj/Male/Male 14-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 0, 0, 13, 9}, SOUTH);
    game->pnj[38].text = "I like this city, a bit old but quiet";
}

void load_pnj_normal_5(game_t *game)
{
    game->pnj[39] = loadpnj("assets/pnj/Male/Male 07-4.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 0, 0, 8, 26}, SOUTH);
    game->pnj[39].text = "My muscles are getting bigger";
    game->pnj[40] = loadpnj("assets/pnj/Male/Male 07-4.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 0, 0, 23, 26}, SOUTH);
    game->pnj[40].text = "Drink water, good water, holy water";
    game->pnj[43] = loadpnj("assets/pnj/Male/Male 12-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 0, 0, 21, 9}, SOUTH);
    game->pnj[43].save = 1;
    game->pnj[44] = loadpnj("assets/pnj/Enemy/Enemy 09-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FANTOME, 0, 0, 7, 25}, SOUTH);
    game->pnj[44].text = "Bouh! I scared you, I know it";
    game->pnj[45] = loadpnj("assets/pnj/Male/Male 12-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FANTOME, 0, 0, 8, 12}, SOUTH);
    game->pnj[45].save = 1;
    game->pnj[46] = loadpnj("assets/pnj/Enemy/Enemy 11-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FANTOME, 0, 0, 23, 17}, EST);
    game->pnj[46].text = "I want to open this chest, but I don't have hands";
}