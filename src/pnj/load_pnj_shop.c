/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_pnj_shop.c
*/

#include "my.h"

void load_pnj_shop_0(game_t *game)
{
    game->pnj[33] = loadpnj("assets/pnj/Male/Male 01-1.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 1, 0, 16, 15}, SOUTH);
    load_shop(&game->pnj[33], (item_t []){create_item((char *[])
    {"Hay", "+5 health", "assets/food/hay.png"}, 0,
    POTION, (itemstat_t) {0, 5, 0, 0, 0}), create_item((char *[])
    {"Flowey", "Cute flower\n(do nothing)", "assets/easter/flowey.png"}, 0,
    NOTYPE, (itemstat_t) {0, 0, 0, 0, 0}), create_item((char *[])
    {"Apple", "+20 health", "assets/food/apple.png"}, 0,
    POTION, (itemstat_t) {0, 20, 0, 0, 0})}, (int[]){5, 2, 40, 0, 0}, 3);
}

void load_pnj_shop_1(game_t *game)
{
    game->pnj[41] = loadpnj("assets/pnj/Male/Male 04-3.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 0, 0, 7, 9}, SOUTH);
    load_shop(&game->pnj[41], (item_t []){create_item((char *[])
    {"Tartine", "+10 health", "assets/food/tartine.png"}, 0,
    POTION, (itemstat_t) {0, 10, 0, 0, 0}), create_item((char *[])
    {"Pain", "+25 health", "assets/food/pain.png"}, 0,
    POTION, (itemstat_t) {0, 25, 0, 0, 0}), create_item((char *[])
    {"Croissant", "+50 health", "assets/food/croissant.png"}, 0,
    POTION, (itemstat_t) {0, 50, 0, 0, 0}), create_item((char *[])
    {"Frites", "+100 health", "assets/food/frites.png"}, 0,
    POTION, (itemstat_t) {0, 100, 0, 0, 0}), create_item((char *[])
    {"Mais", "+150 health", "assets/food/mais.png"}, 0,
    POTION, (itemstat_t) {0, 150, 0, 0, 0})},
    (int[]){30, 45, 80, 120, 200}, 5);
    game->pnj[42] = loadpnj("assets/pnj/Male/Male 04-3.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {SAXON, 1, 0, 6, 9}, SOUTH);
}

void load_pnj_shop_2(game_t *game)
{
    load_shop(&game->pnj[42], (item_t []){create_item((char *[])
    {"Helmet", "+10 armor", "assets/player/blue/helmet.png"}, 0,
    HELMET, (itemstat_t) {5, 0, 0, 0, 0}), create_item((char *[])
    {"Chestplate", "+15 armor", "assets/player/blue/chestplate.png"},
    ARMORSOLDIER,
    CHESTPLATE, (itemstat_t) {15, 0, 0, 0, 0}), create_item((char *[])
    {"Legs", "+10 armor", "assets/player/blue/legs.png"}, 0,
    LEGGINGS, (itemstat_t) {10, 0, 0, 0, 0}), create_item((char *[])
    {"Boot", "+5 armor", "assets/player/blue/boots.png"}, 0,
    BOOTS, (itemstat_t) {5, 0, 0, 0, 0}), create_item((char *[])
    {"Sword", "+20 damage", "assets/player/blue/sword.png"}, 0,
    SWORD, (itemstat_t) {0, 0, 0, 0, 20})}, (int[]){40, 40, 40, 40, 50}, 5);
}

void load_pnj_shop(game_t *game)
{
    game->pnj[7] = loadpnj("assets/pnj/Male/Male 17-2.png",
    (sfVector2f) {2.8, 3.1}, (pos_t) {FARWATER, 1, 0, 15, 20}, WEST);
    game->pnj[7].text = "Do you know that I know where the second amulet "
    "those, go bring its fish to the capital";
    game->pnj[7].quest.recompense = create_item((char *[]) {"Fish crate",
    "Fish crate\nQuest object", "assets/attack/fish.png"}, 0, NOTYPE,
    (itemstat_t) {0, 0, 0, 0, 0});
    load_pnj_shop_0(game);
    load_pnj_shop_1(game);
    load_pnj_shop_2(game);
}