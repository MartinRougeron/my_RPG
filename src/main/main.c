/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

int *load_nowalk(void)
{
    int *tiles = malloc(sizeof(int) * 430);
    int fd = open(".load/nowalk.load", O_RDONLY);
    char *str;

    if (fd < 0) {
        return (NULL);
    }
    for (int i = 0; i < 430; i++) {
        str = get_next_line(fd);
        tiles[i] = my_getnbr(str);
    }
    return (tiles);
}

int main(void)
{
    game_t game;
    sfEvent event;
    sfRenderWindow *window = genwindow();

    load_main(&game, window);
    game.player = loadplayer(&game);
    call_all_load(&game);
    game.nowalktiles = load_nowalk();
    allocation(&game);
    set_view(&game);
    load_music(&game);
    play(game, window, event);
    for (int i = 0; i < MAXMUSIC; i++)
        sfMusic_destroy(game.music[i]);
    return 0;
}