#include<stdio.h>

struct complex
 {
  float real;
  float imag;
 };
 
struct complex add(struct complex num1, struct complex num2)
 {
  struct complex result;
  result.real=num1.real+num2.real;
  result.imag=num1.imag+num2.imag;
  return result;
 }

void multiply(struct complex *num1, struct complex *num2)
 {
  float realpart=(num1->real * num2->real)-(num1->imag * num2->imag);
  float imagpart=(num1->imag * num2->real)+(num1->real * num2->imag);
  num1->real= realpart;
  num1->imag= imagpart;
 }

int main()
{
 struct complex num1,num2,result;
 int choice;
 printf("enter the real and imag part of ist complex no: ");
 scanf("%f %f",&num1.real,&num1.imag);
 printf("enter the real and imag part of 2nd complex no: ");
 scanf("%f %f",&num2.real,&num2.imag);

 printf("***MENU***\n");
 printf("1.ADDITION\n");
 printf("2.MULTIPLICATION\n");
  while(1)
 {
 printf("Enter your choice: ");
 scanf("%d",&choice);
 
 switch(choice)
 {
  case 1:
  result=add(num1,num2);
  printf("Sum= %.2f + %.2fi\n",result.real,result.imag);
  break;
  
  case 2:
  multiply(&num1,&num2);
  printf("Product= %.2f + %.2fi\n",num1.real,num1.imag);
  break;
  
  default:
  printf("Invalid choice\n");
  return 0;
 }
 }
return 0;
}
 
/* input two complex numbers and perform addition (call by value) and 
   multiplication (call by address) of those two numbers using function */
   
 
 
 
 
 
 
 
 
 
 
 
