/*
** EPITECH PROJECT, 2020
** util
** File description:
** display
*/

#include "my.h"

sfRectangleShape *loadmsghud(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    shape = sfRectangleShape_create();
    sfRectangleShape_setFillColor(shape, (sfColor) {0, 0, 0, 128});
    sfRectangleShape_setOutlineThickness(shape, 4);
    sfRectangleShape_setOutlineColor(shape, (sfColor) {0, 0, 0, 255});
    sfRectangleShape_setSize(shape, (sfVector2f) {400, 300});
    sfRectangleShape_centerorigine(shape);
    sfRectangleShape_setPosition(shape, (sfVector2f) {WIDTH / 2, 980});
    return shape;
}

void drawmessage(game_t *game, char *msg, int end)
{
    static sfText *text[2] = {NULL, NULL};

    if (text[0] == NULL) {
        text[0] = sfText_create();
        sfText_setColor(text[0], sfWhite);
        sfText_setFont(text[0], sfFont_createFromFile("assets/menu.ttf"));
        sfText_setCharacterSize(text[0], 15);
        sfText_setPosition(text[0], (sfVector2f) {770, 885 - 50});
        text[1] = sfText_create();
        sfText_setColor(text[1], sfWhite);
        sfText_setFont(text[1], sfFont_createFromFile("assets/menu.ttf"));
        sfText_setCharacterSize(text[1], 15);
        sfText_setPosition(text[1], (sfVector2f) {770, 1030});
        sfText_setString(text[1], "Press any key to continue");
    }
    sfText_setString(text[0], msg);
    sfRenderWindow_drawText(game->window, text[0], NULL);
    if (end)
        sfRenderWindow_drawText(game->window, text[1], NULL);
}

void fillmesage(game_t *game, int *end, char *send, int *i)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (TIME(clock) > 10) {
        send[*i] = game->player.successmsg[*i];
        *i += 1;
        if (game->player.successmsg[*i] == 0)
            *end = 1;
        sfClock_restart(clock);
    }
}

int getmessage(game_t *game)
{
    static int i = 0, end = 0;
    static char *send = NULL;

    if (send == NULL)
        send = my_malloc(my_strlen(game->player.successmsg) + 1);
    if (my_strncmp(send, game->player.successmsg, i) != 0) {
        send = my_malloc(my_strlen(game->player.successmsg) + 1);
        i = 0;
    }
    if (end == 1) {
        processendmsg(game, &end, send, &i);
        send = NULL;
        return 1;
    }
    fillmesage(game, &end, send, &i);
    drawmessage(game, send, end);
    return 0;
}

void drawsuccessmsg(game_t *game)
{
    static sfRectangleShape *shape = NULL;

    if (shape == NULL)
        shape = loadmsghud();
    if (game->player.successmsg == NULL)
        return;
    DRAW_SHAPE(game->window, shape, NULL);
    if (getmessage(game))
        game->player.successmsg = NULL;
}