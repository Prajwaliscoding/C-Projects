#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define NUMBEROFREROLLS 3
#define NUMBEROFFACES 6
#define NUMBEROFDICE 5

void RollDice(int Dice[])
{
    for (int i = 0; i < NUMBEROFDICE; i++)
    {

        Dice[i] = 1 + (rand() % NUMBEROFFACES);
    }
}

void PrintRoll(int Dice[])
{

    for (int i = 0; i < NUMBEROFDICE; i++)
    {
        printf("%d\t", Dice[i]);
    }
    printf("\n");
}

int HowManyFaces(int Dice[], int SearchFace)
{
    int NumberOfFaces = 0;
    for (int i = 0; i < NUMBEROFDICE; i++)
    {
        if (Dice[i] == SearchFace)
        {
            NumberOfFaces++;
        }
    }
    return NumberOfFaces;
}

int main()
{
    int Dice[NUMBEROFDICE];
    int howMany[NUMBEROFFACES];
    int numberOfRolls = 0;
    int numberOfReRolls = NUMBEROFREROLLS;
    char answer = 'N';
    int ofAKind = 0;
    int FullHouse = 0;
    int TwoPair = 0;
    int CSlam = 0;
    int LargeStraight = 0;
    int SmallStraight = 0;
    int i = 0;

    srand(time(0));

    do
    {
        RollDice(Dice);
        printf("\nYou rolled\n");
        printf("Roll #%d\n", numberOfRolls + 1);
        PrintRoll(Dice);
        numberOfRolls++;
        for (i = 0; i < NUMBEROFFACES; i++)
        {
            howMany[i] = HowManyFaces(Dice, i + 1);
        }
        for (i = 0; i < NUMBEROFFACES; i++)
        {
            if (howMany[i] == 3)
            {
                FullHouse += 3;
            }
            if (howMany[i] == 2)
            {
                FullHouse += 2;
                TwoPair++;
            }
            if (howMany[i] == NUMBEROFDICE)
            {
                CSlam++;
            }
            if (howMany[i] == 1)
            {
                LargeStraight++;
            }
            else if (howMany[i] == 0 && LargeStraight > 0 && LargeStraight < 5)
            {
                LargeStraight = 0;
            }
            if (howMany[i] >= 1)
            {
                SmallStraight++;
            }
            else if (howMany[i] == 0 && SmallStraight > 0 && SmallStraight < 4)
            {
                SmallStraight = 0;
            }
            if (howMany[i] == 4)
            {
                ofAKind = 4;
            }
            if (howMany[i] == 3)
            {
                ofAKind = 3;
            }
        }
        if (LargeStraight == 5)
        {
            printf("Large Straight!\n\n");
        }
        else if (SmallStraight >= 4)
        {
            printf("Small Straight!\n\n");
        }
        else if (FullHouse == 5)
        {
            printf("Full House!!\n\n");
        }
        else if (CSlam == 1)
        {
            printf("CSlam!!!\n\n");
        }
        else if (ofAKind == 4)
        {
            printf("Four of a kind!!\n\n");
        }
        else if (ofAKind == 3)
        {
            printf("Three of a kind!\n\n");
        }
        else if (TwoPair == 2)
        {
            printf("Two Pair!\n\n");
        }
        else
        {
            printf("You got nothing.\n\n");
        }

        if (numberOfRolls != NUMBEROFREROLLS)
        {
            char Answer;
            printf("Do you want to reroll?  ");
            scanf(" %c", &answer);
        }
        ofAKind = 0;
        FullHouse = 0;
        TwoPair = 0;
        CSlam = 0;
        LargeStraight = 0;
        SmallStraight = 0;

    } while (toupper(answer) == 'Y' && numberOfRolls < NUMBEROFREROLLS);

    return 0;
}