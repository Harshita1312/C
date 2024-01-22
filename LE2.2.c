/* Given a sorted array of positive integers, rearrange the array alternately i.e first element should be a maximum value, at second position minimum value, at third position second max, at fourth position second min, and so on.
Test Case
Input:
Enter size of the array: 7
Enter array elements: 1 2 3 4 5 6 7
Output: 7 1 6 2 5 3 4                        */

#include<stdio.h>

void rearrange(int arr[],int n,int ans[])
{
  int p=0,q=n-1;
  for(int i=0;i<n;i++)          
  {
     if ((i + 1) % 2 != 0)     
     {  
       ans[i] = arr[q--];
     }
     else
     {    
       ans[i] = arr[p++];
     }
  }  
}

void print(int arr[],int n)
{ 
  printf("rearranged array: ");
  for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  
}

int main()
{ 
  int n,ch;
  printf("enter size of array: ");
  scanf("%d",&n);
  int arr[n];
  int ans[n];
  //input array
  int i=0;
  printf("enter array elements: ");
  while(i<n)
  {
   scanf("%d",&arr[i]);
   i++;
  }
  rearrange(arr,n,ans);
  print(ans,n);
  
  return 0;
}
  
