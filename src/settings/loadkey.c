/*
** EPITECH PROJECT, 2020
** key
** File description:
** key
*/

#include "my.h"

setting_t loaddefaultkey(void)
{
    setting_t settings;

    settings.attack = sfKeyT;
    settings.changestance = sfKeyC;
    settings.down = sfKeyDown;
    settings.interact = sfKeyE;
    settings.inventory = sfKeyTab;
    settings.left = sfKeyLeft;
    settings.map = sfKeyM;
    settings.pause = sfKeyEscape;
    settings.right = sfKeyRight;
    settings.up = sfKeyUp;
    settings.changespell = sfKeyR;
    settings.tree = sfKeyN;
    return settings;
}