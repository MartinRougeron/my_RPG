/*
** EPITECH PROJECT, 2020
** dragon
** File description:
** dragon
*/

#include "my.h"

dragon_t create_dragon(void)
{
    dragon_t dragon;

    dragon = load_dragon(dragon);
    sfSprite_setTexture(dragon.dragon,
    sfTexture_createFromFile("assets/player/dragon.png", NULL), sfTrue);
    sfSprite_setTextureRect(dragon.dragon, (sfIntRect) {256, 256, 128, 128});
    sfSprite_setScale(dragon.dragon, (sfVector2f) {2.5, 2.5});
    sfSprite_centerorigine(dragon.dragon);
    sfSprite_setPosition(dragon.dragon, (sfVector2f) {800, 500});
    return dragon;
}

int damage_dragon(game_t *game, dragon_t *dragon)
{
    sfFloatRect range = range_player(game);
    sfFloatRect bounds = sfSprite_getGlobalBounds(dragon->dragon);

    if (sfFloatRect_intersects(&range, &bounds, NULL) &&
    game->player.state == ATTACK && TIME(dragon->takedmg) > 300) {
        dragon->health -= game->player.stat.damage + getequipmentdamage(game);
        if (dragon->health < 0)
            dragon->health = 0;
        addtxtdmg(game, game->player.stat.damage + getequipmentdamage(game),
        sfSprite_getPosition(dragon->dragon));
        return 1;
    }
    return 0;
}

void destroy_dragon(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->dragon.dragon);

    if (TIME(game->dragon.die) > 200) {
        adddeadparticule(game, (sfVector2f)
        {pos.x + rand() % 100 - 50, pos.y + rand() % 10 - 5},
        (sfColor) {rand() % 160 + 100, rand() % 160 + 100,
        rand() % 250 + 200, rand() % 255 + 200}, 700);
        game->dragon.stance = END;
        sfClock_restart(game->dragon.die);
    }
}

void choosestance(dragon_t *dragon, game_t *game)
{
    sfIntRect rect = sfSprite_getTextureRect(dragon->dragon);
    int side = ((rand() % 2 == 0) ? 100 : 1820);

    rect = dragon_phase(game, dragon, rect, side);
    if (dragon->health == 0) {
        if (dragon->stance != END)
            sfClock_restart(dragon->phase);
        sfClock_restart(dragon->takedmg);
        destroy_dragon(game);
    }
    if (dragon->stance >= 0 && dragon->stance <= 2)
        if (TIME(dragon->phase) > 10000) {
            dragon->stance = WANDERING;
            rect.left = 256;
            sfClock_restart(dragon->phase);
        }
    sfSprite_setTextureRect(dragon->dragon, rect);
    if (dragon->stance == END && TIME(dragon->phase) > 5000)
        clear_dragon(dragon, game);
}

void draw_dragon(game_t *game, dragon_t *dragon)
{
    if (dragon->dragon == NULL)
        return;
    for (int i = 0; i != 20; i++)
        if (game->dragon.lightning[i].sprite != NULL)
            game->dragon.lightning[i] =
            play_lightning(game, game->dragon.lightning[i]);
    for (int i = 0; i != 20; i++)
        if (game->dragon.fireball[i].sprite != NULL)
            move_fireball(game, &game->dragon.fireball[i]);
    for (int i = 0; i != 20; i++)
        if (game->dragon.portal[i].portal != NULL)
            anim_portal(game, &game->dragon.portal[i]);
    attack_dragon(game, dragon);
    anim_dragon(dragon);
    bosslifebar(game, dragon->health, dragon->maxhealth);
    sfRenderWindow_drawSprite(game->window, dragon->dragon, NULL);
    choosestance(dragon, game);
}