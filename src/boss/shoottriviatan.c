/*
** EPITECH PROJECT, 2020
** triviatan
** File description:
** shoot
*/

#include "my.h"

plasma_t checkcolisionplasma(game_t *game, plasma_t bullet)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->player.sprite);
    sfFloatRect plasma = sfSprite_getGlobalBounds(bullet.sprite);

    if (sfFloatRect_intersects(&rect, &plasma, NULL)) {
        if (game->player.shield == 0) {
            addtxtdmg(game, 20, sfSprite_getPosition(game->player.sprite));
            game->player.stat.health -= 20;
        }
        sfSprite_destroy(bullet.sprite);
        bullet.sprite = NULL;
    }
    return bullet;
}

plasma_t *destroyplasma(plasma_t *bullet)
{
    for (int i = 0; i != 51; i++) {
        if (i == 50) {
            free(bullet);
            bullet = NULL;
            break;
        }
        if (bullet[i].sprite != NULL)
            break;
    }
    return bullet;
}

plasma_t *moveandrendershoot(game_t *game, plasma_t *bullet)
{
    sfVector2f posshot;
    float elapsed;

    for (int i = 0; i != 50; i++) {
        if (bullet[i].sprite == NULL)
            continue;
        elapsed = sfTime_asMilliseconds(sfClock_restart(bullet[i].clock));
        sfSprite_move(bullet[i].sprite, (sfVector2f) {bullet[i].speed.x *
        (elapsed / 20), bullet[i].speed.y * (elapsed / 20)});
        sfRenderWindow_drawSprite(game->window, bullet[i].sprite, NULL);
        posshot = sfSprite_getPosition(bullet[i].sprite);
        bullet[i] = checkcolisionplasma(game, bullet[i]);
        if (bullet[i].sprite == NULL)
            continue;
        if (posshot.x > 1920 || posshot.x < 0 || posshot.y > 1080) {
            sfSprite_destroy(bullet[i].sprite);
            bullet[i].sprite = NULL;
        }
    }
    return destroyplasma(bullet);
}

void drawtriviashoot(game_t *game)
{
    for (int i = 0; i != 10; i++)
        if (TRIVIATANT.bullet[i] != NULL)
            TRIVIATANT.bullet[i] =
            moveandrendershoot(game, TRIVIATANT.bullet[i]);
}

void addnewshoot(game_t *game)
{
    for (int i = 0; i != 10; i++) {
        if (TRIVIATANT.bullet[i] == NULL) {
            TRIVIATANT.bullet[i] =
            loadplasma(sfSprite_getPosition(TRIVIATANT.sprite));
            break;
        }
    }
}