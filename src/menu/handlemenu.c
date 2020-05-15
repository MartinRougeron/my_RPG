/*
** EPITECH PROJECT, 2020
** menu
** File description:
** handle
*/

#include "my.h"

void talkpnj(game_t *game)
{
    if (game->player.talking != -1) {
        if (game->pnj[game->player.talking].is_shop) {
            draw_shop(game);
            return;
        }
        if (game->pnj[game->player.talking].hair) {
            hairpnj(game);
            return;
        }
        if (game->pnj[game->player.talking].save)
            savepnj(game);
        else
            drawtext(&game->pnj[game->player.talking], game);
    } else
        game->first_pnj = 0;
}

void handlemenu(game_t *game)
{
    if (game->screen != GAME || game->player.successmsg != NULL)
        restarclock(game);
    if (game->screen == END_SCREEN) {
        draw_end(game);
    }
    menu_pause(game);
    menu_setting(game);
    menu_control(game);
    menu_key(game);
    menu_inventory(game);
    menu_lvl_up(game);
    menu_skill_tree(game);
    menu_move_anim(game);
    drawdrop(game, game->player.drop);
    drawxp(game);
    drawerrormsg((sfColor) {0, 0, 0, 0}, NULL, game->window, 0);
}
