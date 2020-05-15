/*
** EPITECH PROJECT, 2020
** boss
** File description:
** fireball
*/

#include "my.h"

fireball_t create_fireball(sfVector2f pos, sfVector2f dir)
{
    fireball_t fireball;
    float distance = sqrt(pow(pos.x - dir.x, 2) + pow(pos.y - dir.y, 2));
    float angle = (dir.x - pos.x) / distance;

    fireball.clockanim = sfClock_create();
    fireball.move = sfClock_create();
    fireball.sprite = sfSprite_create();
    sfSprite_setTexture(fireball.sprite,
    sfTexture_createFromFile("assets/player/fireball.png", NULL), sfTrue);
    sfSprite_setTextureRect(fireball.sprite, (sfIntRect) {0, 0, 82, 48});
    sfSprite_setScale(fireball.sprite, (sfVector2f) {2, 2});
    sfSprite_setRotation(fireball.sprite, -45);
    sfSprite_rotate(fireball.sprite, acos(angle) * (180 / M_PI));
    sfSprite_centerorigine(fireball.sprite);
    sfSprite_setPosition(fireball.sprite, pos);
    fireball.speed = (sfVector2f) {(dir.x - pos.x) / 20, (dir.y - pos.y) / 20};
    return fireball;
}

void add_fireball(game_t *game, sfVector2f pos, sfVector2f dir)
{
    for (int i = 0; i != 20; i++) {
        if (game->dragon.fireball[i].sprite == NULL) {
            game->dragon.fireball[i] = create_fireball(pos, dir);
            break;
        }
    }
}

void destroy_fireball(fireball_t *fireball)
{
    if (fireball->sprite == NULL)
        return;
    sfClock_destroy(fireball->clockanim);
    sfClock_destroy(fireball->move);
    sfSprite_destroy(fireball->sprite);
    fireball->sprite = NULL;
}

sfIntRect move_rect(sfIntRect rect, fireball_t *fireball)
{
    if (rect.left < 82) {
        if (TIME(fireball->clockanim) > 200) {
            rect.left += 82;
            sfSprite_setTextureRect(fireball->sprite, rect);
            sfClock_restart(fireball->clockanim);
        }
    }
    return (rect);
}

void move_fireball(game_t *game, fireball_t *fireball)
{
    float elasped =
    sfTime_asMilliseconds(sfClock_restart(fireball->move)) / 50.0f;
    sfIntRect rect = sfSprite_getTextureRect(fireball->sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(fireball->sprite);
    sfFloatRect boundsp = sfSprite_getGlobalBounds(game->player.sprite);
    sfVector2f pos = sfSprite_getPosition(fireball->sprite);

    rect = move_rect(rect, fireball);
    sfSprite_move(fireball->sprite, (sfVector2f)
    {fireball->speed.x * elasped, fireball->speed.y * elasped});
    sfRenderWindow_drawSprite(game->window, fireball->sprite, NULL);
    if (sfFloatRect_intersects(&bounds, &boundsp, NULL)) {
        addtxtdmg(game, 20, sfSprite_getPosition(game->player.sprite));
        game->player.stat.health -= 20;
        destroy_fireball(fireball);
    }
    if (pos.x > 1980 || pos.x < -20 || pos.y > 1100 || pos.y < 0)
        destroy_fireball(fireball);
}