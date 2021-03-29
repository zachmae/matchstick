/*
** EPITECH PROJECT, 2021
** play.c
** File description:
** gamepart
*/

#include <stdio.h>
#include "../include/matchstick.h"

static int check_bad_move(int limit, int max, int line, int *tab)
{
    int sticks = 0;
    int occ_one = occ_stick(tab, 1);
    int occ_zero = occ_stick(tab, 0);
    int height;

    for (int y = 0; tab[y] != -1; y++) {
        sticks += tab[y];
        height = y;
    }
    if ((sticks == tab[line] || (occ_one + occ_zero == height
        && occ_one % 2  == 0)) && max != 1)
        max--;
    if (height - occ_zero == 1 && tab[line] + 1 == sticks
        && tab[line] <= limit)
        max = tab[line];
    return max;
}

static char **rm_matches(char **gameboard, int line, int nbr)
{
    int occ = 0;

    for (int x = 0; gameboard[line - 1][x] != '\0'; x++)
        if (gameboard[line - 1][x] == '|')
            occ++;
    for (int c = 0; c < nbr; c++) {
        gameboard[line - 1][occ - c - 1] = ' ';
    }
}

static char **ai_turn(char **gameboard, int size, int limit)
{
    int y;
    int value = 1;
    int *tab = get_tab(gameboard, size);
    int nim_sum = calc_nim_sum(tab);

    my_printf("\nAI's turn...\n");
    if (nim_sum != 0) {
        for (y = 0; tab[y] != -1; y++)
            if ((tab[y] ^ nim_sum) < tab[y]) {
                value = tab[y] - (tab[y] ^ nim_sum);
                break;
            }
        while (value > limit)
            value--;
    } else
        y = first_line_not_empty(tab);
    value = check_bad_move(limit, value, y, tab);
    rm_matches(gameboard, y + 1, value);
    my_printf("AI removed %d match(es) from line %d\n", value, y + 1);
    return gameboard;
}

static char **player_turn(char **gameboard, int size, int limit)
{
    size_t len = 0;
    char *line = NULL;
    char *nbr = NULL;

    my_printf("Line: ");
    if (getline(&line, &len, stdin) == -1)
        return NULL;
    if (check_error_line(gameboard, line, size) == 84)
        return (player_turn(gameboard, size, limit));
    my_printf("Matches: ");
    if (getline(&nbr, &len, stdin) == -1)
        return NULL;
    if (check_error_remove(gameboard, my_getnbr(line), nbr, limit) == 84)
        return (player_turn(gameboard, size, limit));
    rm_matches(gameboard, my_getnbr(line), my_getnbr(nbr));
    my_printf("Player removed %d match(es) from line %d\n"
        , my_getnbr(nbr), my_getnbr(line));
    return gameboard;
}

char **get_play(char **gameboard, int size, int limit, int turn, int nb_players)
{
    if (turn == 1 &&  nb_players == 1) {
        my_printf("\nYour turn:\n");
        gameboard = player_turn(gameboard, size, limit);
    }   else if (nb_players == 1) {
        gameboard = ai_turn(gameboard, size, limit);
    } else {
        my_printf("\nIt's Player %d turn:\n", turn);
        gameboard = player_turn(gameboard, size, limit);
    }

    return gameboard;
}