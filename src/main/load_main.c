/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_main.c
*/

#include "my.h"

void load_allocation(game_t *game)
{
    isometric = 0;
    game->nbkill = 0;
    game->hide = malloc(sizeof(bool) * NBHUD);
    game->lvltogive = 0;
    for (int i = 0; i != NBHUD; i++)
        game->hide[i] = FALSE;
    game->key = loaddefaultkey();
}

void allocation(game_t *game)
{
    game->enemie = malloc(sizeof(enemie_t) * MAXENEMIE);
    for (int i = 0; i != MAXENEMIE; i++)
        game->enemie[i].sprite = NULL;
    game->screen = TITLE_SCREEN;
    game->map.max = malloc(sizeof(mapmax_t) * NBWORLD);
    game->map.max[WORLD] = (mapmax_t) {MAPMAXX, MAPMAXY};
    game->map.max[TRIVIATANFIGHT] = (mapmax_t) {TRIVIAMAPX, TRIVIAMAPY};
    game->map.max[HOUSE] = (mapmax_t) {HOUSEMAPX, HOUSEMAPY};
    game->map.max[CAPITAL] = (mapmax_t) {CAPITALMAXX, CAPITALMAXY};
    game->map.max[SAXON] = (mapmax_t) {2, 1};
    game->map.max[FANTOME] = (mapmax_t) {1, 1};
    game->deadanim = malloc(sizeof(walkanim_t *) * MAXENEMIE);
    for (int i = 0; i != MAXENEMIE; i++)
        game->deadanim[i] = NULL;
    game->damage.text = malloc(sizeof(sfText *) * NBMAXENEMIE);
    game->damage.text_c = malloc(sizeof(sfClock *) * NBMAXENEMIE);
    for (int i = 0; i != NBMAXENEMIE; i++) {
        game->damage.text[i] = NULL;
        game->damage.text_c[i] = NULL;
    }
}

void load_music(game_t *game)
{
    game->music = create_music((char *[]) {"assets/music/main_quest.ogg",
    "assets/music/impact_sword.ogg", "assets/music/item_selection.ogg",
    "assets/music/level_up.ogg", "assets/music/shop.ogg",
    "assets/music/spell_fire.ogg", "assets/music/spell_ice.ogg",
    "assets/music/boss_music.ogg"}, MAXMUSIC);
    for (int i = 0; i < MAXMUSIC; i++)
        sfMusic_setVolume(game->music[i], 2);
    sfMusic_setLoop(game->music[MAIN_S], sfTrue);
    sfMusic_setLoop(game->music[BOSS_S], sfTrue);
    sfMusic_play(game->music[MAIN_S]);
    game->map.max[FARWATER] = (mapmax_t) {2, 1};
    game->map.max[VOLCAN] = (mapmax_t) {1, 1};
}

void set_view(game_t *game)
{
    game->view = (sfView *)sfRenderWindow_getView(game->window);
    game->triviantan = loadtriviatan();
    game->dragon = create_dragon();
    game->first_item = 0;
    game->first_lvl = 0;
    game->first_pnj = 0;
}
