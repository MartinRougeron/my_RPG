/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** action_input.c
*/

#include "my.h"

void action_tree_input(game_t *game)
{
    if (game->screen != SKILLTREE)
        game->screen = SKILLTREE;
    else
        game->screen = GAME;
}

void action_pause_input(game_t *game)
{
    if (game->screen != PAUSE && game->player.talking == -1 &&
        !game->player.quest)
            game->screen = PAUSE;
        else
            game->screen = GAME;
}

void my_stance(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->key.changestance)) {
        if (game->player.learnmagic == 0)
            return;
        else
            game->player.stance =
            (game->player.stance == RANGE) ? MELEE : RANGE;
    }
}

void action_input(game_t *game)
{
    if (sfKeyboard_isKeyPressed(game->key.map))
        game->player.map = (game->player.map == 0) ? 1 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        if (game->player.quest) {
            game->player.quest = 0;
            game->questselect = 0;
        } else
            game->player.quest = 1;
    }
    my_stance(game);
    if (sfKeyboard_isKeyPressed(game->key.changespell)
    && game->player.state != CASTING) {
        game->player.mage.select++;
        if (game->player.mage.select >= game->player.mage.unlocked)
            game->player.mage.select = 0;
    }
}

void zoom(game_t *game, sfEvent event)
{
    static float zoom = 1;

    if (event.type == sfEvtMouseWheelMoved) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
            zoom += (event.mouseWheel.delta == -1) ? 0.05 : -0.05;
            if (zoom > 1) {
                zoom -= 0.05;
                return;
            }
            if (zoom < 0.6) {
                zoom += 0.05;
                return;
            }
            sfView_zoom(game->view,
            ((event.mouseWheel.delta == -1) ? 1 / 0.9 : 0.9));
            centerviewonplayer(game);
        }
    }
}
