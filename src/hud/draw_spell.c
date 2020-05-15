/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_spell.c
*/

#include "my.h"

void draw_spell(game_t *game)
{
    if (game->player.stance == RANGE) {
        sfRenderWindow_drawSprite(game->window, game->hud.spell_choice, NULL);
        switch (game->player.mage.select) {
        case LIGHT:
            sfRenderWindow_drawSprite(game->window, game->hud.type.light,
            NULL);
            break;
        case FIRE:
            sfRenderWindow_drawSprite(game->window, game->hud.type.fire, NULL);
            break;
        case ICE:
            sfRenderWindow_drawSprite(game->window, game->hud.type.ice, NULL);
            break;
        case SHIELD:
            sfRenderWindow_drawSprite(game->window,
            game->hud.type.shield, NULL);
            break;
        }
    }
}