/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** file of matchstick gameloop
*/

#include "../include/matchstick.h"

static int check_win(char **game_board)
{
    for (int y = 0; game_board[y] != NULL; y++) {
        for (int x = 0; game_board[y][x] != '\0'; x++) {
            if (game_board[y][x] == '|')
                return 0;
        }
    }
    return 1;
}

static char **create_game_board(int const size)
{
    char **game_board = malloc(sizeof(char *) * size + 1);

    if (game_board == NULL)
        return NULL;
    for (int c = 0; c <= size; c++) {
        game_board[c] = malloc(sizeof(char) * (c + 1) * 2 + 1);
        if (game_board[c] == NULL)
            return NULL;
        for (int i = 0; i < ((c + 1) * 2) - 1; i++)
            game_board[c][i] = '|';
        game_board[c][((c + 1) * 2) + 1] = '\0';
    }
    game_board[size] = NULL;
    return (game_board);
}

static void print_game_board(int const size, char **game_board)
{
    for (int c = 0; c < (size + 1) * 2 - 1; c++)
        my_printf("*");
    my_printf("\n");
    for (int y = 0; game_board[y] != NULL; y++) {
        my_printf("*");
        for (int c = y; c < size - 1; c++)
            my_printf(" ");
        my_printf("%s", game_board[y]);
        for (int c = y; c < size - 1; c++)
            my_printf(" ");
        my_printf("*\n");
    }
    for (int c = 0; c < (size + 1) * 2 - 1; c++)
        my_printf("*");
    my_printf("\n");
}

int matchstick(int const size, int const limit, int const nb_players)
{
    char **game_board = create_game_board(size);
    int res = 0;
    int turn = 1;

    while (res == 0) {
        print_game_board(size, game_board);
        game_board = get_play(game_board, size, limit, turn, nb_players);
        if (game_board == NULL)
            return 0;
        res = check_win(game_board);
        turn = (turn == 1 ? 2 : 1);
    }
    print_game_board(size, game_board);
    if (turn == 1 && nb_players == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
    else if (nb_players == 1)
        my_printf("You lost, too bad...\n");
    else
        my_printf("Player %d won the game, congratulations\n", turn);
    return turn;
}
