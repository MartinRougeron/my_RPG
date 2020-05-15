/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_pnj_quest.c
*/

#include "my.h"

void load_pnj_quest_0(game_t *game)
{
    game->pnj[1] = loadpnj("assets/pnj/Male/Male 08-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 0, 0, 25, 10}, SOUTH);
    game->pnj[1].text = "Hello World !";
    game->pnj[2] = loadpnj("assets/pnj/Male/Male 08-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 3, 4, 25, 15}, SOUTH);
    load_shop(&game->pnj[2], (item_t []) {create_item((char *[])
    {"Broken Chestplate", "+5 armor\n+5 Health",
    "assets/attack/chesplate.png"},
    ARMORBLUE, CHESTPLATE, (itemstat_t) {5, 5, 0, 0, 0})},
    (int []) {10, 0, 0, 0, 0}, 1);
}

void load_pnj_quest_1(game_t *game) {
    game->pnj[3] = loadpnj("assets/pnj/Male/Male 02-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 0, 0, 25, 25}, EST);
    game->pnj[3].text = "I always dream of becoming a rapper";
    game->pnj[6] = loadpnj("assets/pnj/Male/Male 05-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 5, 4, 7, 15}, SOUTH);
    game->pnj[6].text = "Oh you are the chosen one? I'll teach you the"
    "ice spel"
    "!l Here take this amulet if you manage to collect the other two you can"
    "go"
    " and defeat sahrotar at its volcano";
    game->pnj[6].quest.recompense = create_item((char *[])
    {"Amulette de glace", "+10 mana", "assets/amulettes/amulette1.png"}, 0,
    ARTIFACT1, (itemstat_t) {0, 0, 10, 0, 0});
}

void load_pnj_quest_2(game_t *game)
{
    game->pnj[24] = loadpnj("assets/pnj/Male/Male 14-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 1, 0, 8, 25}, SOUTH);
    game->pnj[24].text = "Go back when you defeted Trivitant";
    game->pnj[24].quest.recompense = create_item((char *[])
    {"Amulette de l'amour", "+10 strenght", "assets/amulettes/amulette3.png"},
    0, ARTIFACT3, (itemstat_t) {0, 0, 0, 0, 10});
    game->pnj[25] = loadpnj("assets/pnj/chest.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FANTOME, 0, 0, 15, 15}, SOUTH);
    game->pnj[25].text = "";
    game->pnj[25].quest.recompense = create_item((char *[])
    {"Jewelery stolen", "Pretty jewelry\nQuest object",
    "assets/attack/necklace.png"},
    ARMORNONE, NOTYPE, (itemstat_t) {0, 0, 0, 0, 0});
    game->pnj[27] = loadpnj("assets/pnj/Female/Female 05-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {CAPITAL, 0, 1, 8, 22}, EST);
    game->pnj[27].text = "Can you bring these flowers to the kingdom garden?";
    game->pnj[27].quest.recompense = create_item((char *[])
    {"Flower lot", "Flower\nQuest object", "assets/attack/flowers.png"},
    ARMORNONE, NOTYPE, (itemstat_t) {0, 0, 0, 0, 0});
}

void load_pnj_quest(game_t *game)
{
    load_pnj_quest_0(game);
    load_pnj_quest_1(game);
    load_pnj_quest_2(game);
    game->pnj[50] = loadpnj("assets/pnj/Male/Male 14-3.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {WORLD, 4, 2, 8, 25}, SOUTH);
    game->pnj[50].text = "Kill 10 mobs and I teach you a spell";
}
