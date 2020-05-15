/*
** EPITECH PROJECT, 2020
** world to volcan
** File description:
** world to volcan
*/

#include "my.h"

int checkconditionvolcan(game_t *game)
{
    if (getitem[INVENTORY_SIZE + ARTIFACT1].sprite != NULL
    && getitem[INVENTORY_SIZE + ARTIFCAT2].sprite != NULL
    && getitem[INVENTORY_SIZE + ARTIFACT3].sprite != NULL) {
        return 1;
    }
    sfSprite_setPosition(game->player.sprite, (sfVector2f) {958, 727});
    game->player.successmsg = "You need 3 amulets\n\nto enter the volcano";
    return 0;
}

void norm_for_line(game_t *game)
{
    game->player.position = (pos_t) {VOLCAN, 0, 0, 0, 0};
    sfSprite_setPosition(game->player.sprite,
    (sfVector2f) {960, 1080 / 2});
    game->player.face = NORTH;
    game->all_quest[7] = FINISH;
}

void worldtovolcan(game_t *game)
{
    int tiles, x, y;
    sfVector2f posact;

    if (!samemap(game->player.position, (pos_t) {WORLD, 2, 2, 0, 0}))
        return;
    posact = sfSprite_getPosition(game->player.sprite);
    y = (int) roundf((posact.y + 33) / (1080 / MAPTILESY));
    x = (int) ((posact.x - 5) / (1920 / MAPTILESX));
    if (x < 0 || x >= MAPTILESX || y < 0 || y >= MAPTILESY)
        return;
    tiles = game->map.map[game->player.position.map]
    [game->player.position.y][game->player.position.x][1][y][x];
    if ((tiles >= 634 && tiles <= 635) || (tiles >= 667 && tiles <= 668)) {
        if (!checkconditionvolcan(game))
            return;
        norm_for_line(game);
    }
}