/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error handling for matchstick
*/

#include "../include/matchstick.h"

int check_error_line(char **gameboard, char *line, int size)
{
    if (!my_str_isnum(line)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return 84;
    }
    if (!(my_getnbr(line) > 0 && my_getnbr(line) <= size)) {
        my_printf("Error: this line is out of range\n");
        return 84;
    }
    return 0;
}

int check_error_remove(char **gameboard, int line, char *nbr, int limit)
{
    int occ = 0;

    if (!my_str_isnum(nbr)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return 84;
    } if (my_getnbr(nbr) < 1) {
        my_printf("Error: you have to remove at least one match\n");
        return 84;
    } if (my_getnbr(nbr) > limit) {
        my_printf("Error: you cannot remove more than %d matches "
            "per turn\n", limit);
        return 84;
    }
    for (int c = 0; gameboard[line - 1][c]; c++)
        if (gameboard[line - 1][c] == '|')
            occ++;
    if (occ < my_getnbr(nbr)) {
        my_printf("Error: not enough matches on this line\n");
        return 84;
    }
    return 0;
}
