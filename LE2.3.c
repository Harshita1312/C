/* Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array.
Test Case
Input:
Enter n: 9
Enter array elements: 0 1 2 3 4 5 6 7 10
Enter m: 11
Output: 8
*/
#include<stdio.h>
void sort(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
      {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }   
  }   
}

void search(int arr[],int n,int m)
{
  int a=0,found=0;
  for(int i=0;i<n;i++)
  {
    if(found==0)
    {
     if(arr[i]!=a)
     { 
       found=1;
       printf("Smallest no.missing is %d\n",a);
     }
    }
    a++;
  }
}    

int main()
{ 
  int n,m;
  printf("Enter size of sorted array(n): ");
  scanf("%d",&n);
  printf("Enter a value>n (m): ");
  scanf("%d",&m);
  int arr[n];
  //input array
  int i=0;
  printf("Enter array elements: ");
  while(i<n)
  {
   scanf("%d",&arr[i]);
   i++;
  }
  sort(arr,n);
  search(arr,n,m);
  
  return 0;
}
