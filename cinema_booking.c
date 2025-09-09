#include <stdio.h>
#include <ctype.h>
#define MAX_ROWS 9
#define MAX_COLS 9
#define TICKET_LIMIT 4

void FillMovieTheater(char MovieTheater[MAX_ROWS][MAX_COLS], int num_rows, int num_of_Seats_Col)
{
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_of_Seats_Col; j++)
        {
            MovieTheater[i][j] = 'O';
        }
    }
}

void PrintSeaMap(char MovieTheater[MAX_ROWS][MAX_COLS], int row, int col)
{
    char apha = 'A';
    printf("         ");

    for (int k = 1; k <= col; k++)
    {
        printf("Seat %d  ", k);
    }
    printf("\n");

    for (int i = 0; i < row; i++)
    {
        printf("Row %c    ", apha++);
        for (int j = 0; j < col; j++)
        {
            printf("%c", MovieTheater[i][j]);
            printf("       ");
        }
        printf("\n");
    }
}

int IsSeatSold(char MovieTheater[MAX_ROWS][MAX_COLS], int rowchoice, int colchoice)
{
    if (MovieTheater[rowchoice][colchoice] == 'X')
    {
        return 1;
    }
    else
    {
        MovieTheater[rowchoice][colchoice] = 'X';
        return 0;
    }
}

int main(void)
{
    char MovieTheater[MAX_ROWS][MAX_COLS] = {};
    int row = 0;
    int col = 0;
    int tickets = 0;
    int colchoice = 0;
    int choosecol = 0;
    int ticketssold = 0;
    char rowchoice;
    char chooserow;

    do
    {
        printf("How many rows does your movie theater have? (1-9) ");
        scanf("%d", &row);
        if (row > MAX_ROWS || row <= 0)
        {
            printf("Rows must be between 1 and 9. Please reenter.\n");
        }

    } while (row > MAX_ROWS || row <= 0);

    do
    {
        printf("How many seat are there per row? (1-9) ");
        scanf("%d", &col);
        if (col > MAX_COLS || col <= 0)
        {
            printf("Columns must be between 1 and 9. Please reenter.\n");
        }

    } while (col > MAX_COLS || col <= 0);
    FillMovieTheater(MovieTheater, row, col);
    do
    {
        printf("How many tickets would you like to purchase? (limit 4) ");
        scanf("%d", &tickets);
        if (tickets < 0 || tickets > TICKET_LIMIT)
        {
            printf("This is a special showing - limit of 4 tickets per purchase\n");
        }
    } while (tickets > TICKET_LIMIT || tickets < 0);

    if (tickets == 0)
    {
        printf("No movie for you!\n");
    }
    else
    {
        while (ticketssold < tickets)
        {
            PrintSeaMap(MovieTheater, row, col);

            printf("\nEnter seat choice by entering the row and seat\nPlease pick a seat ");
            scanf(" %c%d", &chooserow, &choosecol);

            rowchoice = toupper(chooserow) - 'A';
            colchoice = choosecol - 1;

            if ((rowchoice < 0 || rowchoice > row - 1) || (colchoice < 0 || colchoice > col - 1))
            {
                printf("That seat is not in this theater!!\n");
            }
            else if (IsSeatSold(MovieTheater, rowchoice, colchoice))
            {
                printf("Seat %c%d is already sold. Pick a different seat.\n\n", chooserow, choosecol);
            }
            else
            {
                ++ticketssold;
            }
        }

        printf("\nPlease find your way to your seats using this map...\n");
        PrintSeaMap(MovieTheater, row, col);
        printf("\nEnjoy your movie!\n");
    }
}