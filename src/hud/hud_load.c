/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hud_load.c
*/

#include "my.h"

void spell_load(game_t *game)
{
    game->hud.type.fire = loadbutton("assets/spell/fire.png",
    (sfVector2f){1.75, 1.75}, (sfVector2f){32, 155});
    game->hud.type.ice = loadbutton("assets/spell/ice.png",
    (sfVector2f){1.75, 1.75}, (sfVector2f){32, 155});
    game->hud.type.light = loadbutton("assets/spell/light.png",
    (sfVector2f){1.75, 1.75}, (sfVector2f){32, 155});
    game->hud.type.shield = loadbutton("assets/spell/shield.png",
    (sfVector2f){1.75, 1.75}, (sfVector2f){32, 155});
    game->hud.spell_choice = loadbutton("assets/gui/box.png",
    (sfVector2f){1.75, 1.75}, (sfVector2f){25, 150});
}

void load_hud2(game_t *game)
{
    game->hud.inventory_sprite = loadbutton(
    "./assets/menu/inventory/inventory.png",
    (sfVector2f){512/191 * 2, 512/233 * 2}, (sfVector2f){0, 0});
    sfSprite_centerorigine(game->hud.inventory_sprite);
    game->hud.rect = sfSprite_getTextureRect(game->hud.life_bar);
    spell_load(game);
    game->hud.gold = loadbutton("./assets/gui/coin.png", (sfVector2f) {4, 4},
    (sfVector2f) {1261, 35});
    game->hud.goldtxt = loadtext("", (sfVector2f) {1, 1},
    (sfVector2f) {1335, 44}, 30);
    sfText_setFont(game->hud.goldtxt, game->font.menu);
}

void load_hud(game_t *game)
{
    game->hud.hud_main = loadbutton("./assets/gui/bar.png",
    (sfVector2f){2, 2}, (sfVector2f){0, 0});
    game->hud.life_bar = loadbutton("./assets/gui/life_bar.png",
    (sfVector2f){5, 2.2}, (sfVector2f){0, 0});
    game->hud.mana_bar = loadbutton("./assets/gui/mana_bar.png",
    (sfVector2f){5, 2.2}, (sfVector2f){0, 0});
    game->hud.stamina_bar = loadbutton("./assets/gui/stamina_bar.png",
    (sfVector2f){5, 2.2}, (sfVector2f){0, 0});
    game->hud.empty_bar = loadbutton("./assets/gui/empty_bar.png",
    (sfVector2f){5, 2}, (sfVector2f){0, 0});
    game->hud.hud_main_end = loadbutton("./assets/gui/end_bar.png",
    (sfVector2f){2, 2}, (sfVector2f){0, 3});
    game->hud.warrior = loadbutton("./assets/gui/warrior.png",
    (sfVector2f){3, 3}, (sfVector2f){35, 40});
    game->hud.mage = loadbutton("./assets/gui/mage.png",
    (sfVector2f){0.1, 0.1}, (sfVector2f){30, 30});
    load_hud2(game);
}