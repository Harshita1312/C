#include <stdio.h>
#include <stdlib.h> //header file for malloc()
int sum(int *q,int n)
{
	int s=0,i,j,c=0;
	for(i=0;i<n;i++)
	{
 		for(j=1;j<=q[i];j++)
 		 {
  			 if(q[i]%j==0)
    			{
     				c++;
    			}
  		 }
    		 if(c==2)
     		{
      			s=s+q[i];
     		}
		c=0;
	}
 	return s;
}
int main()
{
	int *p,n,i,s;
	printf("enter size of array: ");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	 {
	    printf("enter element %d : ",i+1);
	    scanf("%d",&p[i]);
	 }
	   s=sum(p,n);
	   printf("sum of prime elements = %d\n",s);
	   free (p);
	   return 0;
}

/* malloc()-it allocates dynamic memory at run time. it automatically initizalises each block of memory with garbage value
syntax:  ptr=(type*)malloc(n*sizeof(type));  
  
  calloc()-it allocates dynamic memory at run time. it automatically initizalises each block of memory with zero value
syntax:  ptr=(type*)calloc(n,sizeof(type)); 

   free()-it deallocates dynamically allocated memory.
syntax:  free(ptr); 
    
   realloc()- it is used to reallocate dynamic memory which is allocated through calloc() or malloc() function
syntax: ptr= realloc(ptr,newsize);
  */ 

