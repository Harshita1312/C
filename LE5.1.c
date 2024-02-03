/* Write a menu driven program to perform the following operations in a stack using array by using suitable user defined functions for each case.
1. Push
2. Pop
3. Check stack is empty or not
4. Check stack is full or not
5. Display stack elements
6. Exit */

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

// globally initializing stack as array
int top=-1; // index of topmost element in array
int stack_arr[MAX];

//3.CHECK STACK IS EMPTY OR NOT
int isEmpty()
{
  if( top == -1 )
      return 1;
  else
      return 0;
}
//4.CHECK STACK IS FULL OR NOT
int isFull()
{
  if(top == MAX-1 )
      return 1;
  else
      return 0;
}
//1. PUSH OPERATION IN STACK
void push(int data)
{
  if(isFull())
  {
    printf("stack overflow\n");
    return;
  }
  top++;
  stack_arr[top] = data;
}
//2. POP OPERATION IN STACK
int pop()
{
  int value;
  if(isEmpty())
  {
     printf("stack underflow\n");
     exit(1); //termination of program with failure
  }
  value = stack_arr[top];
  top--;
  return value;
}

//5. DISPLAY STACK
void display()
{
  int i;
  if( top==-1)
  {
     printf("stack underflow\n");
     return;
  }
  printf("Stack: ");
  for(i=top;i>=0;i--)
    printf("%d ",stack_arr[i]);
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


