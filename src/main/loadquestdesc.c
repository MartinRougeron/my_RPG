/*
** EPITECH PROJECT, 2020
** load
** File description:
** load
*/

#include "my.h"

void load_desc2(game_t *game)
{
    game->quest_description[10] = "Go back at FarWater\n\n"
    "to defeat the legendary\n\nTriviatan";
    game->quest_description[11] = "Talk to all the pnj at\n\nHilford"
    " to discover your\n\ndestiny";
    game->quest_description[NBQUEST] = "Bring the flowers to\n\n"
    "the great kingdom garden";
    game->quest_description[NBQUEST + 1] = "Talk to a pnj at Saxon Dale\n\n"
    "to unlock the third amulet";
    game->quest_description[NBQUEST + 2] = "Kill 10 enemie so that the\n\n"
    "lost city PNJ learn you a spell";
}

void load_main(game_t *game, sfRenderWindow *window)
{
    game->quest_description = malloc(sizeof(char *) * (NBQUEST + NBSECONDARY));
    game->quest_description[0] = "Reaches Hilford\n\nOpen the map with 'M'\n\n"
    "if you are lost";
    game->quest_description[1] = "Go find the old man's son\n\nfrom capital"
    "\n\nHe is in the west of Saxon Dale";
    game->quest_description[2] = "Go to brouteland to continue\n\n"
    "learning magic";
    game->quest_description[3] = "Reach the fisherman at\n\nFarWater to find "
    "the\n\nsecond amulet";
    game->quest_description[4] = "Talk to the fisher\n\nto fight triviatan";
    game->quest_description[5] = "Kill triviatant";
    game->quest_description[6] = "Do the missions of the\n\ndj saxon dale"
    "to get\n\nthe 3rd amulets";
    game->quest_description[7] = "Go to the volcano\n\nto fight Sahrotar\n\nThe"
    " legendary dragon";
    game->quest_description[8] = "Bring back the jewlerie\n\nto the pnj at "
    "Saxon-Dale\n\nThey are in the lost city";
    game->quest_description[9] = "Bring fishes to Hilford";
    game->window = window;
    load_desc2(game);
}