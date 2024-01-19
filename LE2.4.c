/* Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false.
Test Case
Input:
Enter size of the array: 5
Enter array elements: 1 2 3 4 5
Enter sum = 9
Output: 5 3 1
Explanation:
There is a triplet (5, 3 and 1) present in the array whose sum is 9. */
#include <stdio.h>
#include <stdbool.h>

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

bool search(int arr[],int n,int sum)
{ 
  for(int i=0;i<n;i++)
  {
    if(i>0 && arr[i] == arr[i-1])
      continue;
    int j=i+1;
    int k=n-1;
    while(j<k)
    {
      int s=arr[i]+arr[j]+arr[k];
      if(s<sum)
       j++;
      else if(s>sum)
       k--;
      else
      {
        printf("triplet (%d,%d and %d) whose sum equals to %d\n",arr[i],arr[j],arr[k],sum);
        return true;
        j++;
        k--;
        while(j<k && arr[j]==arr[j-1])
        {
          j++;
        }
        while(j<k && arr[k]==arr[k+1])
        {
          k--;
        }
      }
    }
  }
  return false;
}      
      
int main()
{ 
  int n,sum;
  printf("Enter size of array: ");
  scanf("%d",&n);
  printf("Enter sum: ");
  scanf("%d",&sum);
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
  bool result=search(arr,n,sum);
  
  if (result==false)
    printf("No triplet found in array whose sum equals %d\n",sum);   
  
  return 0;
}
