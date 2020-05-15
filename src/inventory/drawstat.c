/*
** EPITECH PROJECT, 2020
** inven
** File description:
** draw stat
*/

#include "my.h"

void drawstat(game_t *game)
{
    sfText *text[4] = {NULL, NULL, NULL, NULL};

    if (text[0] == NULL) {
        text[0] = createsimpletext("", (sfVector2f) {1092, 884}, 10);
        text[1] = createsimpletext("", (sfVector2f) {1243, 884}, 10);
        text[2] = createsimpletext("", (sfVector2f) {1100, 980}, 10);
        text[3] = createsimpletext("", (sfVector2f) {1243, 980}, 10);
    }
    sfText_setString(text[0], my_strcat(my_itoa(game->player.stat.stamina),
    my_strcat(" / ", my_itoa(game->player.stat.maxstamina))));
    sfText_setString(text[1], my_itoa(game->player.stat.armor));
    sfText_setString(text[2], my_strcat(my_itoa(game->player.stat.health),
    my_strcat(" / ", my_itoa(game->player.stat.maxhealth))));
    sfText_setString(text[3], my_strcat(my_itoa(game->player.stat.mana),
    my_strcat(" / ", my_itoa(game->player.stat.maxmana))));
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawText(game->window, text[i], NULL);
}