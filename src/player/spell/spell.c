/*
** EPITECH PROJECT, 2020
** player
** File description:
** spell
*/

#include "my.h"

spell_t *load_spell(spell_t *spell, sfIntRect rect)
{
    spell[1].sprite = sfSprite_create();
    sfSprite_setTexture(spell[1].sprite, sfTexture_createFromFile
    ("assets/attack/ice.png", NULL), sfFalse);
    sfSprite_centerorigine(spell[1].sprite);
    sfSprite_setTextureRect(spell[1].sprite, rect);
    sfSprite_setScale(spell[1].sprite, (sfVector2f) {3, 3});
    spell[1].speed = 1.4;
    spell[1].cd = 500;
    spell[1].range = 10;
    spell[2].cost = SHIELDSPELLCOST;
    spell[2].cd = SHIELDSPELLCD;
    spell[3].cd = LIGHTSPELLCD;
    spell[3].cost = LIGHTSPELLCOST;
    return (spell);
}

spell_t *loadbasicspell(void)
{
    spell_t *spell = malloc(sizeof(spell_t) * 4);
    sfIntRect rect = (sfIntRect) {0, 0, 23, 16};

    spell[0].cost = FIRESPELLCOST;
    spell[0].damage = FIRESPELLDAMAGE;
    spell[0].sprite = sfSprite_create();
    sfSprite_setTexture(spell[0].sprite, sfTexture_createFromFile
    ("assets/attack/fire.png", NULL), sfFalse);
    sfSprite_setTextureRect(spell[0].sprite, rect);
    sfSprite_centerorigine(spell[0].sprite);
    spell[0].speed = 0.8;
    spell[0].cd = 200;
    spell[0].range = 30;
    sfSprite_setScale(spell[0].sprite, (sfVector2f) {3, 3});
    spell[1].cost = ICESPELLCOST;
    spell[1].damage = ICESPELLDAMAGE;
    spell = load_spell(spell, rect);
    return spell;
}

void checkspell(spell_t *spell, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(spell->sprite);
    int enemie;

    if (pos.x > 2000 || pos.x < -100) {
        clearspell(spell);
        return;
    }
    if (pos.y > 1150 || pos.y < -100) {
        clearspell(spell);
        return;
    }
    if ((enemie = dospellhit(spell, game)) != -1) {
        spellhit(spell, game);
    }
}

void movespell(game_t *game)
{
    float elapsed;

    for (int i = 0; i != 30; i++) {
        if (game->player.mage.spell[i].sprite == NULL) continue;
        elapsed = sfTime_asMilliseconds
        (sfClock_restart(game->player.mage.spell[i].moveclock));
        if (game->player.mage.spell[i].face == NORTH)
            sfSprite_move(game->player.mage.spell[i].sprite, (sfVector2f)
            {0, -elapsed * game->player.mage.spell[i].speed});
        if (game->player.mage.spell[i].face == SOUTH)
            sfSprite_move(game->player.mage.spell[i].sprite, (sfVector2f)
            {0, elapsed * game->player.mage.spell[i].speed});
        if (game->player.mage.spell[i].face == EST)
            sfSprite_move(game->player.mage.spell[i].sprite, (sfVector2f)
            {-elapsed * game->player.mage.spell[i].speed, 0});
        if (game->player.mage.spell[i].face == WEST)
            sfSprite_move(game->player.mage.spell[i].sprite, (sfVector2f)
            {elapsed * game->player.mage.spell[i].speed, 0});
        checkspell(&game->player.mage.spell[i], game);
    }
}

void animspell(game_t *game)
{
    for (int i = 0; i != 30; i++) {
        if (game->player.mage.spell[i].sprite == NULL)
            continue;
        animpart(game, game->player.mage.spell[i]);
        sfRenderWindow_drawSprite(game->window,
        game->player.mage.spell[i].sprite, NULL);
    }
}