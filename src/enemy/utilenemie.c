/*
** EPITECH PROJECT, 2020
** enemie
** File description:
** util
*/

#include "my.h"

enemie_t *loadbasicenemie(void)
{
    FILE *fd = fopen("./.load/enemie.load", "r");
    enemie_t *enemie = malloc(sizeof(enemie_t) * NBENEMIETOLOAD);

    if (!fd) {
        write(1, "Error loading enemie ! Check\
        ./load/enemie.load file\nIf missing or corrupted use git clone :)",
        93);
        return NULL;
    }
    for (int i = 0; i != NBENEMIETOLOAD; i++) {
        fillenemie(&enemie[i], fd);
    }
    return enemie;
}

enemie_t copyenemie(enemie_t enemie, pos_t position,
drop_t drop, enemieoption_t option)
{
    enemie_t cpy;

    cpy.clock_attack = sfClock_copy(enemie.clock_attack);
    cpy.clockanimation = sfClock_copy(enemie.clockanimation);
    cpy.damage = option.damage;
    cpy.golddrop = enemie.golddrop;
    cpy.health = option.health;
    cpy.position = position;
    cpy.sprite = sfSprite_copy(enemie.sprite);
    cpy.drop = drop;
    cpy.face = SOUTH;
    cpy.maxhealth = cpy.health;
    cpy.clockmove = sfClock_create();
    cpy.blood_c = sfClock_create();
    sfSprite_setPosition(cpy.sprite, convertpos(position));
    return cpy;
}

void loadenemie(game_t *game, enemieoption_t option)
{
    for (int i = 0; i != MAXENEMIE; i++)
        if (game->enemie[i].sprite == NULL) {
            game->enemie[i] =
            copyenemie(game->loadedenemie[option.type],
            option.pos, option.drop, option);
            break;
        }
}

void dodamageenemie(game_t *game, int enemie, int damage)
{
    sfVector2f pos = sfSprite_getPosition(game->enemie[enemie].sprite);

    game->enemie[enemie].health -= damage;
    if (game->player.stance == MELEE) {
        sfMusic_play(game->music[SWORD_S]);
        sfMusic_play(game->music[SWORD_S]);
    }
    addtxtdmg(game, damage, pos);
    if (gottheskill(game->player.tree.unlocked, LIFESTEAL)) {
        game->player.stat.health += damage * 0.3;
        if (game->player.stat.health >= game->player.stat.maxhealth)
            game->player.stat.health = game->player.stat.maxhealth;
    }
    if (game->enemie[enemie].health <= 0) {
        adddeadparticule(game, sfSprite_getPosition(game->enemie[enemie].
        sprite), (sfColor) {121, 151, 214, rand() % 255 + 200}, 300);
        sfSprite_destroy(game->enemie[enemie].sprite);
        game->enemie[enemie].sprite = NULL;
        dropitem(game, game->enemie[enemie].drop);
        if (game->all_quest[NBQUEST + 2] == BEGIN)
            game->nbkill += 1;
    }
}