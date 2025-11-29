#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node *createNode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = val;
    newnode->next = NULL;
    return newnode;
}

void push(int val)
{
    struct node *newnode = createNode(val);
    newnode->next = start;
    start = newnode;
}

void pop()
{
    if (start == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    printf("Popped: %d\n", temp->info);
    free(temp);
}

void enqueue(int val)
{
    struct node *newnode = createNode(val);

    if (start == NULL) {
        start = newnode;
        return;
    }

    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void dequeue()
{
    if (start == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = start;
    start = start->next;
    printf("Dequeued: %d\n", temp->info);
    free(temp);
}

void display()
{
    struct node *temp = start;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val;

    while (1) {
        printf("\n1.Push (Stack)\n2.Pop (Stack)\n");
        printf("3.Enqueue (Queue)\n4.Dequeue (Queue)\n");
        printf("5.Display\n6.Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 4:
            dequeue();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);
        }
    }
}
