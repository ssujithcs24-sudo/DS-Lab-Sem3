#include <stdio.h>
#include <stdlib.h>

struct node
{
   int info;
   struct node *next;
};

struct node *start = NULL;

void createList()
{
   int n, value, i;
   struct node *p, *temp;
   start = NULL;
   printf("Enter number of nodes: ");
   scanf("%d", &n);
   for (i = 0; i < n; i++)
   {
      printf("Enter value: ");
      scanf("%d", &value);
      p = (struct node *)malloc(sizeof(struct node));
      p->info = value;
      p->next = NULL;

      if (start == NULL)
         start = p;
      else
      {
         temp = start;
         while (temp->next != NULL)
            temp = temp->next;
         temp->next = p;
      }
   }
}

void insertsllbeg(int value)
{
   struct node *p = (struct node *)malloc(sizeof(struct node));
   p->info = value;
   p->next = start;
   start = p;
}

void insertsllatpos(int item, int pos)
{
   int i;
   struct node *p, *temp;

   p = (struct node *)malloc(sizeof(struct node));
   p->info = item;

   if (pos == 1)
   {
      p->next = start;
      start = p;
      return;
   }

   temp = start;
   for (i = 1; i < pos - 1 && temp != NULL; i++)
      temp = temp->next;

   if (temp == NULL)
   {
      printf("Invalid position\n");
      return;
   }

   p->next = temp->next;
   temp->next = p;
}

void insertsllend(int value)
{
   struct node *p, *temp;

   p = (struct node *)malloc(sizeof(struct node));
   p->info = value;
   p->next = NULL;

   if (start == NULL)
   {
      start = p;
      return;
   }
   temp = start;
   while (temp->next != NULL)
      temp = temp->next;
   temp->next = p;
}

void deletesllbeg()
{
   struct node *temp;

   if (start == NULL)
   {
      printf("List is empty\n");
      return;
   }

   temp = start;
   start = start->next;
   free(temp);

   printf("First node deleted\n");
}

void deletesllatpos(int pos)
{
   struct node *temp, *prev;
   int i;
   if (start == NULL)
   {
      printf("List is empty\n");
      return;
   }
   if (pos == 1)
   {
      temp = start;
      start = start->next;
      free(temp);
      printf("Node at position %d deleted\n", pos);
      return;
   }
   prev = start;
   temp = start->next;
   for (i = 2; i < pos && temp != NULL; i++)
   {
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL)
   {
      printf("Invalid position\n");
      return;
   }
   prev->next = temp->next;
   free(temp);
   printf("Node at position %d deleted\n", pos);
}

void deletesllend()
{
   struct node *temp, *prev;

   if (start == NULL)
   {
      printf("List is empty\n");
      return;
   }

   if (start->next == NULL)
   {
      free(start);
      start = NULL;
      printf("Last node deleted\n");
      return;
   }

   prev = start;
   temp = start->next;

   while (temp->next != NULL)
   {
      prev = temp;
      temp = temp->next;
   }

   prev->next = NULL;
   free(temp);

   printf("Last node deleted\n");
}

void display()
{
   struct node *temp = start;

   if (start == NULL)
   {
      printf("List is empty\n");
      return;
   }

   while (temp != NULL)
   {
      printf("%d ", temp->info);
      temp = temp->next;
   }
   printf("\n");
}

int main() 
{
   int choice, value, pos;

   while (1)
   {
      printf("\n1. Create List\n2. Insert at First\n3. Insert at Position\n4. Insert at End\n5. Display\n6. Delete at First\n7. Delete at Position\n8. Delete at end\n9. Exit\n");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         createList();
         break;

      case 2:
         printf("Enter value: ");
         scanf("%d", &value);
         insertsllbeg(value);
         break;

      case 3:
         printf("Enter value: ");
         scanf("%d", &value);
         printf("Enter position: ");
         scanf("%d", &pos);
         insertsllatpos(value, pos);
         break;

      case 4:
         printf("Enter value: ");
         scanf("%d", &value);
         insertsllend(value);
         break;

      case 5:
         display();
         break;

      case 6:
         deletesllbeg();
         break;

      case 7:
         printf("Enter value to delete: ");
         scanf("%d", &value);
         deletesllatpos(value);
         break;

      case 8:
         deletesllend();
         break;

      case 9:
         exit(0);

      default:
         printf("Invalid choice\n");
      }
   }
   return 0;
}
