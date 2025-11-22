#include<stdio.h>
#include<stdlib.h>

int stack[5];
int top = -1, maxsize = 5;

void insertS(int item)
{
   if(top == maxsize - 1)
   {
      printf("Stack Overflow\n");
      return;
   }
   else
   {
      top++;
      stack[top] = item;
   }
}
int deleteS()
{
   int item;
   if(top == -1)
   {
      printf("Stack Underflow\n");
      return -1;
   }
   else
   {
      item = stack[top];
      top--;
      return item;
   }
}
void display()
{
   int i;
   if(top == -1)
   {
      printf("Stack is empty\n");
      return;
   }
   printf("Stack elements: ");
   for(i = top; i >= 0; i--)
      printf("%d ", stack[i]);
   printf("\n");
}

int main()
{
   int choice, item;
   while(1)
   {
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      if(choice == 1)
      {
         printf("Enter the element to push: ");
         scanf("%d", &item);
         insertS(item);
      }
      else if(choice == 2)
      {
         item = deleteS();
         if(item != -1)
            printf("Popped element: %d\n", item);
      }
      else if(choice == 3)
      {
         display();
      }
      else if(choice == 4)
      {
         exit(0);
      }
      else
      {
         printf("Invalid choice.\n");
      }
   }
   return 0;
}