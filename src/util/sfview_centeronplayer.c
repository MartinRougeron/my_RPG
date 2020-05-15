/*
** EPITECH PROJECT, 2020
** sfvies
** File description:
** center
*/

#include "my.h"

void centerviewonplayer(game_t *game)
{
    sfView_setCenter(game->view, sfSprite_getPosition(game->player.sprite));
    if (sfView_getCenter(game->view).x +
    (sfView_getSize(game->view).x / 2) > 1920)
        sfView_move(game->view, (sfVector2f) {-(sfView_getCenter(game->view).x
        + (sfView_getSize(game->view).x / 2) - 1920), 0});
    if (sfView_getCenter(game->view).y +
    (sfView_getSize(game->view).y / 2) > 1080)
        sfView_move(game->view, (sfVector2f) {0,
        -(sfView_getCenter(game->view).y +
        (sfView_getSize(game->view).y / 2) - 1080)});
    if (sfView_getCenter(game->view).y -
    (sfView_getSize(game->view).y / 2) < 0)
        sfView_move(game->view, (sfVector2f)
        {0, -(sfView_getCenter(game->view).y
        - (sfView_getSize(game->view).y / 2))});
    if (sfView_getCenter(game->view).x -
    (sfView_getSize(game->view).x / 2) < 0)
        sfView_move(game->view, (sfVector2f) {-(sfView_getCenter(game->view).x
        - (sfView_getSize(game->view).x / 2)), 0});
}
