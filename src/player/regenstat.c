/*
** EPITECH PROJECT, 2020
** regen
** File description:
** stat
*/

#include "my.h"

void regenstamina(game_t *game)
{
    int regen =
    (gottheskill(game->player.tree.unlocked, ADRENALINE_RUSH)) ? 7 : 5;

    if (TIME(game->player.stat.regenstamina) < 400)
        return;
    sfClock_restart(game->player.stat.regenstamina);
    if (game->player.stat.stamina + regen <= game->player.stat.maxstamina)
        game->player.stat.stamina += regen;
    else
        game->player.stat.stamina = game->player.stat.maxstamina;
}

void regenmana(game_t *game)
{
    int regen =
    (gottheskill(game->player.tree.unlocked, PRESENCE_OF_MIND)) ? 7 : 5;

    if (!game->player.learnmagic)
        return;
    if (TIME(game->player.stat.regenmana) < 400)
        return;
    sfClock_restart(game->player.stat.regenmana);
    if (game->player.stat.mana + regen <= game->player.stat.maxmana)
        game->player.stat.mana += regen;
    else
        game->player.stat.mana = game->player.stat.maxmana;
}

void regenhealth(game_t *game)
{
    if (!gottheskill(game->player.tree.unlocked, SECOND_WIND))
        return;
    if (TIME(game->player.combat) < TIMEINCOMBAT)
        return;
    if (TIME(game->player.stat.regenhealth) < 1000)
        return;
    sfClock_restart(game->player.stat.regenhealth);
    if (game->player.stat.health + 5 <= game->player.stat.maxhealth)
        game->player.stat.health += 5;
    else
        game->player.stat.health = game->player.stat.maxhealth;
}

void regenstat(game_t *game)
{
    regenmana(game);
    regenstamina(game);
    regenhealth(game);
}
