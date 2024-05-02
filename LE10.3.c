// BINARY SEARCH

#include<stdio.h>

// FOR BINARY SEARCH WE NEED TO SORT THE ARRAY FIRST
void InsertionSort(int *arr,int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1-i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }   
  }   
}
// BINARY SEARCH
int BinarySearch(int arr[],int n,int key)
{
  int low = 0;
  int high = n-1;
  int found = 0;
  
  while(low <= high)
  {
    int mid = (low+high)/2;
    if(key == arr[mid])
    {
       found=1;
       return found;
    }
    if(key < arr[mid])
      high = mid-1;
    else
      low = mid+1;
  }
  return found;       
}


int main()
{ 
  int n,f,key;
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
  printf("Enter element to be searched: ");
  scanf("%d",&key);
  
  InsertionSort(arr,n);
  f = BinarySearch(arr,n,key);
  
  printf("Sample Output:\n");
  if(f == 1)
     printf("Element found\n");
  else
     printf("Element not found\n");
  
  return 0;
}
