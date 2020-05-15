/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_confirm.c
*/

#include "my.h"

sfRectangleShape *create_shape(char *path, sfVector2f position,
sfVector2f scale, sfIntRect frame)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, scale);
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setTexture(shape, sfTexture_createFromFile
    (path, &frame), 1);
    return shape;
}

int wait_confirm(game_t *game, sfEvent confirm, sfIntRect false_r,
sfIntRect true_r)
{
    while (sfRenderWindow_waitEvent(game->window, &confirm)) {
        if (confirm.type == sfEvtKeyPressed) {
            if (confirm.key.code == sfKeyReturn) {
                return 1;
            } else if (confirm.key.code == sfKeyEscape) {
                return 0;
            } else
                continue;
        } else if (confirm.type == sfEvtMouseButtonPressed) {
            if (sfIntRect_contains(&false_r, MOUSE(WINDOW).x,
            MOUSE(WINDOW).y)) {
                return 0;
            } else if (sfIntRect_contains(&true_r, MOUSE(WINDOW).x,
            MOUSE(WINDOW).y))
                return 1;
        }
    }
    return 0;
}

int draw_confirm(game_t *game)
{
    sfEvent confirm;
    sfRectangleShape *shape = create_shape("assets/gui/text_confirm.png",
    (sfVector2f){1920/4, 1080/4}, (sfVector2f){1920/2, 500/2 -4},
    (sfIntRect){0, 0, 128, 64});
    sfRectangleShape *true_b = create_shape("assets/gui/valid_button.png",
    (sfVector2f){1920*3/4, 1080/4}, (sfVector2f){500/2, 500/2},
    (sfIntRect){0, 0, 70, 260/4});
    sfRectangleShape *false_b = create_shape("assets/gui/unvalid_button.png",
    (sfVector2f){500/2, 1080/4}, (sfVector2f){500/2, 500/2} ,
    (sfIntRect){0, 0, 70, 260/4});
    sfText *confirm_msg = loadtxtname("Are you sure ?",
    (sfVector2f){1920/2, 1080/2 - 200}, 50);
    sfIntRect false_r = {280, 296, 150, 200};
    sfIntRect true_r = {1515, 295, 150, 200};

    DRAW_SHAPE(game->window, shape, NULL);
    DRAW_SHAPE(game->window, true_b, NULL);
    DRAW_SHAPE(game->window, false_b, NULL);
    sfRenderWindow_drawText(game->window, confirm_msg, NULL);
    sfRenderWindow_display(game->window);
    return wait_confirm(game, confirm, false_r, true_r);
}
