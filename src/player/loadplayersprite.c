/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** sprite
*/

#include "my.h"

player_t load_player3(player_t player)
{
    player.stat.regenhealth = sfClock_create();
    player.stat.damage = 10;
    player.stat.armor = 0;
    player.tree = loadskilltree();
    player.tree.point = 0;
    player.tree.clickonmenu = sfClock_create();
    player.drop = (drop_t) {0, 0};
    player.xp = 0;
    player.level = 1;
    player.stat.maxhealth = 100;
    player.stat.maxmana = 100;
    player.stat.maxstamina = 200;
    player.combat = sfClock_create();
    player.color = BLUE;
    player.shield = 0;
    player.clockshield = sfClock_create();
    player.light = 0;
    player.clocklight = sfClock_create();
    player.successmsg = NULL;
    return (player);
}

player_t loadplayer2(player_t player)
{
    player.mage.spell = malloc(sizeof(spell_t) * 30);
    for (int i = 0; i != 30; i++)
        player.mage.spell[i].sprite = NULL;
    player.mage.cd = malloc(sizeof(sfClock *) * 4);
    for (int i = 0; i != 4; i++ )
        player.mage.cd[i] = sfClock_create();
    player.mage.select = ICE;
    player.mage.loadedspell = loadbasicspell();
    player.stance = MELEE;
    player.spellclock = sfClock_create();
    player.mage.unlocked = 0;
    player.stat.health = 100;
    player.stat.mana = 0;
    player.stat.stamina = 0;
    player.stat.regenmana = sfClock_create();
    player.stat.regenstamina = sfClock_create();
    player.quest = 0;
    player = load_player3(player);
    return player;
}

player_t load_player_clock(player_t player)
{
    player.moveclock = sfClock_create();
    player.position = (pos_t) {WORLD, 3, 4, 0, 0};
    player.ismoving = sfClock_create();
    player.attackclock = sfClock_create();
    player.clock_attack = sfClock_create();
    player.talking = -1;
    player.learnmagic = 0;
    player.map = 0;
    player.confirm = 0;
    return (player);
}

player_t loadplayer(game_t *game)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/player/none/spritesheet_blue.png", NULL);
    player_t player;

    sfSprite_setScale(sprite, (sfVector2f) {2.7, 3.4});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 30, 35});
    sfSprite_centerorigine(sprite);
    sfSprite_setPosition(sprite, (sfVector2f) {930, 319});
    player.sprite = sprite;
    player.animationclock = sfClock_create();
    player.face = SOUTH;
    player.state = WALKING;
    player = load_player_clock(player);
    loadinventory(&player);
    game->all_quest = malloc(sizeof(quest_) * (NBQUEST + NBSECONDARY));
    for (int i = 0; i < NBQUEST + NBSECONDARY; i++)
        game->all_quest[i] = NOT_BEGIN;
    return loadplayer2(player);
}