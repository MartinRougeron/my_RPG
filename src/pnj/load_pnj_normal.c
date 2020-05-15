/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_pnj_normal.c
*/

#include "my.h"

void load_pnj_normal_0(game_t *game)
{
    game->pnj[0] = loadpnj("assets/pnj/Male/Male 05-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 1, 1, 8, 6}, SOUTH);
    game->pnj[0].text = "Hello you !";
    game->pnj[4] = loadpnj("assets/pnj/Male/Male 03-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 1, 0, 20, 8}, SOUTH);
    game->pnj[4].text = "Hi there, are you from my father?"
    "I'll teach you a spell";
    game->pnj[5] = loadpnj("assets/pnj/Male/Male 05-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 0, 1, 15, 15}, SOUTH);
    game->pnj[5].text = "Hello World !";
    game->pnj[8] = loadpnj("assets/pnj/Female/Female 17-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 1, 1, 21, 12}, SOUTH);
    game->pnj[8].hair = 1;
    game->pnj[9] = loadpnj("assets/pnj/Male/Male 12-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 1, 23, 12}, SOUTH);
    game->pnj[9].save = 1;
    game->pnj[10] = loadpnj("assets/pnj/Female/Female 14-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 1, 5, 15}, WEST);
    game->pnj[10].text = "Such a beautiful weather today don't you think ?";
}

void load_pnj_normal_2(game_t *game)
{
    game->pnj[11] = loadpnj("assets/pnj/Male/Male 11-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 1, 12, 23}, NORTH);
    game->pnj[11].text = "This city is restless !";
    game->pnj[12] = loadpnj("assets/pnj/Female/Female 06-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 1, 12, 14}, SOUTH);
    game->pnj[12].text = "My store was closed because of that damn dragon";
    game->pnj[13] = loadpnj("assets/pnj/Male/Male 17-4.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 1, 7, 9}, SOUTH);
    game->pnj[13].text = "I store all the city food in my barn";
    game->pnj[14] = loadpnj("assets/pnj/Female/Female 03-4.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 1, 25, 22}, EST);
    game->pnj[14].text = "Have you heard of bigfoot";
    game->pnj[15] = loadpnj("assets/pnj/Female/Female 13-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 1, 1, 5, 19}, WEST);
    game->pnj[15].text = "It is the deepest well in the whole kingdom";
    game->pnj[16] = loadpnj("assets/pnj/Female/Female 22-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 1, 1, 20, 22}, NORTH);
    game->pnj[16].text = "I planted all the plants in the gardens";
}

void load_pnj_normal_3(game_t *game)
{
    game->pnj[17] = loadpnj("assets/pnj/Male/Male 09-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 1, 0, 9, 7}, SOUTH);
    game->pnj[17].text = "I hope someone can one day defeat this dragon";
    game->pnj[18] = loadpnj("assets/pnj/Male/Male 12-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 1, 0, 24, 11}, SOUTH);
    game->pnj[18].text = "Oh you are the chosen one to defeat the cursed "
    "sahrotar! Go west of saxon dale my son will teach you magic";
    game->pnj[19] = loadpnj("assets/pnj/Male/Male 14-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 1, 0, 19, 13}, EST);
    game->pnj[19].text = "My girlfriend died while drawing the world map";
    game->pnj[20] = loadpnj("assets/pnj/Soldier/Soldier 07-4.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 0, 13, 23}, NORTH);
    game->pnj[20].text = "We are looking for a man who really looks like you";
    game->pnj[21] = loadpnj("assets/pnj/Soldier/Soldier 07-4.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 0, 18, 23}, NORTH);
    game->pnj[21].text = "We are looking for a man who really looks like you";
    game->pnj[22] = loadpnj("assets/pnj/Soldier/Soldier 04-3.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 0, 3, 9}, NORTH);
    game->pnj[22].text = "I'm not good at aiming but I learn quickly";
}

void load_pnj_normal_1(game_t *game)
{
    game->pnj[23] = loadpnj("assets/pnj/Soldier/Soldier 04-3.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 0, 5, 11}, EST);
    game->pnj[23].text = "He is really not good to aim";
    game->pnj[26] = loadpnj("assets/pnj/Female/Female 22-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 3, 1, 15, 15}, WEST);
    game->pnj[26].text = "I'm waiting for a flower delivery from the capital";
        game->pnj[28] = loadpnj("assets/pnj/Female/Female 22-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 0, 0, 17, 23}, SOUTH);
    game->pnj[28].text = "Welcome to Farwater ! You can rest here if you want";
    game->pnj[29] = loadpnj("assets/pnj/Female/Female 12-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 0, 0, 13, 13}, WEST);
    game->pnj[29].text = "Why do we have all this hay? There's no animals"
    "here";
    game->pnj[30] = loadpnj("assets/pnj/Female/Female 25-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 0, 0, 6, 10}, SOUTH);
    game->pnj[30].text = "I'm not going in your tent so GET OUT OF MY TENT !";
    game->pnj[31] = loadpnj("assets/pnj/Female/Female 20-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 0, 0, 13, 8}, EST);
    game->pnj[31].text = "HEY! Did you see my haybrow? Looks cute right?";
}

void load_pnj_normal(game_t *game)
{
    load_pnj_normal_0(game);
    load_pnj_normal_2(game);
    load_pnj_normal_3(game);
    load_pnj_normal_1(game);
    load_pnj_normal_4(game);
    load_pnj_normal_5(game);
    game->pnj[47] = loadpnj("assets/pnj/Female/Female 15-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 1, 5, 16, 7}, EST);
    game->pnj[47].text = "I love Subaru !!! He is here, I'm sure !";
    game->pnj[48] = loadpnj("assets/pnj/Female/Female 16-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 1, 5, 15, 7}, WEST);
    game->pnj[48].text = "But he loves Emilia ! (Why are we here ?)";
    game->pnj[49] = loadpnj("assets/pnj/pkmntrainer.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 5, 1, 13, 16}, SOUTH);
    game->pnj[49].text = "LET'S DO A POKEMON BATTLE!! Oh wait.. Wrong game";
}
