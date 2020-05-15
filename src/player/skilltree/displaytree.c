/*
** EPITECH PROJECT, 2020
** skilltree
** File description:
** display
*/

#include "my.h"

void placevertex(sfVertex *pos, sfVertex *pos2, int i)
{
    sfVector2f point[9][2] = {
        {{700, 715}, {700, 615}},
        {{1150, 715}, {1150, 615}},
        {{725, 715}, {925, 615}},
        {{1125, 715}, {925, 615}},
        {{700, 515}, {700, 415}},
        {{1150, 515}, {1150, 415}},
        {{925, 515}, {925, 215}},
        {{700, 315}, {700, 215}},
        {{1150, 315}, {1150, 215}}
    };
    pos->position = point[i][0];
    pos2->position = point[i][1];
}

void drawline(sfVertex *pos, sfVertex *pos2, int i, game_t *game)
{
    int dependence[9] = {
        ADRENALINE_RUSH, PRESENCE_OF_MIND,
        ADRENALINE_RUSH, PRESENCE_OF_MIND,
        PARADE, TRANSCENDENCE,
        SECOND_WIND, CRITICAL, ARCANOPULSE
    };
    if (!gottheskill(game->player.tree.unlocked, dependence[i])) {
        pos->color = sfBlack;
        pos2->color = sfBlack;
    } else {
        pos->color = sfYellow;
        pos2->color = sfYellow;
    }
}

void drawskill(game_t *game)
{
    for (int i = 0; i != NBSKILL; i++) {
        if (!gottheskill(game->player.tree.unlocked, i))
            sfRenderWindow_drawSprite(game->window,
            game->player.tree.skill[i].unlearned, NULL);
        else
            sfRenderWindow_drawSprite(game->window,
            game->player.tree.skill[i].sprite, NULL);
    }
}

void drawclassicsprite(game_t *game)
{
    static sfSprite *gui = NULL;

    if (gui == NULL) {
        gui = loadbutton("assets/skill/gui.png",
        (sfVector2f) {1.2, 1}, (sfVector2f) {570, 80});
    }
    sfRenderWindow_drawSprite(game->window, gui, NULL);
}

void displaytree(game_t *game)
{
    sfVertex pos1;
    sfVertex pos2;
    sfVertexArray *array = sfVertexArray_create();
    sfText *text = loadnbofcmpt("Skill points :", (sfVector2f) {925, 720}, 20);
    sfText *nb = loadnbofcmpt(my_itoa(game->player.tree.point),
    (sfVector2f) {925, 770}, 25);

    drawclassicsprite(game);
    sfVertexArray_setPrimitiveType(array, sfLines);
    for (int i = 0; i != 9; i++) {
        placevertex(&pos1, &pos2, i);
        drawline(&pos1, &pos2, i, game);
        sfVertexArray_append(array, pos1);
        sfVertexArray_append(array, pos2);
        sfRenderWindow_drawVertexArray(game->window, array, NULL);
        sfVertexArray_destroy(array);
        array = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(array, sfLines);
    }
    displaytree_r(game, text, nb);
}