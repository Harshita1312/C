/* Write a menu driven program to perform the following operations in a stack using linked list by using suitable user defined functions for each case.
1. Push
2. Pop
3. Check stack is empty or not
4. Check stack is full or not
5. Display stack elements
6. Exit  */

#include<stdio.h>
#include <stdlib.h>

struct stack
{
  int data;
  struct stack* next;
} *top=NULL;

//3.CHECK STACK IS EMPTY OR NOT
int isEmpty()
{
  if( top == NULL )
      return 1;
  else
      return 0;
}
//4.CHECK STACK IS FULL OR NOT
int isFull()
{
      return 0;  // Linked lists can never be full
}
//1. PUSH OPERATION IN STACK
void push(int data)
{
  struct stack* temp;
  temp = malloc(sizeof(struct stack));
  if(temp == NULL)
  {
     printf("Stack overflow\n");
     exit(1);
  }
  temp->data = data;
  temp->next = NULL;
  temp->next = top;
  top = temp;
}
//2. POP OPERATION IN STACK
int pop()
{
  int value;
  if(isEmpty())
  {
     printf("stack underflow..\n");
     exit(1); //termination of program with failure
  }
  struct stack* temp = top; 
  value = temp->data;
  top = top->next;
  free(temp);
  temp = NULL;
  return value;
}
//5. DISPLAY STACK
void display()
{ 
  struct stack* temp;
  temp=top;
  if(isEmpty())
  {
     printf("stack underflow..\n");
     exit(1); //termination of program with failure
  }
  printf(" element of stack: ");
  while(temp)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}


int main()
{
  int ch,data;
  
  // menu driven program
    printf("***MENU CHOICE***\n");
    printf("1: Push\n");
    printf("2: Pop\n");
    printf("3: Check stack is empty or not\n");
    printf("4: Check stack is full or not\n");
    printf("5: Display stack elements\n");
    printf("6: Exit\n");  
    while(1)
    {
       printf("Enter option: ");
       scanf("%d",&ch);
       //switch case
       switch(ch)
       {
         case 1:
           printf("Enter element to be pushed: ");
           scanf("%d",&data);
           push(data);           
           break;
         case 2:
           data = pop();
           printf("Deleted element is %d\n",data);
           break;
         case 3:
           if(isEmpty())
              printf("stack is empty\n");
           else
              printf("stack is not empty\n");
           break;
         case 4:
           if(isFull())
              printf("stack is full\n");
           else
              printf("stack is not full\n");
           break;
         case 5:
           display();
           break;
         case 6:
           printf("QUITING...\n");
           return 0;
         default:
          printf("invalid choice\n");
       }
    }
 
  return 0;
}
