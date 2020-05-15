/*
** EPITECH PROJECT, 2020
** quest
** File description:
** draw
*/

#include "my.h"

sfSprite **loadhudquest(void)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 2);

    sprite[0] = loadbutton("assets/gui/quest.png",
    (sfVector2f) {1.01, 1.01}, (sfVector2f) {0, 0});
    sprite[1] = loadbutton("assets/gui/quest1.png",
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    sfSprite_centerorigine(sprite[0]);
    sfSprite_centerorigine(sprite[1]);
    sfSprite_setPosition(sprite[0], (sfVector2f) {WIDTH / 2, HEIGHT / 2});
    sfSprite_setPosition(sprite[1], (sfVector2f) {WIDTH / 2, HEIGHT / 2});
    return sprite;
}

sfText **loadtextquest(game_t *game)
{
    sfText **txt = malloc(sizeof(sfText *) * 2);

    txt[0] = loadtxtname("Objectives", (sfVector2f)
    {WIDTH / 2, HEIGHT / 2 - 180}, 30);
    txt[1] = sfText_create();
    sfText_setCharacterSize(txt[1], 20);
    sfText_setColor(txt[1], sfBlack);
    sfText_setPosition(txt[1], (sfVector2f) {672, 423});
    sfText_setFont(txt[1], game->font.menu);
    return txt;
}

sfSprite **loadarrowquest(void)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 2);

    sprite[0] = loadbutton("assets/gui/arrowkeyleft.png",
    (sfVector2f) {1, 1}, (sfVector2f) {676, 656});
    sprite[1] = loadbutton("assets/gui/arrowkeyright.png",
    (sfVector2f) {1, 1}, (sfVector2f) {1176, 656});
    return sprite;
}

void selectquest(game_t *game, int nbquest, int *quest, sfText *text)
{
    static sfSprite **sprite = NULL;
    static sfClock *clock;

    if (sprite == NULL) {
        sprite = loadarrowquest();
        clock = sfClock_create();
    }
    if (quest[0] == -1) {
        sfText_setString(text, "You got no quest :'(");
        return;
    }
    quest_nbr(game, sprite, nbquest, clock);
    sfText_setString(text, game->quest_description[quest[game->questselect]]);
}

void drawquest(game_t *game)
{
    static sfSprite **hud = NULL;
    static sfText **text;
    int nbquest = 0;
    int *quest = getactualquest(game, &nbquest);

    if (hud == NULL) {
        hud = loadhudquest();
        text = loadtextquest(game);
    }
    restarclock(game);
    sfRenderWindow_drawSprite(game->window, hud[0], NULL);
    sfRenderWindow_drawSprite(game->window, hud[1], NULL);
    sfRenderWindow_drawText(game->window, text[0], NULL);
    selectquest(game, nbquest, quest, text[1]);
    sfRenderWindow_drawText(game->window, text[1], NULL);
}