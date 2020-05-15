/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** shop_pnj.c
*/

#include "my.h"

static sfIntRect rect[5] = {{374, 444, 213, 278}, {613, 444, 213, 278},
    {860, 444, 213, 278}, {1098, 444, 213, 278}, {1342, 444, 213, 278}};

void load_shop(pnj_t *pnj, item_t *item, int *price, int nbitem)
{
    pnj->pos = 0;
    pnj->sell = malloc(sizeof(int) * 5);
    pnj->nb_item = nbitem;
    pnj->is_shop = 1;
    pnj->shop = malloc(sizeof(item_t) * pnj->nb_item);
    for (int i = 0; i != 5; i++) {
        pnj->sell[i] = (i < nbitem) ? 1 : 0;
        if (i < nbitem) {
            pnj->shop[i] = item[i];
            pnj->shop[i].cost = price[i];
            sfSprite_setScale(pnj->shop[i].sprite, (sfVector2f){16.f/23.f, 1});
            sfSprite_centerorigine(pnj->shop[i].sprite);
        }
    }
}

void drawiteminfo_pnj(game_t *game, item_t item, sfVector2f pos)
{
    sfText *text[2] = {NULL, NULL};
    static sfSprite *coin = NULL;

    if (coin == NULL)
        coin = loadbutton("assets/gui/coin.png",
        (sfVector2f) {2, 2}, (sfVector2f){0, 0});
    if (text[0] == NULL) {
        text[0] = createsimpletext("", (sfVector2f)
        {pos.x + 50, pos.y + 300}, 15);
        text[1] = createsimpletext("", (sfVector2f) {pos.x, pos.y + 350},
        15);
    }
    sfText_setString(text[0], my_itoa(item.cost));
    sfText_setString(text[1], item.descrption);
    sfSprite_setPosition(coin, (sfVector2f){pos.x +
    my_strlen(my_itoa(item.cost)) * 50 + 50, pos.y + 300});
    sfRenderWindow_drawText(game->window, text[0], NULL);
    sfRenderWindow_drawSprite(game->window, coin, NULL);
    sfRenderWindow_drawText(game->window, text[1], NULL);
}

int buy_item_pnj(game_t *game, int i)
{
    if (game->player.inventory.gold < pnj_item(i).cost) {
        drawerrormsg(sfRed, "Not enough money", game->window, 50);
        return (1);
    }
    sfSprite_setScale(pnj_item(i).sprite, (sfVector2f) {1, 1});
    sfSprite_setOrigin(pnj_item(i).sprite, (sfVector2f){0, 0});
    if (additem(game, pnj_item(i)) == 0) {
        drawerrormsg(sfRed, "Not enough space in inventory", game->window,
        50);
        return 1;
    } else {
        pnj_item(i).sprite = NULL;
        game->player.inventory.gold -= pnj_item(i).cost;
        return 0;
    }
    return 1;
}

int choice_arrow(void)
{
    int choice = 0;
    static sfClock *cool_d = NULL;

    if (cool_d == NULL)
        cool_d = sfClock_create();
    choice -= (sfKeyboard_isKeyPressed(sfKeyLeft) && TIME(cool_d) > 200);
    choice += (sfKeyboard_isKeyPressed(sfKeyRight) && TIME(cool_d) > 200);
    if (choice)
        sfClock_restart(cool_d);
    return (choice);
}

void draw_shop(game_t *game)
{
    static sfSprite *shop_s = NULL;
    static sfClock *cool_down = NULL;

    if (game->first_pnj++ == 0)
        sfMusic_play(game->music[SHOP_S]), sfMusic_play(game->music[SHOP_S]);
    if (shop_s == NULL)
        shop_s = loadbutton("assets/gui/shop.png",
        (sfVector2f){4, 4}, (sfVector2f){1920/2, 1080/2});
    if (cool_down == NULL)
        cool_down = sfClock_create();
    sfSprite_centerorigine(shop_s);
    sfRenderWindow_drawSprite(game->window, shop_s, NULL);
    for (int i = 0; i < game->pnj[game->player.talking].nb_item; i++) {
        choice_item(game);
        if (shop(game, rect, i) &&
        TIME(cool_down) > 200 && (sfMouse_isButtonPressed(sfMouseLeft) ||
        sfKeyboard_isKeyPressed(sfKeyReturn)))
            pnj_selected.sell[i] = buy_item_pnj(game, i),
            sfClock_restart(cool_down);
    }
}
