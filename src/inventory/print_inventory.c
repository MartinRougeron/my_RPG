/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_inventory.c
*/

#include "my.h"

void print_items(game_t *game, int i, sfIntRect rect)
{
    if (getitem[i].sprite == NULL)
        return;
    sfSprite_setPosition(getitem[i].sprite,
    (sfVector2f){rect.left, rect.top});
    sfRenderWindow_drawSprite(game->window,
    getitem[i].sprite, NULL);
}

sfIntRect create_hitbox(int i)
{
    sfIntRect rect;
    sfIntRect hitbox[9] = {
        {1143, 319, 70, 70}, {1143, 426, 70, 70}, {1143, 528, 70, 70},
        {1143, 627, 70, 70}, {1047, 473, 70, 70}, {1243, 372, 70, 70},
        {1062, 763, 70, 73}, {1143, 763, 70, 73}, {1226, 763, 70, 73}
    };

    if (i >= INVENTORY_SIZE)
        return hitbox[i - INVENTORY_SIZE];
    rect.top = (i / 4) * 80 + 1080 / 2 - 4 * 64 + 50 - 16 - 4;
    rect.left = (i % 4) * 80 + 1920 / 2 - 256 +  - 32 - 16 - 4;
    rect.width = 62;
    rect.height = 64;
    return rect;
}

int moveinventory(int select)
{
    static sfClock *clock = NULL;
    int stock = select;

    if (clock == NULL)
        clock = sfClock_create();
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && TIME(clock) > 200)
        select = (select == 0) ? 0 : select - 1;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && TIME(clock) > 200)
        select = (select + 1 >= INVENTORY_SIZE + NBSLOT) ? select : select + 1;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && TIME(clock) > 200)
        select = (select - 4 < 0) ? select : select - 4;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && TIME(clock) > 200)
        select = (select + 4 > INVENTORY_SIZE) ? select : select + 4;
    if (stock != select)
        sfClock_restart(clock);
    return select;
}

int print_inventory2(game_t *game, int select)
{
    sfRenderWindow_drawSprite(game->window, game->hud.inventory_sprite, NULL);
    if (getitem[select].sprite != NULL)
        drawiteminfo(game, getitem[select]);
    for (int i = 0; i != INVENTORY_SIZE + NBSLOT; i++) {
        if (hitrect(create_hitbox(i), game->window))
            select = i;
        if (getitem[i].sprite == NULL)
            continue;
        print_items(game, i, create_hitbox(i));
    }
    drawoutline(game, create_hitbox(select));
    if ((sfMouse_isButtonPressed(sfMouseRight)
    || sfKeyboard_isKeyPressed(sfKeyReturn)) && getitem[select].sprite != NULL
    && game->player.inventory.lastclick == -1) {
        sfClock_restart(game->player.inventory.clockaction);
        game->player.inventory.lastclick = select;
    }
    drawstat(game);
    return select;
}

void print_inventory(game_t *game)
{
    sfVector2u position = sfRenderWindow_getSize(game->window);
    static sfText *name = NULL;
    static int select = 0;

    if (name == NULL)
        name = loadtxtname(game->player.name, (sfVector2f){960, 180}, 50);
    sfSprite_setPosition(game->hud.inventory_sprite,
    (sfVector2f){position.x/2, position.y/2 + 50});
    if (game->player.inventory.lastclick == -1)
        select = moveinventory(select);
    select = print_inventory2(game, select);
    if (game->player.inventory.lastclick != -1) {
        clickonitem(game, game->player.inventory.lastclick,
        create_hitbox(game->player.inventory.lastclick));
    } else
        game->first_item = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        game->player.inventory.lastclick = -1;
    sfRenderWindow_drawText(game->window, name, NULL);
}