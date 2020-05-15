/*
** EPITECH PROJECT, 2020
** boss
** File description:
** triviatan
*/

#include "my.h"

void triviatan_shoot(game_t *game)
{
    if (TIME(TRIVIATANT.shoot) > 1400) {
        sfClock_restart(TRIVIATANT.shoot);
        addnewshoot(game);
    }
    if (TIME(TRIVIATANT.phasec) > 15000) {
        TRIVIATANT.phase = SLEEP;
        sfClock_restart(TRIVIATANT.phasec);
    }
}

void destroy_triviatan(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(TRIVIATANT.sprite);

    if (TIME(TRIVIATANT.clock) > 200) {
        adddeadparticule(game, (sfVector2f)
        {pos.x + rand() % 100 - 50, pos.y + rand() % 10 - 5},
        (sfColor) {rand() % 160 + 100, rand() % 160 + 100,
        rand() % 250 + 200, rand() % 255 + 200}, 700);
        TRIVIATANT.phase = DYING;
        sfClock_restart(TRIVIATANT.clock);
    }
}

void dodamagetrivia(game_t *game)
{
    sfFloatRect boss = sfSprite_getGlobalBounds(TRIVIATANT.sprite);
    sfFloatRect spell;

    for (int i = 0; i != 30; i++) {
        if (game->player.mage.spell[i].sprite == NULL)
            continue;
        spell = sfSprite_getGlobalBounds(game->player.mage.spell[i].sprite);
        if (sfFloatRect_intersects(&boss, &spell, NULL)) {
            TRIVIATANT.health -= game->player.mage.spell[i].damage;
            TRIVIATANT.health = (TRIVIATANT.health < 0) ? 0 :
            TRIVIATANT.health;
            addtxtdmg(game, game->player.mage.spell[i].damage, (sfVector2f)
            {sfSprite_getPosition(TRIVIATANT.sprite).x,
            sfSprite_getPosition(TRIVIATANT.sprite).y + 20});
            clearspell(&game->player.mage.spell[i]);
        }
    }
    if (TRIVIATANT.health <= 0) {
        if (TRIVIATANT.phase != DYING) sfClock_restart(TRIVIATANT.phasec);
        destroy_triviatan(game);
    }
}

void animtriviatan(game_t *game)
{
    static trivphase_t phase = SHOT;
    trivphase_t newphase = TRIVIATANT.phase;
    sfIntRect rect = sfSprite_getTextureRect(TRIVIATANT.sprite);

    if (phase != newphase) {
        phase = newphase;
        rect.left = 0;
        rect.top = phase * rect.top;
    }
    if (TIME(TRIVIATANT.anim) > 1000) {
        sfClock_restart(TRIVIATANT.anim);
        rect.left += rect.width;
        if (rect.left == (rect.width) * 6) {
            rect.left = 0;
        }
        sfSprite_setTextureRect(TRIVIATANT.sprite, rect);
    }
}

void triviatanfight(game_t *game)
{
    static int first = 0;

    if (game->player.position.map != TRIVIATANFIGHT)
        return;
    if (TRIVIATANT.phase == CLEAR)
        return;
    if (first++ == 0) {
        sfMusic_play(game->music[BOSS_S]),
        sfMusic_pause(game->music[MAIN_S]);
    }
    sfRenderWindow_drawSprite(game->window, TRIVIATANT.sprite, NULL);
    animtriviatan(game);
    dodamagetrivia(game);
    actiontriv(game);
    bosslifebar(game, TRIVIATANT.health, TRIVIATANHEALTH);
}
