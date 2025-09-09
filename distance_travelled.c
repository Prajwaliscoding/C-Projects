#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct city
{
    char name[100];
    int distance;
    struct city *next;
};
struct city *head = NULL;
void menu()
{
    printf("0) Exit program.\n");
    printf("1) Clear screen.\n");
    printf("2) Print all cities.\n");
    printf("3) Add a city.\n");
    printf("4) Delete a city by city name.\n");
    printf("5) Insert a city by position.\n");
}
void clear_screen()
{
    system("clear");
    menu();
}
void add()
{
    char name[100];
    int distance;
    struct city *newcity = (struct city *)malloc(sizeof(struct city));
    printf("Enter the city and the distance from previous city:");
    scanf("%s%d", name, &distance);
    strcpy(newcity->name, name);
    newcity->distance = distance;
    newcity->next = head;
    head = newcity;
}
void display()
{
    int total = 0;
    struct city *traverse;
    traverse = head;
    if (traverse == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        while (traverse != NULL)
        {
            printf("%-15s   %d\n", traverse->name, traverse->distance);
            total = total + traverse->distance;
            traverse = traverse->next;
        }
        printf("\nTotal distance=%d\n", total);
    }
    free(traverse);
}
int main()
{
    int choice;
    menu();
    do
    {
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case (0):
            printf("Process returned (0*0)");
            printf("Enter any key to exit");
            getchar();
            getchar();
            break;
        case (1):
            clear_screen();
            break;
        case (2):
            display();
            break;
        case (3):
            add();
            break;
        default:
            printf("Invalid choice.");
        }

    } while (choice != 0);

    return 0;
}