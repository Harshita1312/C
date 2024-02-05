/* Write a program to convert infix expression to postfix operation using stack.
Test Case
Input:
Enter infix expression: (a+b)/c*d-e^f
Output:
Postfix: ab+c/d*ef^-    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX],posfix[MAX];
int top=-1;

void push(char);
char pop();
int isEmpty();
void infixToPosfix();
int space(char);
void display();
int precedence(char);

int main()
{
   printf("Enter the infix expression: ");
   fgets(infix, MAX, stdin);
   
   infixToPosfix();
   display();
   return 0;
} 

int precedence(char symbol)
{
  switch(symbol)
  {
    //higher return value for greater precedence
    case '^':
      return 3;
    case '/':
    case '*':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;    
  }
}

void infixToPosfix() //CONVERSION
{
  int j=0;
  char symbol,next;
  for( int i=0; i<strlen(infix) ; i++)
  {
     symbol=infix[i];
     //if symbol is not whitespace
     if(!space(symbol))
     {
     switch(symbol)
     {
       case '(':
         push(symbol);
         break;
       case ')':
         while( (next=pop()) != '(' )
            posfix[j++] = next; 
         break;
       case '+':
       case '-':
       case '*':
       case '/':
       case '^':
         while( !isEmpty() && precedence(stack[top]) >= precedence(symbol) )
            posfix[j++] = pop(); 
         push(symbol);
         break;
       default:
         posfix[j++] = symbol; 
     }
     }
  }
  while(!isEmpty())
  {
       posfix[j++] = pop();
  }
  posfix[j] = '\0';
}

int space(char c)
{
  //if symbol is a blank space or tab
  if( c==' ' || c=='\t' )
     return 1;
  else
     return 0;
}
void push(char data)
{
  if(top == MAX-1)
  {
    printf("stack overflow\n");
    return;
  }
  top++;
  stack[top] = data;
}
char pop()
{
  char value;
  if( top == -1 )
  {
     printf("stack underflow\n");
     exit(1); //termination of program with failure
  }
  value = stack[top];
  top--;
  return value;
}
//5. DISPLAY STACK
void display()
{
  int i=0;
  printf("Euivalent posfix expression: ");
  while(posfix[i])
  {
    printf("%c",posfix[i++]);
  }
  printf("\n");
}
//3.CHECK STACK IS EMPTY OR NOT
int isEmpty()
{
  if( top == -1 )
      return 1;
  else
      return 0;
}



