/*
** EPITECH PROJECT, 2020
** pnj
** File description:
** load and anim
*/

#include "my.h"

pnj_t loadpnj(char *path, sfVector2f scale, pos_t pos, facing_t face)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    pnj_t pnj;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 32, 32});
    sfSprite_centerorigine(sprite), sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f)
    {pos.onmapx * (WIDTH / MAPTILESX), pos.onmapy * (HEIGHT / MAPTILESY)});
    pnj.sprite = sprite;
    pnj.face = face;
    pnj.position = pos;
    pnj.exist = 1;
    pnj.clockanim = sfClock_create();
    pnj.interaction = sfClock_create();
    pnj.is_shop = 0;
    pnj.nb_item = 0;
    pnj.hair = 0;
    pnj.save = 0;
    return pnj;
}

void loadallpnj(game_t *game)
{
    game->nbpnj = 51;
    game->pnj = malloc(sizeof(pnj_t) * game->nbpnj);
    load_pnj_normal(game);
    load_pnj_quest(game);
    load_pnj_shop(game);
}

void drawpnj(game_t *game)
{
    for (int i = 0; i != game->nbpnj; i++) {
        if (!game->pnj[i].exist)
            continue;
        if (!samemap(game->pnj[i].position, game->player.position))
            continue;
        sfRenderWindow_drawSprite(game->window, game->pnj[i].sprite, NULL);
    }
}

void interactpnj(game_t *game)
{
    for (int i = 0; i != game->nbpnj; i++) {
        if (!game->pnj[i].exist)
            continue;
        if (!samemap(game->pnj[i].position, game->player.position))
            continue;
        if (!isaround(game->player.sprite, game->pnj[i].sprite, 70)
        && sfKeyboard_isKeyPressed(game->key.interact)
        && game->player.talking == -1) {
            game->player.talking = i;
            sfClock_restart(game->pnj[i].interaction);
        }
    }
}

void animpnj(game_t *game)
{
    sfIntRect rect;

    for (int i = 0; i != game->nbpnj; i++) {
        if (!game->pnj[i].exist)
            continue;
        rect = sfSprite_getTextureRect(game->pnj[i].sprite);
        rect.top = game->pnj[i].face * 32;
        if (TIME(game->pnj[i].clockanim) < 200)
            continue;
        rect.left += 32;
        if (rect.left == 32 * 3)
            rect.left = 0;
        sfSprite_setTextureRect(game->pnj[i].sprite, rect);
        sfClock_restart(game->pnj[i].clockanim);
    }
}