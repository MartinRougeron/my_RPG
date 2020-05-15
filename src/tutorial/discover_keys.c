/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** discover_keys.c
*/

#include "my.h"

void firstmsg(game_t *game)
{
    static int first = 0;
    char *all_key =
    my_strcat(my_strcat(my_strcat(my_strcat("",
    my_strcat(my_strcat("\n\n Key ", game->menu.key_st.c_up),
    " To go up")), my_strcat(my_strcat("\n\n Key ", game->menu.key_st.c_down),
    " To go down")), my_strcat(my_strcat("\n\n Key ", 
    game->menu.key_st.c_left),
    " To go left")), my_strcat(my_strcat("\n\n Key ",
    game->menu.key_st.c_right), " To go right"));

    if (first++ == 0) {
        all_key =
        my_strcat(my_strcat("Go to all direction using \n", all_key), "\n\n");
        game->player.successmsg = all_key;
        drawsuccessmsg(game);
    }
}

void discover_keys(game_t *game)
{
    static int up_key = 0;
    static int right_key = 0;
    static int down_key = 0;
    static int left_key = 0;

    firstmsg(game);
    if (sfKeyboard_isKeyPressed(game->key.up))
        up_key = 1;
    if (sfKeyboard_isKeyPressed(game->key.down))
        down_key = 1;
    if (sfKeyboard_isKeyPressed(game->key.left))
        left_key = 1;
    if (sfKeyboard_isKeyPressed(game->key.right))
        right_key = 1;
    if (up_key && down_key && right_key && left_key)
        game->is_tuto = KILL;
}