/*
** EPITECH PROJECT, 2020
** add
** File description:
** txt
*/

#include "my.h"

void addtxtdmg(game_t *game, int damage, sfVector2f pos)
{
    for (int i = 0; i != MAXENEMIE; i++)
        if (game->damage.text[i] == NULL) {
            game->damage.text[i] = sfText_create();
            sfText_setString(game->damage.text[i], my_itoa(damage));
            sfText_setFont(game->damage.text[i], game->font.menu);
            sfText_centerorigine(game->damage.text[i]);
            sfText_setPosition(game->damage.text[i],
            (sfVector2f) {pos.x + rand() % 70 - 35, pos.y - 65 - rand() % 35});
            game->damage.text_c[i] = sfClock_create();
            break;
        }
}