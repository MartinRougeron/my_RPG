/*
** EPITECH PROJECT, 2020
** player
** File description:
** castspell
*/

#include "my.h"

spell_t copyspell(spell_t spell, facing_t face, sfVector2f pos, int which)
{
    spell_t res;
    float rotate[4] = {90, 180, 0, 270};

    res.sprite = sfSprite_copy(spell.sprite);
    sfSprite_setPosition(res.sprite, pos);
    res.animclock = sfClock_create();
    res.moveclock = sfClock_create();
    res.cost = spell.cost;
    res.damage = spell.damage;
    res.face = face;
    res.speed = spell.speed;
    res.part = malloc(sizeof(walkanim_t) * NBPARTSPELL);
    res.which = which;
    sfSprite_rotate(res.sprite, rotate[face]);
    for (int i = 0; i != NBPARTSPELL; i++)
        res.part[i] = initpart(face);
    return res;
}

void castspell(game_t *game, int spell)
{
    int i;

    if (spell == SHIELD) {
        game->player.shield = 1;
        return;
    }
    if (spell == LIGHT) {
        game->player.light = 1;
        return;
    }
    for (i = 0; game->player.mage.spell[i].sprite != NULL; i++);
    game->player.mage.spell[i] = 
    copyspell(game->player.mage.loadedspell[spell],
    game->player.face, sfSprite_getPosition(game->player.sprite), spell);
}

void launchspell(game_t *game)
{
    if (game->player.stance == RANGE) {
        if (game->player.mage.select == FIRE) {
            sfMusic_play(game->music[FIRE_S]);
            sfMusic_play(game->music[FIRE_S]);
        } if (game->player.mage.select == ICE) {
            sfMusic_play(game->music[ICE_S]);
            sfMusic_play(game->music[ICE_S]);
        }
    }
    game->player.stat.mana -=
    game->player.mage.loadedspell[game->player.mage.select].cost;
    castspell(game, game->player.mage.select);
    sfClock_restart(game->player.mage.cd[game->player.mage.select]);
}

int canlaunch(game_t *game)
{
    int cd = game->player.mage.loadedspell[game->player.mage.select].cd;

    if (gottheskill(game->player.tree.unlocked, TRANSCENDENCE))
        cd *= 0.8;
    if (sfKeyboard_isKeyPressed(game->key.attack)
    && TIME(game->player.mage.cd[game->player.mage.select]) > cd
    && game->player.stat.mana >=
    game->player.mage.loadedspell[game->player.mage.select].cost) {
        return 1;
    }
    return 0;
}