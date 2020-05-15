/*
** EPITECH PROJECT, 2020
** dragon
** File description:
** clear
*/

#include "my.h"

void clear_dragon(dragon_t *dragon, game_t *game)
{
    game->screen = END_SCREEN;
    game->player.successmsg = "The dragon has respawn";
    sfClock_destroy(dragon->anim);
    sfClock_destroy(dragon->die);
    sfClock_destroy(dragon->phase);
    sfClock_destroy(dragon->shoot);
    sfClock_destroy(dragon->takedmg);
    sfSprite_destroy(dragon->dragon);
    dragon->dragon = NULL;
    game->dragon = create_dragon();
}