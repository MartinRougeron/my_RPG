/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** creat_new_name
*/

#include "my.h"

void creat_new_name(game_t *game)
{
    int i = 0;
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (TIME(clock) < 40)
        return;
    if (hitsprite(game->menu.menu_pl.rec, (sfWindow*)game->window) &&
    game->menu.parch_3_status == 1) {
        i = test_reforge(game);
        if (i == 0) {
            return;
        }
        name_norm(game);
        name_norm_r(game);
    }
    sfClock_restart(clock);
}

void all_char_forname(char *sprite, game_t *game, int i)
{
    sprite[i] = text_key_play(sprite, game, i);
    sprite[i] = text_keyss_play(sprite, game, i);
    sprite[i] = text_kekeys_play(sprite, game, i);
}

char text_key_play(char *sprite, game_t *game, int i)
{
    if (game->menu.num_key == 0)
        sprite[i] = 'A';
    if (game->menu.num_key == 1)
        sprite[i] = 'B';
    if (game->menu.num_key == 2)
        sprite[i] = 'C';
    if (game->menu.num_key == 3)
        sprite[i] = 'D';
    if (game->menu.num_key == 4)
        sprite[i] = 'E';
    if (game->menu.num_key == 5)
        sprite[i] = 'F';
    if (game->menu.num_key == 6)
        sprite[i] = 'G';
    if (game->menu.num_key == 7)
        sprite[i] = 'H';
    if (game->menu.num_key == 8)
        sprite[i] = 'I';
    return sprite[i];
}

char text_kekeys_play(char *sprite, game_t *game, int i)
{
    if (game->menu.num_key == 10)
        sprite[i] = 'K';
    if (game->menu.num_key == 11)
        sprite[i] = 'L';
    if (game->menu.num_key == 12)
        sprite[i] = 'M';
    if (game->menu.num_key == 13)
        sprite[i] = 'N';
    if (game->menu.num_key == 14)
        sprite[i] = 'O';
    if (game->menu.num_key == 15)
        sprite[i] = 'P';
    if (game->menu.num_key == 16)
        sprite[i] = 'Q';
    if (game->menu.num_key == 17)
        sprite[i] = 'R';
    if (game->menu.num_key == 18)
        sprite[i] = 'S';
    return sprite[i];
}

char text_keyss_play(char *sprite, game_t *game, int i)
{
    if (game->menu.num_key == 20)
        sprite[i] = 'U';
    if (game->menu.num_key == 21)
        sprite[i] = 'V';
    if (game->menu.num_key == 22)
        sprite[i] = 'W';
    if (game->menu.num_key == 23)
        sprite[i] = 'X';
    if (game->menu.num_key == 24)
        sprite[i] = 'Y';
    if (game->menu.num_key == 25)
        sprite[i] = 'Z';
    if (game->menu.num_key == 19)
        sprite[i] = 'T';
    if (game->menu.num_key == 9)
        sprite[i] = 'J';
    return sprite[i];
}