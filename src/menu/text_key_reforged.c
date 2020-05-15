/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text_key_reforged
*/

#include "my.h"

char *text_k_key(char *sprite, game_t *game)
{
    if (game->menu.num_key == 50)
        sprite = "KPeriod";
    if (game->menu.num_key == 51)
        sprite = "KQuote";
    if (game->menu.num_key == 52)
        sprite = "KSlash";
    if (game->menu.num_key == 53)
        sprite = "KBackslash";
    if (game->menu.num_key == 54)
        sprite = "KTilde";
    if (game->menu.num_key == 55)
        sprite = "KEqual";
    if (game->menu.num_key == 56)
        sprite = "KHyphen";
    if (game->menu.num_key == 57)
        sprite = "KSpace";
    if (game->menu.num_key == 58)
        sprite = "Enter";
    return sprite;
}

char *text_k_keys(char *sprite, game_t *game)
{
    if (game->menu.num_key == 60)
        sprite = "Tab";
    if (game->menu.num_key == 61)
        sprite = "PageUp";
    if (game->menu.num_key == 62)
        sprite = "PageDown";
    if (game->menu.num_key == 63)
        sprite = "End";
    if (game->menu.num_key == 64)
        sprite = "Home";
    if (game->menu.num_key == 65)
        sprite = "Insert";
    if (game->menu.num_key == 66)
        sprite = "Delete";
    if (game->menu.num_key == 67)
        sprite = "Add";
    if (game->menu.num_key == 68)
        sprite = "Subtract";
    return sprite;
}

char *text_k_keyss(char *sprite, game_t *game)
{
    if (game->menu.num_key == 70)
        sprite = "Divide";
    if (game->menu.num_key == 71)
        sprite = "Left";
    if (game->menu.num_key == 72)
        sprite = "Right";
    if (game->menu.num_key == 73)
        sprite = "Up";
    if (game->menu.num_key == 74)
        sprite = "Down";
    if (game->menu.num_key == 75)
        sprite = "Npad0";
    if (game->menu.num_key == 76)
        sprite = "Npad1";
    if (game->menu.num_key == 77)
        sprite = "Npad2";
    if (game->menu.num_key == 78)
        sprite = "Npad3";
    return sprite;
}

char *text_ks_keys(char *sprite, game_t *game)
{
    if (game->menu.num_key == 80)
        sprite = "Npad5";
    if (game->menu.num_key == 81)
        sprite = "Npad6";
    if (game->menu.num_key == 82)
        sprite = "Npad7";
    if (game->menu.num_key == 83)
        sprite = "Npad8";
    if (game->menu.num_key == 84)
        sprite = "Npad9";
    if (game->menu.num_key == 85)
        sprite = "F1";
    if (game->menu.num_key == 86)
        sprite = "F2";
    if (game->menu.num_key == 87)
        sprite = "F3";
    if (game->menu.num_key == 88)
        sprite = "F4";
    return sprite;
}

char *text_keys(char *sprite, game_t *game)
{
    if (game->menu.num_key == 90)
        sprite = "F6";
    if (game->menu.num_key == 91)
        sprite = "F7";
    if (game->menu.num_key == 92)
        sprite = "F8";
    if (game->menu.num_key == 93)
        sprite = "F9";
    if (game->menu.num_key == 94)
        sprite = "F10";
    if (game->menu.num_key == 95)
        sprite = "F11";
    if (game->menu.num_key == 96)
        sprite = "F12";
    if (game->menu.num_key == 97)
        sprite = "F13";
    if (game->menu.num_key == 98)
        sprite = "F14";
    return sprite;
}