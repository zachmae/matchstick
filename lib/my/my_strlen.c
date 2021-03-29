/*
** EPITECH PROJECT, 2020
** my _strlen
** File description:
** contain the _strlen_function
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
