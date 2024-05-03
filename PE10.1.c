//MERGE SORT
#include<stdio.h>

// ENTER ONE ARRAY [ 7 15 | 2 8 10 ] AND MERGE SORT THEM
//                   L  M        H     

void EnterArray(int *arr,int size)
{
  //input array
  int i=0;
  printf("Enter array elements: ");
  while(i<size)
  {
   scanf("%d",&arr[i]);
   i++;
  }
}
// MERGE SORT
void Merge(int *arr, int low,int mid,int high)
{
  int merge[high+1];
  int i, j, k;
  i=low, j=mid+1, k=low;
  
  while( i <= mid && j <= high)
  {
    if(arr[i] < arr[j])
      merge[k++] = arr[i++];
    else
      merge[k++] = arr[j++];
  }
  while( i <= mid )
     merge[k++] = arr[i++];
  while( j <= high )
     merge[k++] = arr[j++];
  //copying the elements back to the original array    
  for(i=low; i<=high; i++)
  {
     arr[i] = merge[i];
  }
} 
//RECURSIVE MERGE SORT
void MergeSort(int arr[], int low, int high)
{ 
  if(low < high)
  {
    int mid = (low+high)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
  }
}

// PRINT ARRAY
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
  int n, low, high;
  
  printf("Sample Input:\n");
  printf("Enter size of array: ");
  scanf("%d",&n);
  int arr[n];
  EnterArray(arr, n);
  
  low = 0, high = n-1;

  MergeSort(arr, low, high);
  print(arr,n);
  return 0;
}

/*   // ENTER TWO DIFFERENT SORTED ARRAY AND MERGE SORT THEM
//enter sorted array to merge them
void EnterArray(int *arr,int size)
{
  //input array
  int i=0;
  printf("Enter array elements: ");
  while(i<size)
  {
   scanf("%d",&arr[i]);
   i++;
  }
}
// MEREG SORT
void MergeSort(int merge[],int arr_n[],int arr_m[],int n,int m)
{
  int i=0, j=0, k=0;
  while( i < n && j < m)
  {
    if(arr_n[i] < arr_m[j])
      merge[k++] = arr_n[i++];
    else
      merge[k++] = arr_m[j++];
  }
  while( i < n )
     merge[k++] = arr_n[i++];
  while( i < m )
     merge[k++] = arr_m[j++];
}  */

