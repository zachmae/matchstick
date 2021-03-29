/*
** EPITECH PROJECT, 2021
** my prog.h
** File description:
** .h file for prog
*/

#ifndef _MATCHSTICK_H_
#define _MATCHSTICK_H_

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

static const int PVE = 1;
static const int PVP = 2;

int matchstick(int const size, int const limit, int const nb_players);
char **get_play(char **gameboard, int size, int limit, int turn,
    int nb_players);
int check_error_remove(char **gameboard, int line, char *nbr, int limit);
int check_error_line(char **gameboard, char *line, int size);
int *get_tab(char **gameboard, int size);
int occ_stick(int *tab, int nb);
int calc_nim_sum(int *tab);
int first_line_not_empty(int *tab);

#endif