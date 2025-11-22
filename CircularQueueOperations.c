#include<stdio.h>

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) 
{
   if ((rear + 1) % SIZE == front)
      printf("Queue Overflow\n");
   else if (front == -1)
   {
      front = 0;
      rear = (rear + 1) % SIZE;
      queue[rear] = value;
      printf("Inserted %d\n", value);
   }
}

void delete()
{
   if (front == -1)
      printf("Queue Underflow\n");
   else
   {
      printf("Deleted %d\n", queue[front]);
      if (front == rear)
            front = rear = -1;
      else
            front = (front + 1) % SIZE;
   }
}

void display() 
{
   if (front == -1)
      printf("Queue is Empty\n");
   else
   {
      int i = front;
      while (i != rear)
      {
         printf("%d ", queue[i]);
         i = (i + 1) % SIZE;
      }
      printf("%d\n", queue[rear]);
   }
}

int main()
{
   insert(10);
   insert(20);
   insert(30);
   insert(40);
   insert(50);
   insert(60);
   
   display();

   delete();
   delete();
   
   display();
   
   return 0;
}
