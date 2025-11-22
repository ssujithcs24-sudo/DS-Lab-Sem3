#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1, maxsize = 5;

void enqueue(int queue[], int ele)
{
    if(rear == maxsize - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    else if(front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = ele;
    }
    else
    {
        rear++;
        queue[rear] = ele;
    }
}
int dequeue(int queue[])
{
    int item;
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else if(front == rear)
    {
        int ele = queue[front];
        front = rear = -1;
        return ele;
    }
    else
    {
        item = queue[front];
        front++;
        return item;
    }
}
void display(int queue[])
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    printf("Queue elements: ");
    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main()
{
    int queue[5], choice, ele;
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            printf("Enter element to enqueue: ");
            scanf("%d", &ele);
            enqueue(queue, ele);
        }
        else if(choice == 2)
        {
            ele = dequeue(queue);
            if(ele != -1)
                printf("Dequeued element: %d\n", ele);
        }
        else if(choice == 3)
            display(queue);
        else if(choice == 4)
            exit(0);
        else
                printf("Invalid choice\n");
    }
}