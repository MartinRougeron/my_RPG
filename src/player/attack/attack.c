/*
** EPITECH PROJECT, 2020
** player
** File description:
** attack
*/

#include "my.h"
void norm_isatack(game_t *game, sfIntRect rect)
{
    game->player.state = ATTACK;
    rect.width = 36;
    rect.left = 0;
    rect.top = 144 + game->player.face * 36;
    game->player.stat.stamina -= 10;
    sfSprite_setTextureRect(game->player.sprite, rect);
    sfClock_restart(game->player.attackclock);
    sfClock_restart(game->player.clock_attack);
}

int islaunch(game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->player.sprite);

    if (game->player.stance == MELEE) return 0;
    if (TIME(game->player.spellclock) < ANIMSPELL * NBFRAMESPELL) return 1;
    if (game->player.state == CASTING) {
        rect.left = 0;
        rect.top = 144 * 2;
        launchspell(game);
        game->player.state = IDLE;
        sfSprite_setTextureRect(game->player.sprite, rect);
    } if (canlaunch(game)) {
        game->player.state = CASTING;
        sfClock_restart(game->player.spellclock);
        rect.width = (PLAYERFACE == EST || PLAYERFACE == WEST) ? 24 : 30;
        rect.left = 0;
        rect.top = 144 * 3 + game->player.face * 36;
        sfSprite_setTextureRect(game->player.sprite, rect);
        return 1;
    }
    return 0;
}

int isattack(game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->player.sprite);

    if (game->player.stance == RANGE)
        return 0;
    if (TIME(game->player.attackclock) < ANIMATTACK * 3)
        return 1;
    if (game->player.state == ATTACK) anim_player_attack(game, rect);
    if (sfKeyboard_isKeyPressed(game->key.attack) &&
    TIME(game->player.clock_attack) > 300 &&
    game->player.stat.stamina > 10) {
        norm_isatack(game, rect);
        return 1;
    }
    return 0;
}