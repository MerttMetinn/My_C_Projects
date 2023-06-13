#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void display_board(char board[][SIZE])
{
    printf("\n");
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if(j != SIZE - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i != SIZE - 1)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}

void get_move(char board[][SIZE], char player, int *row, int *col)
{
    int valid_move = 0;
    while(!valid_move)
    {
        printf("Player %c's turn.\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", row);
        printf("Enter column (1-3): ");
        scanf("%d", col);

        if(*row < 1 || *row > 3 || *col < 1 || *col > 3)
        {
            printf("Invalid move. Please enter row and column between 1 and 3.\n");
        }
        else if(board[*row - 1][*col - 1] != ' ')
        {
            printf("Invalid move. That space is already occupied.\n");
        }
        else
        {
            valid_move = 1;
        }
    }
}

int check_win(char board[][SIZE], char player)
{
    int count = 0;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board[i][j] == player)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if(count == 3)
            {
                return 1;
            }
        }

        count = 0;
    }

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board[j][i] == player)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if(count == 3)
            {
                return 1;
            }
        }

        count = 0;
    }

    for(int i = 0; i < SIZE; i++)
    {
        if(board[i][i] == player)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if(count == 3)
        {
            return 1;
        }
    }

    count = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(board[i][SIZE - 1 - i] == player)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if(count == 3)
        {
            return 1;
        }
    }

    return 0;
}

void play_game()
{
    char board[SIZE][SIZE];
    int row, col;
    char player = 'X';
    int turn = 1;
    int win = 0;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    while(!win && turn <= SIZE * SIZE)
    {
        display_board(board);
        get_move(board, player, &row, &col);
        board[row - 1][col - 1] = player;

        if(check_win(board, player))
        {
            win = 1;
        }
        else
        {
            player = (player == 'X') ? 'O' : 'X';
            turn++;
        }
    }

    display_board(board);
    if(win)
    {
        printf("Player %c wins!\n", player);
    }
    else
    {
        printf("Game ended in a tie.\n");
    }
}

int main()
{
    play_game();
    return 0;
}
