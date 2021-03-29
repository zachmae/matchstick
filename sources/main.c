/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "../include/matchstick.h"

int error_handle(int ac, char **av)
{
    if (ac == 4) {
        if (!(my_str_isnum(av[1])) || !(my_str_isnum(av[2]))) {
            my_perror("arguments line and limit must be numbers\n");
            return 84;
        }
        if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) >= 100) {
            my_perror("number of line must be include between 1 and 100\n");
            return 84;
        }
        if (my_getnbr(av[2]) < 1) {
            my_perror("You must take at least 1 stick every turn\n");
            return 84;
        }
        if (my_strcmp(av[3], "PVP") != 0 && my_strcmp(av[3], "PVE") != 0) {
            my_perror("You must choose between pvp and PVE gamemode\n");
            return 84;
        }
    } else {
        write(2, "read usage\n", 12);
        return 84;
    }
    return 0;
}

int print_usage(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            my_printf("USAGE\n\t./matchstick lines limit\n");
            my_printf("DESCRIPTION\n\tline\tnumber of lines of the game\n");
            my_printf("\n\tlimit\tmax number"
                " of stick you can take each turn\n\tPVE/PVP"
                "\tchoose between pvp and pve");
            my_printf("This is matchstick, an epitech 1st year project in ");
            my_printf("which we must recreate the stick game from Fort Boyard"
                "\n");
            return 1;
        }
    return 0;
}

int main(int ac, char **av)
{
    int return_value;

    if (print_usage(ac, av) == 1)
        return 0;
    if (error_handle(ac, av) == 84)
        return 84;
    return (matchstick(my_getnbr(av[1]), my_getnbr(av[2]),
        (my_strcmp(av[3], "PVP") ? PVE : PVP)));
}