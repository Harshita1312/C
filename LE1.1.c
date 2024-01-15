#include<stdio.h>

void compare( int *num1, int *num2) /*  '*' for value at address */
{
 if(*num1>*num2)
 {
   printf("%d is greater than %d \n",*num1,*num2);
 }
 else if(*num1<*num2)
 {
  printf("%d is greater than %d \n",*num2,*num1);
 }
 else
 {
  printf("Both numbers are equal\n");
 }
}

int main()
 {
   int num1,num2;
   printf("enter two numbers: ");
   scanf("%d %d",&num1,&num2); /* & for call by address */
   compare(&num1,&num2);
   return 0;
 }
/* input two numbers and compare greater,smaller,equal */
