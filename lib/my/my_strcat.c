/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** contain my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int c;

    while (dest[i] != '\0') {
        i++;
    }
    for (c = 0; src[c] != '\0'; c++) {
        dest[i] = src[c];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int c;

    while (dest[i] != '\0') {
        i++;
    }
    for (c = 0; src[c] != '\0' && c < nb; c++) {
        dest[i] = src[c];
        i++;
    }
    dest[i + 1] = '\0';
    return dest;
}
