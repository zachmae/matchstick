/*
** EPITECH PROJECT, 2021
** ia.c
** File description:
** function for my ia in c
*/

#include "../include/matchstick.h"

int *get_tab(char **gameboard, int size)
{
    int *tab = malloc(sizeof(int) * size + 1);

    for (int y = 0; gameboard[y]; y++) {
        tab[y] = 0;
        for (int x = 0; gameboard[y][x]; x++) {
            if (gameboard[y][x] == '|')
                tab[y]++;
        }
    }
    tab[size] = -1;
    return tab;
}

int occ_stick(int *tab, int nb)
{
    int occ = 0;

    for (int c = 0; tab[c] != -1; c++) {
        (tab[c] == nb ? occ++ : 0);
    }
    return occ;
}

int calc_nim_sum(int *tab)
{
    int nim_sum = 0;

    for (int c = 0; tab[c] != -1; c++)
        nim_sum ^= tab[c];
    return nim_sum;
}

int first_line_not_empty(int *tab)
{
    for (int y = 0; tab[y] != -1; y++)
        if (tab[y] != 0)
            return y;
}
