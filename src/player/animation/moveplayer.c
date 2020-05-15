/*
** EPITECH PROJECT, 2020
** player
** File description:
** move
*/

#include "my.h"

void changedirplayer(game_t *game, sfIntRect rect)
{
    static facing_t face = NORTH;

    if (sfKeyboard_isKeyPressed(game->key.up))
        game->player.face = NORTH;
    if (sfKeyboard_isKeyPressed(game->key.down))
        game->player.face = SOUTH;
    if (sfKeyboard_isKeyPressed(game->key.left))
        game->player.face = EST;
    if (sfKeyboard_isKeyPressed(game->key.right))
        game->player.face = WEST;
    if (face != game->player.face) {
        rect.left = 0;
        face = game->player.face;
    }
    rect.top = (game->player.state) * 144 + (game->player.face) * 36;
    if (game->player.face == NORTH || game->player.face == SOUTH)
        rect.width = 30;
    else
        rect.width = 24;
    sfSprite_setTextureRect(game->player.sprite, rect);
}

void changeplayerstate(sfVector2f posact, game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(game->player.sprite);

    if (!cmpvector2f(posact, sfSprite_getPosition(game->player.sprite)))
        sfClock_restart(game->player.ismoving);
    if (TIME(game->player.ismoving) > 500) {
        if (game->player.state != IDLE) {
            rect.left = 0;
            sfSprite_setTextureRect(game->player.sprite, rect);
        }
        game->player.state = IDLE;
    }
    else
        game->player.state = WALKING;
}

void checkcolision(game_t *game, sfVector2f oldpos)
{
    sfVector2f posact = sfSprite_getPosition(game->player.sprite);
    int tilesy = (int) roundf((posact.y + 33) / (1080 / MAPTILESY));
    int tilesx = (int) ((posact.x - 5) / (1920 / MAPTILESX));

    if (tilesy < 0 || tilesx < 0 || tilesy >= MAPTILESY || tilesx >= MAPTILESX)
        return;
    for (int i = 0; i != NBLAYER; i++)
        if (containsint(game->map.map[game->player.position.map]
        [game->player.position.y]
        [game->player.position.x][i][tilesy][tilesx], game->nowalktiles))
            sfSprite_setPosition(game->player.sprite, oldpos);
    for (int i = 0; i != game->nbpnj; i++) {
        if (!game->pnj[i].exist)
            continue;
        if (!samemap(game->player.position, game->pnj[i].position))
            continue;
        if (!isaround(game->player.sprite, game->pnj[i].sprite, 60))
            sfSprite_setPosition(game->player.sprite, oldpos);
    }
}

void functionaftermove(game_t *game, sfVector2f posact)
{
    changemapevent(game);
    changeplayerstate(posact, game);
    checkcolision(game, posact);
    centerviewonplayer(game);
    processteleport(game);
    if (!cmpvector2f(posact, sfSprite_getPosition(game->player.sprite)))
        walkinganim(game);
}

void moveplayer(game_t *game)
{
    float speed = 0.5;
    float elapsed = sfTime_asMilliseconds
    (sfClock_restart(game->player.moveclock));
    sfVector2f posact = sfSprite_getPosition(game->player.sprite);

    if (isattack(game) || islaunch(game) || game->player.talking != -1 ||
    game->player.successmsg != NULL)
        return;
    changedirplayer(game, sfSprite_getTextureRect(game->player.sprite));
    if (sfKeyboard_isKeyPressed(game->key.up)) {
        move_up(game, speed, elapsed);
    } if (sfKeyboard_isKeyPressed(game->key.down)) {
        move_down(game, speed, elapsed);
    } if (sfKeyboard_isKeyPressed(game->key.left)) {
        move_left(game, speed, elapsed);
    } if (sfKeyboard_isKeyPressed(game->key.right)) {
        move_right(game, speed, elapsed);
    }
    functionaftermove(game, posact);
}