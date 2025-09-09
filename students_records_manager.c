#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students
{
    char fname[50];
    char lname[50];
    float score;
    char nationality[50];
};

void DisplayMenu()
{
    printf("\nSelect a numeric choice from the given menu:\n\n");
    printf("0) Exit program.\n\n");
    printf("1) Clear screen.\n\n");
    printf("2) Print all student records.\n\n");
    printf("3) Search records by first name.\n\n");
    printf("4) Search records by last name.\n\n");
    printf("5) Search records by Grade (>=).\n\n");
    printf("6) Print List, total, count, and average score for all American students.\n\n");
    printf("7) Save the records of British students in British.txt.\n\n");
    printf("8) Sort all records by First name.\n\n");
    printf("9) Sort by records by Last name.\n\n");
    printf("10) Sort all records by scores.\n\n");
}

void PrintAll_2(struct students array[])
{
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf(" %-10s%-10s %.1f\t%-10s\n", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
    }
}
void SearchByFirstName_3(struct students array[])
{
    char first_name[50];
    printf("\nEnter student's first name:");
    scanf("%s", first_name);
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(first_name, array[i].fname) == 0)
        {
            printf(" %-10s%-10s%.1f \t%-10s", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
        }
    }
    printf("\n");
}
void SearchByLastName_4(struct students array[])
{
    char last_name[50];
    printf("\nEnter student's last name:");
    scanf("%s", last_name);
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(last_name, array[i].lname) == 0)
        {
            printf(" %-10s%-10s%.1f \t%-10s", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
        }
    }
    printf("\n");
}
void SearchByGrade_5(struct students array[])
{
    float grades;
    printf("Enter grade: ");
    scanf("%f", &grades);
    for (int i = 0; i < 6; i++)
    {
        if (array[i].score >= grades)
        {
            printf(" %-10s%-10s%.1f \t%-10s\n", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
        }
    }
    printf("\n");
}

void AmericanStudentDetails_6(struct students array[])
{
    float total = 0;
    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(array[i].nationality, "American") == 0)
        {
            printf(" %-10s%-10s%.1f \t%-10s\n", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
            total = total + array[i].score;
            count++;
        }
    }
    printf("Total= %.1f\tCount=%d\t  Average= %.1f\n", total, count, total / count);
    printf("\n");
}
void SaveBritishRecords_7(struct students array[])
{
    FILE *file = fopen("British.txt", "w");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(array[i].nationality, "British") == 0)
        {
            fprintf(file, "%-10s%-10s\t %.1f\n", array[i].fname, array[i].lname, array[i].score);
        }
    }
    fclose(file);

    printf("British students saved to British.txt\n");
    printf("British.txt\n");
    FILE *file1 = fopen("British.txt", "r");
    char ch;
    while ((ch = fgetc(file1)) != EOF)
    {
        putchar(ch); // Print character to console
    }
    fclose(file1);
}
void SortByFirstName_8(struct students array[], struct students temp)
{
    for (int i = 0; i < 6 - 1; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (strcmp(array[j].fname, array[j + 1].fname) > 0)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf(" %-10s%-10s%.1f \t%-10s\n", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
    }
    printf("\n\n");
}
void SortByLastName_9(struct students array[], struct students temp)
{
    for (int i = 0; i < 6 - 1; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (strcmp(array[j].lname, array[j + 1].lname) > 0)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf(" %-10s%-10s%.1f \t%-10s\n", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
    }
    printf("\n\n");
}
void SortByScores_10(struct students array[], struct students temp)
{
    for (int i = 0; i < 6 - 1; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (array[j].score > array[j + 1].score)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf(" %-10s%-10s%.1f \t%-10s\n", array[i].fname, array[i].lname, array[i].score, array[i].nationality);
    }
    printf("\n\n");
}
int main()
{
    int user_choice;
    struct students array[6] = {
        {"Isaac", "Newton", 3.7, "British"},
        {"Charles", "Darwin", 3.7, "British"},
        {"Nikola", "Tesla", 3.8, "American"},
        {"Henry", "Ford", 3.9, "American"},
        {"Albert", "Einstein", 4.1, "American"},
        {"Marie", "Curie", 4.2, "French"}};
    struct students temp;
    DisplayMenu();
    do
    {
        printf("\nEnter a choice.\n");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 0:
            printf("Process returned 0 (0×0)\n");
            printf("Press any key to continue.\n");
            getchar();
            getchar();
            break;
        case 1:
            system("clear");
            DisplayMenu();
            break;
        case 2:
            PrintAll_2(array);
            break;
        case 3:
            SearchByFirstName_3(array);
            break;
        case 4:
            SearchByLastName_4(array);
            break;
        case 5:
            SearchByGrade_5(array);
            break;
        case 6:
            AmericanStudentDetails_6(array);
            break;
        case 7:
            SaveBritishRecords_7(array);
            break;
        case 8:
            SortByFirstName_8(array, temp);
            break;
        case 9:
            SortByLastName_9(array, temp);
            break;
        case 10:
            SortByScores_10(array, temp);
            break;
        default:
            printf("Invalid choice!\n");
        }

    } while (user_choice != 0);

    return 0;
}
