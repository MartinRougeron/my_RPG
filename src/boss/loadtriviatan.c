/*
** EPITECH PROJECT, 2020
** triviatan
** File description:
** triviatan
*/

#include "my.h"

void cleartriviatan(game_t *game)
{
    game->all_quest[5] = BEGIN;
    game->player.position.map = FARWATER;
    sfSprite_setPosition(game->player.sprite, (sfVector2f){458, 568});
    sfSprite_destroy(TRIVIATANT.sprite);
    sfClock_destroy(TRIVIATANT.clock);
    sfClock_destroy(TRIVIATANT.anim);
    sfClock_destroy(TRIVIATANT.phasec);
    sfClock_destroy(TRIVIATANT.shoot);
    TRIVIATANT.phase = CLEAR;
    game->player.position.y = 0;
    game->player.position.x = 1;
    if (sfMusic_getStatus(game->music[BOSS_S]) == sfPlaying)
        sfMusic_play(game->music[MAIN_S]),
        sfMusic_pause(game->music[BOSS_S]);
}

sfSprite *createplasmashot(sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite,
    sfTexture_createFromFile("assets/spell/plasmashot.png", NULL), sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {2.5, 2.5});
    sfSprite_centerorigine(sprite);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

plasma_t *loadplasma(sfVector2f pos)
{
    plasma_t *plasma = malloc(sizeof(plasma_t) * 50);
    static int dodge = 25;
    int savedodge = dodge;

    do {
        dodge = savedodge;
        dodge += rand() % 20 - 10;
    } while (dodge > 45 || dodge < 5);
    for (int i = 0; i != 50; i++) {
        if (i > dodge - 3 && i < dodge + 3) {
            plasma[i].sprite = NULL;
            continue;
        }
        plasma[i].clock = sfClock_create();
        plasma[i].sprite = createplasmashot(pos);
        plasma[i].speed = (sfVector2f) {5 * cos((((i * 1.0) / 50) * 3.14)),
        5 * sin((((i * 1.0) / 50) * 3.14))};
    }
    return plasma;
}

triviatant_t loadtriviatan(void)
{
    triviatant_t boss;

    boss.clock = sfClock_create();
    boss.health = TRIVIATANHEALTH;
    boss.sprite = sfSprite_create();
    sfSprite_setTexture(boss.sprite,
    (sfTexture_createFromFile("assets/player/boss2.png", NULL)), sfTrue);
    sfSprite_setTextureRect(boss.sprite, (sfIntRect) {0, 0, 141, 66});
    sfSprite_centerorigine(boss.sprite);
    sfSprite_setScale(boss.sprite, (sfVector2f) {3, 3});
    sfSprite_setPosition(boss.sprite, (sfVector2f) {WIDTH / 2, 200});
    boss.phasec = sfClock_create();
    boss.phase = SLEEP;
    boss.shoot = sfClock_create();
    boss.anim = sfClock_create();
    boss.bullet = malloc(sizeof(plasma_t *) * 10);
    for (int i = 0; i != 10; i++)
        boss.bullet[i] = NULL;
    return boss;
}