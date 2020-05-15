/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** discover_tree.c
*/

#include "my.h"

void discover_levelup(game_t *game)
{
    static int first = 0;

    if (first++ == 0) {
        game->player.successmsg = "Youhou you level up\n\n"
        "You can choose\n\nA stat to increase";
        drawsuccessmsg(game);
    }
}

void discover_tree(game_t *game)
{
    static int first = 0;

    if (first++ == 0)
        game->player.successmsg = "With this Level UP\n\n"
        "you won a Skill Point\n\nOpen skill tree with Key N\n\n"
        "You win a skill point\n\nevery 3 levels";
    if (sfKeyboard_isKeyPressed(game->key.tree))
        game->is_tuto = CAPITALE;
}

void go_saxon_dalle(game_t *game)
{
    static int first = 0;

    if (first++ == 0)
        game->player.successmsg = "You finished your training\n\n"
        "come back to Hilford\n\nYou can open map with key M\n\n"
        "Open the quest log with\n\nkey K";
    game->all_quest[0] = BEGIN;
    game->is_tuto = NO;
}