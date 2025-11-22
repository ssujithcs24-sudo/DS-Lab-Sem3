#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];  // changed to char to store operators
int topife = -1, indexpfe = -1;
char ife[100], pfe[100];
int maxsize = 100;

void input()
{
   printf("Enter the Infix Expression: ");
   scanf("%s", ife);
}
void push(char ele)
{
   if(topife == maxsize - 1)
   {
      printf("Stack Overflow\n");
      return;
   }
   stack[++topife] = ele;
}
char pop()
{
   if(topife == -1)
   {
      printf("Stack Underflow\n");
      exit(1);
   }
   return stack[topife--];
}
int OpPre(char op)
{
   if(op == '^')
      return 3;
   if(op == '*' || op == '/')
      return 2;
   if(op == '+' || op == '-')
      return 1;
   return 0;
}
void display()
{
   int i;
   printf("Postfix Expression: ");
   for(i = 0; i <= indexpfe; i++)
      printf("%c", pfe[i]);
   printf("\n");
}
void convert()
{
   for(int i = 0; i < strlen(ife); i++)
   {
      if(ife[i] == '(')
         push(ife[i]);
      else if(isalnum(ife[i]))
         pfe[++indexpfe] = ife[i];
      else if(ife[i] == ')')
      {
         while(topife != -1 && stack[topife] != '(')
         {
            pfe[++indexpfe] = pop();
         }
         if(topife != -1)
            pop();  // pop '('
         else
         {
            printf("Mismatched parentheses\n");
            exit(1);
         }
      }
      else
      {
         int pre = OpPre(ife[i]);
         while(topife != -1 && OpPre(stack[topife]) >= pre)
         {
            pfe[++indexpfe] = pop();
         }
         push(ife[i]);
      }
   }
}

int main()
{
   input();
   convert();
   while(topife != -1)
   {
      if(stack[topife] == '(' || stack[topife] == ')')
      {
         printf("Mismatched parentheses\n");
         exit(1);
      }
      pfe[++indexpfe] = pop();
   }
   display();
   return 0;
}