/*
** EPITECH PROJECT, 2021
** my str to word array
** File description:
** my str to word array function
*/

#include <stdlib.h>

int nbr_lim(char *str, char lim)
{
    int c;
    int v = 0;

    for (c = 0; str[c]; c++)
        if (str[c] == lim)
            v++;
    return (v + 1);
}

int length_string(char *str, int c, char lim)
{
    int len = 0;

    while (str[c] != '\0' && str[c] != lim) {
        c++;
        len++;
    }
    return len;
}

char **str_to_word_array(char *str, char lim)
{
    char **tab = malloc(sizeof(*tab) * (nbr_lim(str, lim) + 1));
    int y = 0;
    int x = 0;
    int c = 0;

    tab[y] = malloc(sizeof(*tab) * (length_string(str, c, lim) + 1));
    for (; str[c] != '\0'; c++) {
        while (str[c] == lim) {
            c++;
            tab[y][x] = '\0';
            x = 0;
            y++;
        tab[y] = malloc(sizeof(*tab) * (length_string(str, c, lim) + 1));
        }
        tab[y][x] = str[c];
        x++;
    }
    tab[y][x] = '\0';
    tab[y + 1] = NULL;
    return tab;
}