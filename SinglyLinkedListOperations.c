#include <stdio.h>
#include <stdlib.h>

struct node
{
   int info;
   struct node *next;
};

struct node *start = NULL;

struct node *createList()
{
   struct node *newnode, *temp;
   int n, val, i;

   printf("Enter number of nodes: ");
   scanf("%d", &n);

   if (n <= 0)
      return start;

   for (i = 0; i < n; i++)
   {
      newnode = (struct node *)malloc(sizeof(struct node));
      printf("Enter value: ");
      scanf("%d", &val);
      newnode->info = val;
      newnode->next = NULL;

      if (start == NULL)
      {
         start = newnode;
         temp = start;
      }
      else
      {
         temp->next = newnode;
         temp = newnode;
      }
   }
   return start;
}

struct node *insertfirst(int val)
{
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   newnode->info = val;
   newnode->next = start;
   start = newnode;
   return start;
}

struct node *insertend(int val)
{
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   struct node *temp = start;
   newnode->info = val;
   newnode->next = NULL;

   if (start == NULL)
   {
      start = newnode;
      return start;
   }

   while (temp->next != NULL)
      temp = temp->next;

   temp->next = newnode;
   return start;
}

struct node *insertatpos(int val, int pos)
{
    struct node *newnode, *temp = start;
   int i;

   if (pos == 1)
      return insertfirst(val);

    newnode = (struct node *)malloc(sizeof(struct node));
   newnode->info = val;

   for (i = 1; i < pos - 1 && temp != NULL; i++)
      temp = temp->next;

   if (temp == NULL)
   {
      printf("Invalid position\n");
      free(newnode);
      return start;
   }
   newnode->next = temp->next;
   temp->next = newnode;
   return start;
}

struct node *deletefirst()
{
   struct node *temp;

   if (start == NULL)
      return start;

   temp = start;
   start = start->next;
   free(temp);
   return start;
}

struct node *deleteend()
{
    struct node *temp = start, *prev;

   if (start == NULL)
      return start;

   if (start->next == NULL)
   {
      free(start);
      start = NULL;
      return start;
   }

   while (temp->next != NULL)
   {
      prev = temp;
      temp = temp->next;
   }

   prev->next = NULL;
   free(temp);
   return start;
}

struct node *deleteatpos(int pos)
{
   struct node *temp = start, *prev;
   int i;

   if (start == NULL)
      return start;

   if (pos == 1)
      return deletefirst();

   for (i = 1; i < pos && temp != NULL; i++)
   {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL)
   {
      printf("Invalid position\n");
      return start;
   }

   prev->next = temp->next;
   free(temp);
   return start;
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

struct node *reversesll(struct node *start)
{
   struct node *temp, *cur = NULL, *prev = NULL;
   temp = start;

   while (temp != NULL)
   {
      prev = cur;
      cur = temp;
      temp = temp->next;
      cur->next = prev;
   }
   return cur;
}

struct node *sllconcat(struct node *start1, struct node *start2)
{
   struct node *temp;

   if (start1 == NULL)
      return start2;

   temp = start1;

   while (temp->next != NULL)
      temp = temp->next;

   temp->next = start2;

   return start1;
}

struct node *sortsll(struct node *start)
{
    struct node *i, *j;
   int temp;

   for (i = start; i != NULL; i = i->next)
   {
      for (j = i->next; j != NULL; j = j->next)
      {
         if (i->info > j->info)
         {
            temp = i->info;
            i->info = j->info;
            j->info = temp;
         }
      }
   }
   return start;
}

int main()
{
   int choice, val, pos;
    struct node *start2 = NULL;

   while (1)
   {
      printf("\n1.Create\n2.Insert First\n3.Insert End\n4.Insert at Position\n");
      printf("5.Delete First\n6.Delete End\n7.Delete at Position\n8.Display\n");
      printf("9.Concatenate Another List\n10.Reverse\n11.Sort\n12.Exit\n");

      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         start = NULL;
         createList();
         break;

      case 2:
         printf("Enter value: ");
         scanf("%d", &val);
         insertfirst(val);
         break;

      case 3:
         printf("Enter value: ");
         scanf("%d", &val);
         insertend(val);
         break;

      case 4:
         printf("Enter value and position: ");
         scanf("%d %d", &val, &pos);
         insertatpos(val, pos);
         break;

      case 5:
         deletefirst();
         break;

      case 6:
         deleteend();
         break;

      case 7:
         printf("Enter position: ");
         scanf("%d", &pos);
         deleteatpos(pos);
         break;

      case 8:
         display();
         break;

      case 9:
         printf("Creating second list:\n");

         start2 = NULL;
         struct node *backup = start;

         start = NULL;
         createList();
         start2 = start;

         start = backup;
         start = sllconcat(start, start2);
         printf("Lists concatenated\n");
         break;

      case 10:
         start = reversesll(start);
         printf("List reversed\n");
         break;

      case 11:
         start = sortsll(start);
         printf("List sorted\n");
         break;

      case 12:
         exit(0);
      }
   }
}
