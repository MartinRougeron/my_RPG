/*
** EPITECH PROJECT, 2020
** skilltree
** File description:
** tree
*/

#include "my.h"

void hoverskill(skill_t skill, game_t *game)
{
    static sfSprite *gui = NULL;
    sfSprite *ic = sfSprite_copy(skill.sprite);
    sfText *text[2];

    if (gui == NULL)
        gui = loadskill("assets/skill/gui.png",
        (sfVector2f) {1.2, 0.2}, (sfVector2f) {930, 950});
    sfRenderWindow_drawSprite(game->window, gui, NULL);
    sfSprite_setPosition(ic, (sfVector2f) {660, 950});
    sfRenderWindow_drawSprite(game->window, ic, NULL);
    sfSprite_destroy(ic);
    text[0] = loadtxtname(skill.name, (sfVector2f) {965, 920}, 24);
    text[1] = loadtxtname(skill.description, (sfVector2f) {965, 950}, 15);
    sfRenderWindow_drawText(game->window, text[0], NULL);
    sfRenderWindow_drawText(game->window, text[1], NULL);
}

void learnskill(skill_t skill, game_t *game, int i)
{
    if (TIME(game->player.tree.clickonmenu) < 200)
        return;
    sfClock_restart(game->player.tree.clickonmenu);
    if (gottheskill(game->player.tree.unlocked, i))
        return;
    if (game->player.tree.point <= 0)
        return;
    if (!gotdependence(skill.dependence, game->player.tree.unlocked))
        return;
    addskill(game, i);
    game->player.tree.point -= 1;
}

int moveskill(int select)
{
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && TIME(clock) > 200) {
        select = (select == 0) ? 0 : select - 1;
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && TIME(clock) > 200) {
        select = (select == 9) ? 9 : select + 1;
        sfClock_restart(clock);
    }
    return select;
}

void inmenutree(game_t *game)
{
    static int skill = 0;

    displaytree(game);
    skill = moveskill(skill);
    for (int i = 0; i != NBSKILL; i++)
        if (hitsprite(game->player.tree.skill[i].sprite,
        (sfWindow *) game->window))
            skill = i;
    hoverskill(game->player.tree.skill[skill], game);
    if (sfMouse_isButtonPressed(sfMouseLeft)
    || sfKeyboard_isKeyPressed(sfKeyReturn))
        learnskill(game->player.tree.skill[skill], game, skill);
}