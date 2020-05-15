/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handgame
*/

#include "my.h"

void menu_move_anim(game_t *game)
{
    if (game->screen == GAME) {
        drawmap(game);
        moveplayer(game);
        animplayer(game);
        animpnj(game);
        drawpnj(game);
        if (game->is_tuto != MOVE)
            anim_ennemy(game);
        sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
        interactpnj(game);
        if ((game->is_tuto != MOVE && game->is_tuto != KILL) &&
        (game->player.successmsg == NULL && game->player.talking == -1))
            ennemy_ia(game);
        quest_all(game);
        talkpnj(game);
        animspell(game);
        movespell(game);
        enemy_life(game);
        menu_game(game);
    }
}

void menu_game(game_t *game)
{
    menu_game_tuto(game);
    triviatanfight(game);
    if (game->player.position.map == VOLCAN)
        draw_dragon(game, &game->dragon);
    magicshield(game);
    lightspell(game);
    drawsuccessmsg(game);
    print_life(game);
    drawgold(game);
    regenstat(game);
    levelupscreen(game);
}

void menu_game_tuto(game_t *game)
{
    if (game->is_tuto == MOVE)
        discover_keys(game);
    if (game->is_tuto == KILL)
        discover_kill(game);
    if (game->is_tuto == BUY)
        discover_shop(game);
    if (game->is_tuto == INV)
        discover_inventory(game);
    if (game->is_tuto == TREE)
        discover_tree(game);
    if (game->is_tuto == ZOOM)
        discover_zoom(game);
    if (game->is_tuto == LVLUP)
        game->is_tuto = TREE;
    if (game->is_tuto == CAPITALE)
        go_saxon_dalle(game);
}
