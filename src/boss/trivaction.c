/*
** EPITECH PROJECT, 2020
** tri
** File description:
** action
*/

#include "my.h"

void actiontriv(game_t *game)
{
    if (TRIVIATANT.phase == DYING) {
        destroy_triviatan(game);
        if (TIME(TRIVIATANT.phasec) > 5000) {
            cleartriviatan(game);
            return;
        }
    }
    if (TRIVIATANT.phase == SHOT)
        triviatan_shoot(game);
    if (TRIVIATANT.phase == SLEEP)
        if (TIME(TRIVIATANT.phasec) > 4000) {
            sfClock_restart(TRIVIATANT.phasec);
            TRIVIATANT.phase = CHARGE;
        }
    if (TRIVIATANT.phase == CHARGE)
        if (TIME(TRIVIATANT.phasec) > 3000) {
            sfClock_restart(TRIVIATANT.phasec);
            TRIVIATANT.phase = SHOT;
        }
    drawtriviashoot(game);
}