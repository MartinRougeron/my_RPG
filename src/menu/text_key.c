/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text_key
*/

#include "my.h"

char *text_key(char *sprite, game_t *game)
{
    if (game->menu.num_key == 0)
        sprite = "A";
    if (game->menu.num_key == 1)
        sprite = "B";
    if (game->menu.num_key == 2)
        sprite = "C";
    if (game->menu.num_key == 3)
        sprite = "D";
    if (game->menu.num_key == 4)
        sprite = "E";
    if (game->menu.num_key == 5)
        sprite = "F";
    if (game->menu.num_key == 6)
        sprite = "G";
    if (game->menu.num_key == 7)
        sprite = "H";
    if (game->menu.num_key == 8)
        sprite = "I";
    return sprite;
}

char *text_kekeys(char *sprite, game_t *game)
{
    if (game->menu.num_key == 10)
        sprite = "K";
    if (game->menu.num_key == 11)
        sprite = "L";
    if (game->menu.num_key == 12)
        sprite = "M";
    if (game->menu.num_key == 13)
        sprite = "N";
    if (game->menu.num_key == 14)
        sprite = "O";
    if (game->menu.num_key == 15)
        sprite = "P";
    if (game->menu.num_key == 16)
        sprite = "Q";
    if (game->menu.num_key == 17)
        sprite = "R";
    if (game->menu.num_key == 18)
        sprite = "S";
    return sprite;
}

char *text_keyss(char *sprite, game_t *game)
{
    if (game->menu.num_key == 20)
        sprite = "U";
    if (game->menu.num_key == 21)
        sprite = "V";
    if (game->menu.num_key == 22)
        sprite = "W";
    if (game->menu.num_key == 23)
        sprite = "X";
    if (game->menu.num_key == 24)
        sprite = "Y";
    if (game->menu.num_key == 25)
        sprite = "Z";
    if (game->menu.num_key == 26)
        sprite = "0";
    if (game->menu.num_key == 27)
        sprite = "1";
    if (game->menu.num_key == 28)
        sprite = "2";
    return sprite;
}

char *text_key_key(char *sprite, game_t *game)
{
    if (game->menu.num_key == 30)
        sprite = "4";
    if (game->menu.num_key == 31)
        sprite = "5";
    if (game->menu.num_key == 32)
        sprite = "6";
    if (game->menu.num_key == 33)
        sprite = "7";
    if (game->menu.num_key == 34)
        sprite = "8";
    if (game->menu.num_key == 35)
        sprite = "9";
    if (game->menu.num_key == 36)
        sprite = "Escape";
    if (game->menu.num_key == 37)
        sprite = "LControl";
    if (game->menu.num_key == 38)
        sprite = "LShift";
    return sprite;
}

char *text_keys_key(char *sprite, game_t *game)
{
    if (game->menu.num_key == 40)
        sprite = "RSystem";
    if (game->menu.num_key == 41)
        sprite = "RControl";
    if (game->menu.num_key == 42)
        sprite = "RShift";
    if (game->menu.num_key == 43)
        sprite = "RAlt";
    if (game->menu.num_key == 44)
        sprite = "RSystem";
    if (game->menu.num_key == 45)
        sprite = "KMenu";
    if (game->menu.num_key == 46)
        sprite = "LBracket";
    if (game->menu.num_key == 47)
        sprite = "RBraket";
    if (game->menu.num_key == 48)
        sprite = "Semicolon";
    return sprite;
}