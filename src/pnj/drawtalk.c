/*
** EPITECH PROJECT, 2020
** pnj
** File description:
** talk
*/

#include "my.h"

int getsizemax(char *text)
{
    int max = 0;

    for (int i = 0, line = 0, count = 0; text[i] != 0; i++) {
        count += 1;
        if (count >= max)
            max = count;
        if (i >= 20 * (line + 1) && text[i] == ' ') {
            line++;
            count = 0;
        }
    }
    return max;
}

int getlinenb(char *text)
{
    int line = 0;

    for (int i = 0; text[i] != 0; i++) {
        if (i >= 20 * (line + 1) && text[i] == ' ')
            line++;
    }
    return line;
}

void writemsg(pnj_t *pnj, sfClock **end, sfText *text)
{
    static char *string = NULL;
    static sfClock *clock = NULL;
    static int i = 0, line = 0;

    string = (string == NULL) ? my_malloc(my_strlen(pnj->text) + 10) : string;
    clock = (clock == NULL) ? sfClock_create() : clock;
    if (TIME(clock) > 10) {
        string[i] = pnj->text[i];
        if (i > 20 * (line + 1) && string[i] == ' ') {
            string[i] = '\n';
            line += 1;
        } sfText_setString(text, string);
        sfClock_restart(clock);
        if (pnj->text[++i] == 0) { free(string);
            *end = sfClock_create();
            i = 0;
            line = 0;
            string = NULL;
        }
    }
}

void placetext(pnj_t *pnj, sfText *text, sfRectangleShape *gui, game_t *game)
{
    sfVector2f vec;

    vec = sfSprite_getPosition(pnj->sprite);
    sfRectangleShape_setSize(gui, (sfVector2f)
    {getsizemax(pnj->text) * 15 + 30, 60 + 20 * getlinenb(pnj->text)});
    sfRectangleShape_setPosition(gui, (sfVector2f)
    {vec.x - 100, vec.y - 120 - 20 * getlinenb(pnj->text)});
    sfText_setPosition(text, (sfVector2f)
    {vec.x - 70, vec.y - 105 - 20 * getlinenb(pnj->text)});
    DRAW_SHAPE(game->window, gui, NULL);
    sfRenderWindow_drawText(game->window, text, NULL);
}

void drawtext(pnj_t *pnj, game_t *game)
{
    static sfRectangleShape *gui = NULL;
    static sfText *text;
    static sfClock *end = NULL;

    if (gui == NULL) {
        gui = loadguitalk();
        text = loadtexttalk();
    }
    placetext(pnj, text, gui, game);
    if (end != NULL) {
        if (TIME(end) > 1000) {
            game->player.talking = -1;
            sfText_setString(text, "");
            end = NULL;
        }
        return;
    }
    writemsg(pnj, &end, text);
}