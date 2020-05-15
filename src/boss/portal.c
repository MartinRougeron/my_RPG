/*
** EPITECH PROJECT, 2020
** portal
** File description:
** portal
*/

#include "my.h"

portal_t create_portal(sfVector2f position, int spawn)
{
    portal_t portal;

    portal.anim = sfClock_create();
    portal.portal = sfSprite_create();
    portal.spawn = spawn;
    sfSprite_setTexture(portal.portal,
    sfTexture_createFromFile("assets/player/portal.png", NULL), sfTrue);
    sfSprite_setTextureRect(portal.portal, (sfIntRect) {0, 0, 100, 100});
    sfSprite_centerorigine(portal.portal);
    sfSprite_setPosition(portal.portal, position);
    return portal;
}

void add_portal(game_t *game, sfVector2f postion, int spawn)
{
    for (int i = 0; i != 20; i++) {
        if (game->dragon.portal[i].portal == NULL) {
            game->dragon.portal[i] = create_portal(postion, spawn);
            break;
        }
    }
}

void destroy_portal(portal_t *portal)
{
    sfSprite_destroy(portal->portal);
    portal->portal = NULL;
    sfClock_destroy(portal->anim);
}

void spawn_ennemy(game_t *game, portal_t *portal, sfVector2f pos)
{
    loadenemie(game, (enemieoption_t) {(drop_t) {1, 1},
    (pos_t) {game->player.position.map,
    game->player.position.x, game->player.position.y,
    (pos.x * MAPTILESX) / WIDTH,
    (pos.y * MAPTILESY) / HEIGHT}, 2, 8, 10});
    portal->spawn -= 1;
}

void anim_portal(game_t *game, portal_t *portal)
{
    sfIntRect rect = sfSprite_getTextureRect(portal->portal);
    sfVector2f pos = sfSprite_getPosition(portal->portal);

    if (TIME(portal->anim) > 50) {
        rect.left += 100;
        if (rect.left == 1000) {
            rect.left = 0;
            rect.top += 100;
        }
        if (rect.top == 900) {
            rect.top = 0;
            spawn_ennemy(game, portal, pos);
        }
        sfSprite_setTextureRect(portal->portal, rect);
    }
    sfRenderWindow_drawSprite(game->window, portal->portal, NULL);
    if (portal->spawn == 0)
        destroy_portal(portal);
}

