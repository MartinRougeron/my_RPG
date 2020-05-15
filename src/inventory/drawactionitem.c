/*
** EPITECH PROJECT, 2020
** drawactionitem
** File description:
** inv
*/

#include "my.h"

int doaction(game_t *game, sfText *text, int index, int i)
{
    sfText_setColor(text, (sfColor) {255, 255, 255, 255});
    if (TIME(game->player.inventory.clockaction) < 200)
        return 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) ||
    sfKeyboard_isKeyPressed(sfKeyReturn)) {
        if (getitem[index].action[i] == REMOVE)
            dropitemaction(game, index);
        if (getitem[index].action[i] == EQUIP)
            equipitemaction(game, index);
        if (getitem[index].action[i] == UNEQUIP)
            unequipitemaction(game, index);
        if (getitem[index].action[i] == USE)
            useaction(game, index);
        game->player.inventory.lastclick = -1;
        return 1;
    }
    return 0;
}

int moveaction(int select, int nbaction)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (sfKeyboard_isKeyPressed(sfKeyUp) && TIME(clock) > 100) {
        select = (select == 0) ? 0 : select - 1;
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && TIME(clock) > 100) {
        select = (select == nbaction) ? select : select + 1;
        sfClock_restart(clock);
    }
    return select;
}

void setstring(game_t *game, int index, int i, sfText **text)
{
    sfText_setColor(text[i], (sfColor) {255, 255, 255, 200});
    if (i == 0 && getitem[index].action[i] == NONE)
        sfText_setString(text[i], "NONE");
    if (getitem[index].action[i] == USE)
        sfText_setString(text[i], "USE");
    if (getitem[index].action[i] == REMOVE)
        sfText_setString(text[i], "DROP");
    if (getitem[index].action[i] == EQUIP)
        sfText_setString(text[i], "EQUIP");
    if (getitem[index].action[i] == UNEQUIP)
        sfText_setString(text[i], "UNEQUIP");
}

void drawuichoice(game_t *game, int nbaction, sfIntRect rect)
{
    static sfRectangleShape *uichoice = NULL;

    if (uichoice == NULL)
        uichoice = loadui();
    sfRectangleShape_setSize(uichoice, (sfVector2f) {120, nbaction * 25});
    sfRectangleShape_setPosition(uichoice,
    (sfVector2f) {rect.left + rect.width, rect.top});
    DRAW_SHAPE(game->window, uichoice, NULL);
}

void clickonitem(game_t *game, int index, sfIntRect rect)
{
    static sfText **text = NULL;
    int nbaction = getnbaction(game, index);
    static int select = 0;

    selection_music(game);
    if (text == NULL)
        text = loadaction();
    drawuichoice(game, nbaction, rect);
    select = moveaction(select, nbaction - 1);
    for (int i = 0; i != nbaction; i++) {
        setstring(game, index, i, text);
        if (hittext(text[i], (sfWindow *) game->window))
            select = i;
        sfText_setPosition(text[i], (sfVector2f)
        {rect.left + rect.width, rect.top + 5 + 25 * i});
    }
    if (doaction(game, text[select], index, select))
        select = 0;
    for (int i = 0; i != nbaction; i++)
        sfRenderWindow_drawText(game->window, text[i], NULL);
}