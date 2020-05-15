/*
** EPITECH PROJECT, 2020
** map
** File description:
** change map
*/

#include "my.h"

sfVector2f checkchangemapy(game_t *game, sfVector2f pos)
{
    if (pos.x >= 1920) {
        if (game->player.position.x + 1 >=
        game->map.max[game->player.position.map].x || game->is_tuto != NO)
            pos.x = 1880;
        else {
            game->player.position.x += 1;
            pos.x = 60;
        }
    }
    if (pos.y >= 1080) {
        if (game->player.position.y + 1 >=
        game->map.max[game->player.position.map].y || game->is_tuto != NO)
            pos.y = 1040;
        else {
            game->player.position.y += 1;
            pos.y = 20;
        }
    }
    return pos;
}

sfVector2f checkchangemapx(game_t *game, sfVector2f pos)
{
    if (pos.y <= 0) {
        if (game->player.position.y - 1 < 0 || game->is_tuto != NO)
            pos.y = 70;
        else {
            game->player.position.y -= 1;
            pos.y = 1010;
        }
    }
    if (pos.x <= 0) {
        if (game->player.position.x - 1 < 0 || game->is_tuto != NO)
            pos.x = 60;
        else {
            game->player.position.x -= 1;
            pos.x = 1880;
        }
    }
    return pos;
}

int checkchangemap(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player.sprite);

    if (game->player.position.map == FANTOME ||
    game->player.position.map == FARWATER)
        return 1;
    pos = checkchangemapy(game, pos);
    pos = checkchangemapx(game, pos);
    if (cmpvector2f(sfSprite_getPosition(game->player.sprite), pos)) {
        sfSprite_setPosition(game->player.sprite, pos);
        return 1;
    }
    pos = docolidewithblock(game, pos,
    sfSprite_getPosition(game->player.sprite));
    sfSprite_setPosition(game->player.sprite, pos);
    return 0;
}

void spawnenemie(game_t *game)
{
    int enemietospawn = rand() % 4;
    int levelenemie, health, damage;

    for (int i = 0; i != enemietospawn; i++) {
        levelenemie = game->player.level + rand() % 2;
        if (levelenemie >= NBENEMIETOLOAD)
            levelenemie = NBENEMIETOLOAD - 1;
        health = levelenemie * 4 + rand() % levelenemie + 2 + 2;
        damage = health / 2;
        loadenemie(game, (enemieoption_t) {(drop_t)
        {levelenemie * 1.0 * (rand() % 200 + 100) * 1.0 / 100,
        levelenemie * 1.0 * (rand() % 200 + 100) * 1.0 / 100},
        (pos_t) {game->player.position.map, game->player.position.x,
        game->player.position.y, 15 + rand() % 4 - 2, 15 - 2 * i},
        levelenemie, damage, health});
    }
}

void changemapevent(game_t *game)
{
    if (checkchangemap(game))
        return;
    if (game->is_tuto != NO)
        return;
    destroy_enemie(game);
    for (int i = 0; i != 30; i++)
        if (game->player.mage.spell[i].sprite != NULL)
            clearspell(&game->player.mage.spell[i]);
    if (game->player.position.map == WORLD)
        spawnenemie(game);
}