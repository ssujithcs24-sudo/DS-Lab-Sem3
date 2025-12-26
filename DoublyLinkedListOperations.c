// Write a program with functions to implement basic Doubly Linked List operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
}
*start = NULL;

void create_dll(int data)
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
}
void display_dll()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("Doubly Linked List is empty\n");
        return;
    }
    temp = start;
    printf("Doubly Linked List elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
void insert_to_left(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = data;
    new_node->prev = NULL;
    new_node->next = start;
    if (start != NULL)
        start->prev = new_node;
    start = new_node;
}
struct node *delete_node(int data)
{
    struct node *temp = start;
    while (temp != NULL)
    {
        if (temp->info == data)
        {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                start = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            return start;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list\n", data);
    return start;
}
int main()
{
    int choice, data;
    while (1)
    {
        printf("\nDoubly Linked List Operations Menu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Display Doubly Linked List\n");
        printf("3. Insert Node to the Left\n");
        printf("4. Delete Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                create_dll(data);
                break;
            case 2:
                display_dll();
                break;
            case 3:
                printf("Enter data to insert at left: ");
                scanf("%d", &data);
                insert_to_left(data);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete_node(data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
