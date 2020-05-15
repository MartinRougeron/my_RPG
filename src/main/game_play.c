/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** game_play.c
*/

#include "my.h"

void game_play(game_t *game, sfRenderWindow *window)
{
    changeplayertexture(game);
    dorain(game);
    astakedamage(game);
    playdeadparticule(game);
    damage_ennemie_show(game);
    sfRenderWindow_setView(game->window, game->view);
    if (game->player.quest)
        drawquest(game);
    dodeath(game);
    displayminimap(game);
    sfRenderWindow_display(window);
}

void call_all_load(game_t *game)
{
    all_call_set(game);
    set_all_pause(game);
    load_allocation(game);
    loadmap(game);
    loadtriviamap(game);
    loadhousemap(game);
    loadvolcan(game);
    loadcapitalmap(game);
    loadsaxonmap(game);
    loadwatermap(game);
    loadfantome(game);
    load_ennemy(game);
    load_hud(game);
    gentiles(game);
    loadallpnj(game);
    game->questselect = 0;
}

void play(game_t game, sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (game.screen == TITLE_SCREEN) {
            main_menu(&game);
            continue;
        }
        game.playerpvstart = game.player.stat.health;
        getitemstat(&game);
        gethudtohide(&game);
        handlemenu(&game);
        game_play(&game, window);
        removeitemstat(&game);
        while (sfRenderWindow_pollEvent(window, &event))
            imput(&game, event);
        if (game.player.talking != -1 && sfKeyboard_isKeyPressed(sfKeyEscape))
            game.player.talking = -1;
    }
}