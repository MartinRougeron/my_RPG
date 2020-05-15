/*
** EPITECH PROJECT, 2020
** xp
** File description:
** util
*/

#include "my.h"

int xpneedtolvl(game_t *game)
{
    return (int) round(16 * sqrt(game->player.level));
}

void makelevelup(game_t *game)
{
    while (1) {
        if (game->player.xp >= xpneedtolvl(game)) {
            game->player.xp -= xpneedtolvl(game);
            game->player.level += 1;
            game->lvltogive += 1;
            if (game->player.level % 3 == 2)
                game->player.tree.point += 1;
            game->screen = LEVELUP;
            game->player.state = IDLE;
            sfSprite_setTextureRect(game->player.sprite,
            (sfIntRect) {0, 288, 30, 35});
        } else
            break;
    }
}

void drawlevel(game_t *game)
{
    static sfText *level = NULL;
    char *txt;
    int alpha = (game->hide[XP] == TRUE) ? 128 : 255;

    if (level == NULL)
        level = loadnbofcmpt("", (sfVector2f) {WIDTH / 2 - 220, 50}, 20);
    sfText_setTransparent(level, alpha, sfText_getColor(level));
    txt = my_itoa(game->player.level);
    sfText_setString(level, txt);
    sfRenderWindow_drawText(game->window, level, NULL);
}

void drawbar(game_t *game)
{
    static sfSprite *bar[2] = {NULL, NULL};
    sfVector2f scale = {4, 2.5};
    int alpha = (game->hide[XP] == TRUE) ? 128 : 255;
    sfIntRect rect;

    if (bar[0] == NULL) {
        bar[0] = loadskill("assets/gui/xpgui.png", scale,
        (sfVector2f) {WIDTH / 2, 60});
        bar[1] = loadskill("assets/gui/xpbar.png", scale,
        (sfVector2f) {WIDTH / 2 + 46, 60});
    }
    sfSprite_setTransparent(bar[0], alpha);
    sfSprite_setTransparent(bar[1], alpha);
    rect = sfSprite_getTextureRect(bar[1]);
    rect.width = 97 * (game->player.xp * 1.0 / xpneedtolvl(game));
    sfSprite_setTextureRect(bar[1], rect);
    sfRenderWindow_drawSprite(game->window, bar[0], NULL);
    sfRenderWindow_drawSprite(game->window, bar[1], NULL);
}

void drawxp(game_t *game)
{
    drawbar(game);
    drawlevel(game);
}