/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** contain prototype of libmy functions
*/

#ifndef MY_H
#define MY_H

void my_putrev(char *str);
int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
unsigned int my_put_uint(unsigned int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_perror(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_printf(char *s, ...);
void my_put_binary(int nb);
void my_put_octal(int nb);
void my_put_hexa(int nb);
void my_put_uphexa(int nb);
void my_put_ptr(int nb);
char **str_to_word_array(char *str, char lim);

#endif //MY_H//
