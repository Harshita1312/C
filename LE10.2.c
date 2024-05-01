//QUICK SORT
#include<stdio.h>

int partition(int *arr,int low,int high)
{
  int pivot = arr[low];
  int i = low+1;
  int j = high;
  
  do
  { 
    while(arr[i]<=pivot)
        i++;
    while(arr[j]>pivot)
        j--; 
    if(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    } 
  } while(i<j);
  //SWAP ARR[LOW] AND ARR[J]
  int temp=arr[low];
  arr[low]=arr[j];
  arr[j]=temp;
  return j; //partition index
}

void QuickSort(int arr[],int low,int high)
{
  int partitionIndex; //index of pivot after partition
  
  if(low<high)
  {
    partitionIndex = partition(arr, low, high);
    QuickSort(arr, low, partitionIndex-1); //sort left side of pivot
    QuickSort(arr, partitionIndex+1, high); //sort right side of pivot
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
  QuickSort(arr, 0, n-1);
  print(arr,n);
  return 0;
}
