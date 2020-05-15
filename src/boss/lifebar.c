/*
** EPITECH PROJECT, 2020
** boss life bar
** File description:
** life bar
*/

#include "my.h"

sfSprite **load_lifebar(void)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 2);

    sprite[0] = loadbutton("assets/player/bossbar.png",
    (sfVector2f) {1.5, 1.5}, (sfVector2f) {712, 1010});
    sprite[1] = loadbutton("assets/player/bosslifebar.png",
    (sfVector2f) {1.5, 1.5}, (sfVector2f) {743, 1040});
    return sprite;
}

void bosslifebar(game_t *game, int hp, int maxhp)
{
    static sfSprite **sprite = NULL;
    sfIntRect rect;

    if (sprite == NULL)
        sprite = load_lifebar();
    rect = sfSprite_getTextureRect(sprite[1]);
    rect.width = 301 * (hp * 1.0 / maxhp);
    sfSprite_setTextureRect(sprite[1], rect);
    sfRenderWindow_drawSprite(game->window, sprite[0], NULL);
    sfRenderWindow_drawSprite(game->window, sprite[1], NULL);
}