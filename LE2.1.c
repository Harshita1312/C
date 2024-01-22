/*Given an array A of n elements, rearrange array such that even positioned
elements are greater than odd positioned elements.
i.e. sort the array according to the following relations:
A[i] >= A[i-1] ; if i is even, ∀ 1<=i<n
A[i] <= A[i-1] ; if i is odd, ∀ 1<=i<n
Input :
Enter size of the array: 5
Enter array elements: 2 4 3 5 6 
Output : 2 6 3 5 4    */

#include<stdio.h>

void sort(int arr[],int n) //2 3 4 5 6 
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

void rearrange(int arr[],int n,int ans[])
{
  int p=0,q=n-1;
  for(int i=0;i<n;i++)          
  {
     if ((i + 1) % 2 == 0)     
     { 
       //printf("q=%d ",q);
       ans[i] = arr[q--];
       //printf("q=%d ",q);
     }
     else
     {    
       ans[i] = arr[p++];
     }
  }  
}
/* DRY RUN
 i=0, else arr[1]
 i=1, if arr[4]
 i=2, else arr[
 */

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
  sort(arr,n);
  //print(arr,n);
  rearrange(arr,n,ans);
  print(ans,n);
  
  return 0;
}
  
