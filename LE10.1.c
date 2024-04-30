//INSERTION SORT
#include<stdio.h>

void InsertionSort(int *arr,int n)
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
void print(int arr[],int n)
{ 
  printf("Sample Output:\n");
  printf("Non-decreasing order:: ");
  for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  printf("Non-increasing order:: ");
  for(int i=n;i>0;i--)
  {
    printf("%d ",arr[i-1]);
  }
  printf("\n");
}

int main()
{ 
  int n;
  printf("Sample Input:\n");
  printf("Enter size of array: ");
  scanf("%d",&n);
  int arr[n];
  //input array
  int i=0;
  printf("Enter array elements: ");
  while(i<n)
  {
   scanf("%d",&arr[i]);
   i++;
  }
  InsertionSort(arr,n);
  print(arr,n);
  return 0;
}
