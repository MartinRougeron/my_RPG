/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text_key_r
*/

#include "my.h"

char *text_k_keys_n(char *sprite, game_t *game)
{
    if (game->menu.num_key == 59)
        sprite = "Backspace";
    if (game->menu.num_key == 69)
        sprite = "Multiply";
    if (game->menu.num_key == 79)
        sprite = "Npad4";
    if (game->menu.num_key == 89)
        sprite = "F5";
    if (game->menu.num_key == 99)
        sprite = "f15";
    if (game->menu.num_key == 9)
        sprite = "J";
    if (game->menu.num_key == 19)
        sprite = "T";
    return sprite;
}

char *text_k_keys_norm(char *sprite, game_t *game)
{
    if (game->menu.num_key == 29)
        sprite = "3";
    if (game->menu.num_key == 39)
        sprite = "LAlt";
    if (game->menu.num_key == 49)
        sprite = "KComma";
    return sprite;
}