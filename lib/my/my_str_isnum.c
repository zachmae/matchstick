/*
** EPITECH PROJECT, 2020
** my str is num
** File description:
** contain my str is num
*/

int my_str_isnum(char const *str)
{
    for (int c = 0; str[c] != '\0' && str[c] != '\n'; c++)
        if (str[c] < '0' || str[c] > '9')
            return (0);
    return (1);
}
