/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_shop.c
*/

#include "my.h"

void draw_shop_items(game_t *game, int i)
{
    sfSprite_setPosition(pnj_item(i).sprite,
    (sfVector2f) {i * 242 + 480, 1080/2 + 50});
    sfSprite_setScale(pnj_item(i).sprite,
    (sfVector2f){10, 10});
    sfRenderWindow_drawText(game->window,
    loadtext(pnj_item(i).name,
    (sfVector2f){1, 1}, (sfVector2f){i * 242 + 400, 1080/2 - 170}, 30),
    NULL);
    sfRenderWindow_drawSprite(game->window,
    pnj_item(i).sprite, NULL);
}

int draw_choice(int pos, int i, game_t *game, sfIntRect *rect)
{
    if (pos != i)
        pos = i;
    drawoutline(game, rect[i]),
    drawiteminfo_pnj(game, pnj_item(i), (sfVector2f) {rect[i].left,
    rect[i].top});
    return (pos);
}

void draw_item(game_t *game, int i)
{
    sfSprite_setPosition(pnj_item(i).sprite,
    (sfVector2f) {i * 242 + 480, 1080/2 + 50});
    sfSprite_setScale(pnj_item(i).sprite,
    (sfVector2f){4, 4});
    sfRenderWindow_drawText(game->window,
    loadtext(pnj_item(i).name,
    (sfVector2f){1, 1}, (sfVector2f){i * 242 + 400, 1080/2 - 170}, 30),
    NULL);
    sfRenderWindow_drawSprite(game->window,
    pnj_item(i).sprite, NULL);
}

void choice_item(game_t *game)
{
    int tmp = choice_arrow();
    
    pnj_selected.pos += tmp;
    pnj_selected.pos = (pnj_selected.pos % 5);
    pnj_selected.pos += (pnj_selected.pos == -1) * 5;
    if (tmp < 0)
        for (; pnj_selected.sell[pnj_selected.pos] == 0 &&
        pnj_selected.pos >= 0; pnj_selected.pos--);
    else
        for (; pnj_selected.sell[pnj_selected.pos] == 0 &&
        pnj_selected.pos < 5; pnj_selected.pos++);
}

int shop(game_t *game, sfIntRect *rect, int i)
{
    if (pnj_item(i).sprite == NULL)
        return 0;
    draw_item(game, i);
    if (hitrect(rect[i], game->window) || (i == pnj_selected.pos)) {
        drawoutline(game, rect[i]),
        drawiteminfo_pnj(game, pnj_item(i), (sfVector2f) {rect[i].left,
        rect[i].top});
        pnj_selected.pos = i;
        return 1;
    }
    return 0;
}
