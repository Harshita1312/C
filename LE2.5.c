/*Given an array where each element represents the max number of steps that can be made forward from that index. The task is to find the minimum number of jumps to reach the end of the array starting from index 0. If the end isn’t reachable, return -1.
Test Case
Input:
Enter size of the array: 11
Enter array elements: 1 3 5 8 9 2 6 7 6 8 9
Output: 3 (1-> 3 -> 9 -> 9)
Explanation: Jump from 1st element to 2nd element as there is only 1 step.
Now there are three options 5, 8 or 9.
If 8 or 9 is chosen then the end node 9 can be reached. So, 3 jumps are made.*/
#include <stdio.h>
#include <limits.h> // for INT_MAX
#include <stdlib.h> // for array_length

int min_jumps(int arr[], int n) 
{
  // Initialize all values to -1.
  int jumps[n];
  for (int i = 0; i < n; i++)
    jumps[i] = -1;
 
  // minimum number of jumps to reach the first index
  jumps[0] = 0;
  int a=0;
  for (int i = 1; i < n; i++) 
  {
    int min_jumps = INT_MAX;
    for (int j = 0; j < i; j++) 
    {
      if (arr[j] + j >= i) 
      {
        min_jumps = (min_jumps<jumps[j] + 1)? min_jumps:jumps[j] + 1;
      }
     
    }
    jumps[i] = min_jumps;
    
    a++;
  }
  return jumps[n - 1];
}

int main()
{ 
  int n;
  printf("Enter size of the array: ");
  scanf("%d",&n);
  int arr[n];

  //input array
  int i=0;
  printf("Enter array elements: ");
  for (int i = 0; i < n; i++) 
  {
    scanf("%d", &arr[i]);
  }
  
  int jumps = min_jumps(arr, n);

  if (jumps == -1)
    printf("The end is not reachable.\n");
  else 
    printf("The minimum number of jumps is %d.\n", jumps);
  
  return 0;
 }
