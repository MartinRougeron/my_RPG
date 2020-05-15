/*
** EPITECH PROJECT, 2020
** inv
** File description:
** draw drop
*/

#include "my.h"

void drawdroptext(game_t *game, drop_t stock)
{
    static sfText *text[2] = {NULL, NULL};
    int alpha = (game->hide[LOOT] == TRUE) ? 128 : 255;

    if (text[0] == NULL) {
        text[0] = loadtxtname("+", (sfVector2f) {1645 - 40, 45}, 25);
        text[1] = loadtxtname("+", (sfVector2f) {1795 - 40, 45}, 25);
    }
    sfText_setTransparent(text[0], alpha, sfText_getColor(text[0]));
    sfText_setTransparent(text[1], alpha, sfText_getColor(text[1]));
    if (stock.xp > 0 || stock.gold > 0) {
        sfRenderWindow_drawText(game->window, text[0], NULL);
        sfRenderWindow_drawText(game->window, text[1], NULL);
    }
    sfText_setString(text[0], my_strcat("+", my_itoa(stock.gold)));
    sfText_setString(text[1], my_strcat("+", my_itoa(stock.xp)));
}

void drawdropui(game_t *game, drop_t stock)
{
    int alpha = (game->hide[LOOT] == TRUE) ? 128 : 255;
    static sfSprite *gui = NULL;

    if (gui == NULL)
        gui = loadskill("assets/gui/lootgui.png",
        (sfVector2f) {3.5, 2.5}, (sfVector2f) {1720, 80});
    sfSprite_setTransparent(gui, alpha);
    if (stock.xp > 0 || stock.gold > 0)
        sfRenderWindow_drawSprite(game->window, gui, NULL);
}

void drawdrop(game_t *game, drop_t drop)
{
    static sfClock *clock = NULL;
    static drop_t stock = {0, 0};

    if (clock == NULL)
        clock = sfClock_create();
    drawdropui(game, stock);
    drawdroptext(game, stock);
    if (TIME(clock) > 3000)
        stock = (drop_t) {0, 0};
    if (drop.gold <= 0 && drop.xp <= 0)
        return;
    stock.gold += drop.gold;
    stock.xp += drop.xp;
    sfClock_restart(clock);
    game->player.drop = (drop_t) {0, 0};
}