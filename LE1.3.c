#include<stdio.h>

//1. traversal of the array
void traverse(int arr[],int n)
{
  printf("Array elements: ");
  for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}
  
//2.insert a given element at specific position
void insert(int arr[],int n)
{
  int a,_n;
  printf("element to insert: ");
  scanf("%d",&a);
  printf("enter position(0-%d): ",n);
  scanf("%d",&_n);
  for(int i=n;i>=_n;i--)
  {
    arr[i]=arr[i-1];
  }
  arr[_n]=a;
  //(n)++;
  printf("Element inserted\n");
}
 
//3.delete and element from a specific position of array
void delete(int arr[],int n)
{
  int pos;
  printf("enter position(0-%d) to delete element: ",n-1);
  scanf("%d",&pos);
  if(pos>=0 && pos<n)
  {
   int a=0;
   for(int i=0;i<n;i++)
   { 
     if(i!=pos)
     {
      arr[a]=arr[i];
      a++;
     }
     //i++;
   }
  }
  else
  {
   printf("invalid position\n");
  }
  printf("Element deleted\n");
  //printf("element %d was deleted\n",arr[pos]);
}

//4.linear search to search an element 
void search(int arr[],int n)
{
  int s;
  int found=0;
  printf("element to search: ");
  scanf("%d",&s);
  for(int i=0;i<n;i++)
   { 
     if(arr[i]==s)
     {
      found=1;
     }
   }
   if(found==1)
   {
      printf("%d was found\n",s);
   }
   else
   {
      printf("%d was not found\n",s);
   } 
}
 
 
int main()
{ 
  int n,ch;
  printf("enter size of array: ");
  scanf("%d",&n);
  int arr[n];
  //input array
  int i=0;
  while(i<n)
  {
   printf("enter element %d : ",i+1);
   scanf("%d",&arr[i]);
   i++;
  }
  // menu driven program
 
  printf("***MENU***\n");
  printf("1.Traverse\n2.Insert\n3.Delete\n4.Linear search\n5.Exit\n");
  while(1)
 {
  printf("Enter option: ");
  scanf("%d",&ch);
  //switch case
  switch(ch)
  {
    case 1:
     traverse(arr,n);
     break;
    case 2:
     insert(arr,n);
     n=n+1;
     break;
    case 3:
     delete(arr,n);
     n=n-1;
     break;
    case 4:
     search(arr,n);
     break;
    case 5:
     printf("EXITING...\n");
     return 0;
    default:
     printf("invalid choice\n");
  }
 }
  
  return 0;
}
  
