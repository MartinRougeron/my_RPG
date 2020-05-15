/*
** EPITECH PROJECT, 2020
** showstat
** File description:
** hud
*/

#include "my.h"

void print_hud_health(game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->hud.life_bar);

    for (int i = 0; i < 10; i++) {
        sfSprite_setPosition(game->hud.empty_bar,
        (sfVector2f){i * 30 + 165, 6}),
        sfRenderWindow_drawSprite(game->window, game->hud.empty_bar, NULL);
    }
    rect.width = round(60 * (game->player.stat.health * 1.0
    / (game->player.stat.maxhealth * 1.0)));
    sfSprite_setTextureRect(game->hud.life_bar, rect);
    sfSprite_setPosition(game->hud.life_bar,
    (sfVector2f){165, 10}),
    sfRenderWindow_drawSprite(game->window, game->hud.life_bar,
    NULL);
}

void print_hud_mana(game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->hud.mana_bar);

    for (int i = 0; i < 10; i++) {
        sfSprite_setPosition(game->hud.empty_bar,
        (sfVector2f){i * 30 + 165, 50 - 4}),
        sfRenderWindow_drawSprite(game->window, game->hud.empty_bar, NULL);
    }
    rect.width = round(60 * (game->player.stat.mana * 1.0 /
    (game->player.stat.maxmana * 1.0)));
    sfSprite_setTextureRect(game->hud.mana_bar, rect);
    sfSprite_setPosition(game->hud.mana_bar,
    (sfVector2f){165, 50}),
    sfRenderWindow_drawSprite(game->window, game->hud.mana_bar,
    NULL);
}

void print_hud_stamina(game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->hud.stamina_bar);

    for (int i = 0; i < 10; i++) {
        sfSprite_setPosition(game->hud.empty_bar,
        (sfVector2f){i * 30 + 165, 90 - 4}),
        sfRenderWindow_drawSprite(game->window, game->hud.empty_bar, NULL);
    }
    rect.width = round(60 * (game->player.stat.stamina * 1.0 /
    (game->player.stat.maxstamina)));
    sfSprite_setTextureRect(game->hud.stamina_bar, rect);
    sfSprite_setPosition(game->hud.stamina_bar,
    (sfVector2f){165, 90}),
    sfRenderWindow_drawSprite(game->window, game->hud.stamina_bar,
    NULL);
}

void maketransparent(game_t *game)
{
    int alpha = (game->hide[STAT] == TRUE) ? 128 : 255;

    sfSprite_setTransparent(game->hud.empty_bar, alpha);
    sfSprite_setTransparent(game->hud.hud_main, alpha);
    sfSprite_setTransparent(game->hud.hud_main_end, alpha);
    sfSprite_setTransparent(game->hud.life_bar, alpha);
    sfSprite_setTransparent(game->hud.mage, alpha);
    sfSprite_setTransparent(game->hud.mana_bar, alpha);
    sfSprite_setTransparent(game->hud.stamina_bar, alpha);
    sfSprite_setTransparent(game->hud.warrior, alpha);
}

void print_life(game_t *game)
{
    maketransparent(game);
    sfSprite_setTextureRect(game->hud.life_bar, game->hud.rect);
    sfSprite_setTextureRect(game->hud.mana_bar, game->hud.rect);
    sfSprite_setTextureRect(game->hud.stamina_bar, game->hud.rect);
    if (game->player.stat.health <= 0)
        return;
    sfRenderWindow_drawSprite(game->window, game->hud.hud_main, NULL);
    sfRenderWindow_drawSprite(game->window, (game->player.stance == RANGE) ?
    game->hud.mage : game->hud.warrior, NULL);
    print_hud_health(game);
    print_hud_mana(game);
    print_hud_stamina(game);
    sfSprite_setPosition(game->hud.hud_main_end, (sfVector2f){300 + 165, 3});
    draw_spell(game);
    sfRenderWindow_drawSprite(game->window, game->hud.hud_main_end, NULL);
}