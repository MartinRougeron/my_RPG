/*
** EPITECH PROJECT, 2020
** loadskilltree
** File description:
** skill tree
*/

#include "my.h"

int *loadunlocked(int size)
{
    int *res = malloc(sizeof(int) * size);

    for (int i = 0; i != size; i++)
        res[i] = -1;
    return res;
}

int *cpdependence(int *dep)
{
    int *res = loadunlocked(5);

    for (int i = 0; dep[i] != -1; i++)
        res[i] = dep[i];
    return res;
}

tree_t loadskilltree(void)
{
    int *unlocked = loadunlocked(NBSKILL);
    skill_t *skill = malloc(sizeof(skill_t) * NBSKILL);
    tree_t tree;
    
    LOADTREE;
    tree.skill = skill;
    tree.unlocked = unlocked;
    return tree;
}