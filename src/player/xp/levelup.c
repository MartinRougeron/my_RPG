/*
** EPITECH PROJECT, 2020
** xp
** File description:
** level up
*/

#include "my.h"

void drawlevelup(game_t *game)
{
    static sfSprite *gui = NULL;

    if (game->first_lvl++ == 0) {
        sfMusic_play(game->music[LEVELUP_S]);
        sfMusic_play(game->music[LEVELUP_S]);
    }
    if (gui == NULL)
        gui = loadskill("assets/gui/levelup.png",
        (sfVector2f) {0.8, 0.8}, (sfVector2f) {WIDTH / 2, HEIGHT / 2 - 60});
    sfRenderWindow_drawSprite(game->window, gui, NULL);
}

void drawoutline(game_t *game, sfIntRect rect)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setOutlineThickness(shape, 5);
    sfRectangleShape_setOutlineColor(shape, sfYellow);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setPosition(shape,
    (sfVector2f) {rect.left, rect.top});
    sfRectangleShape_setSize(shape,
    (sfVector2f) {rect.width, rect.height});
    DRAW_SHAPE(game->window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void checkclick(game_t *game, int i)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (TIME(clock) < 500) return;
    switch (i) {
    case 0:
        game->player.stat.maxhealth += 10;
        game->player.stat.health += 10;
        break;
    case 1:
        game->player.stat.maxstamina += 10;
        game->player.stat.stamina += 10;
        break;
    case 2:
        game->player.stat.maxmana += 10;
        game->player.stat.mana += 10;
    }
    game->lvltogive -= 1;
    game->screen = (game->lvltogive == 0) ? GAME : game->screen;
}

int moveselect(int select)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && TIME(clock) > 200) {
        select = (select == 0) ? 0 : select - 1;
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && TIME(clock) > 200) {
        select = (select == 2) ? 2 : select + 1;
        sfClock_restart(clock);
    }
    return select;
}

void levelupscreen(game_t *game)
{
    sfIntRect rect[4] = {{793, 608, 67 * 0.8, 68 * 0.8},
    {940, 612, 61 * 0.8, 65 * 0.8}, {1065, 610, 60 * 0.8, 69 * 0.8}};
    sfVector2i pos = sfMouse_getPosition((sfWindow *) game->window);
    static int select = 0;

    if (game->lvltogive <= 0) {
        select = 0;
        game->first_lvl = 0;
        return;
    }
    game->screen = LEVELUP;
    game->player.state = IDLE;
    drawlevelup(game);
    drawoutline(game, rect[select]);
    select = moveselect(select);
    for (int i = 0; i != 3; i++)
        if (sfIntRect_contains(&rect[i], pos.x, pos.y))
            select = i;
    if (sfMouse_isButtonPressed(sfMouseLeft)
    || sfKeyboard_isKeyPressed(sfKeyReturn)) checkclick(game, select);
}