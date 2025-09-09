#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pancake
{
    char name[100];
    int calorie;
    struct pancake *next;
};
struct pancake *head = NULL;

void push_pancake()
{
    char name[100];
    int calorie;
    struct pancake *newpancake = (struct pancake *)malloc(sizeof(struct pancake));
    printf("Enter pancake name and its calories: ");
    scanf("%s%d", name, &calorie);
    strcpy(newpancake->name, name);
    newpancake->calorie = calorie;
    newpancake->next = head;
    head = newpancake;
}

void display()
{
    int total = 0;
    struct pancake *traverse = (struct pancake *)malloc(sizeof(struct pancake));
    traverse = head;
    if (traverse == NULL)
    {
        printf("The stack is empty till now.\n");
    }
    else
    {
        while (traverse != NULL)
        {
            total = total + traverse->calorie;
            printf("%-15s   %d\n", traverse->name, traverse->calorie);
            traverse = traverse->next;
        }
        printf("\nTotal Calories: %d\n", total);
    }
}
void pop_pancake()
{
    struct pancake *traverse = (struct pancake *)malloc(sizeof(struct pancake));
    traverse = head;
    head = head->next;
    free(traverse);

    printf("A pancake has been removed from the top of the stack.\n");
}
void menu()
{
    printf("0) Exit program.\n");
    printf("1) Clear screen.\n");
    printf("2) Display the pancake stack.\n");
    printf("3) Push a pancake.\n");
    printf("4) Push a pancake.\n");
}
void clear_screen()
{
    system("clear");
    menu();
}
int main()
{
    int choice;
    menu();

    do
    {
        printf("\nEnter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case (0):
            printf("Process returned 0(0*0)\n");
            printf("Enter any character to exit.");
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
            push_pancake();
            break;
        case (4):
            pop_pancake();
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 0);
    return 0;
}