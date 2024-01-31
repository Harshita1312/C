/*Write a menu driven program to perform the following operations in a single linked list (using self-referencing structure) by using suitable user defined unctions for each case.
a) Traversal of the list
b) Check if the list is empty
c) Insert a node at the certain position (at beginning/end/any position)
d) Delete a node at the certain position (at beginning/end/any position)
e) Delete a node for the given key
f) Count the total number of nodes
g) Search for an element in the linked list
Verify & validate each function from main method.*/
#include<stdio.h>
#include<stdlib.h> //for creating nodes
struct SLL
{ 
 int data;
 struct SLL *link;
};
//creating of sll
struct SLL *create(struct SLL *head,int n)
{
  struct SLL *temp,*newnode;
  printf("Enter elements of SLL: ");
  for(int i=0;i<n;i++)
  {
    newnode=(struct SLL*)malloc(sizeof(struct SLL));
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(head==NULL)
     head=temp=newnode;
    else{
     temp->link=newnode;
     temp=newnode;
    }
  }
  return head;
}
    
//1: Traversal of sll, 11: searching element
void traversal(struct SLL *head,int ch)
{
  if(head==NULL)
    printf("linked list is empty\n");
  else
  {
    struct SLL *ptr=NULL;
    ptr=head;
    if(ch==1)
    {
    printf("Elements of SLL: ");
    while(ptr!=NULL)
    {
     printf("%d ", ptr->data);
     ptr=ptr->link;
    }
    printf("\n");
    }
    if(ch==11)
    {
      int ele,found=0;
      printf("Enter element to search:");
      scanf("%d",&ele);
      while(ptr!=NULL)
      { 
       if(ptr->data==ele)
         found=1;
       ptr=ptr->link;
      }
      if(found==0)
        printf("Element not found\n");
      else
        printf("Element found\n");
    }
  }
}
  
//2: check SLL is empty
void empty(struct SLL *head)
{
  int count=0;
  if(head==NULL)
    printf("linked list is empty\n");
  else
    printf("linked list is not empty\n");
}

//3.4.5. insert node 
struct SLL *insert(struct SLL *head,int ch)
{
  int ele;
  printf("Enter element to insert:");
  scanf("%d",&ele);
  struct SLL *temp,*ptr;
  ptr=head;
  temp=(struct SLL*)malloc(sizeof(struct SLL));
  temp->data=ele;
  temp->link=NULL;
  if(head!=NULL)
  {
  if(ch==3)  //beginning
  {
   temp->link=head;
   head=temp;
  }
  if(ch==4) //end
  { 
   while(ptr->link !=NULL) // to reach end node of list
     ptr=ptr->link;
   ptr->link=temp;
  }
  if(ch==5) //at any position
  {
   int pos;
   printf("enter position to insert element: ");
   scanf("%d",&pos);
   if(pos == 1)
   {
     temp->link=head;
     head=temp;
   }
   pos--;
   while(pos!=1)
   {
      ptr=ptr->link;
      pos--;
   }
   temp->link=ptr->link;
   ptr->link=temp;
  }
  }
  else
    head=temp;
  printf("Element inserted\n");
  return head;
}  

//6.7.8.9 deleting node 
struct SLL *delete(struct SLL *head,int ch)
{
  struct SLL *ptr,*temp;
  ptr=head;
  if(head==NULL)
    printf("List is empty\n");
  else
  {
  if(ch==6) //beginning
  {
   head=head->link;
   free(ptr);
   ptr=NULL;
  }
  if(ch==7) //end
  { 
   if(head->link==NULL)
   {
     free(head);
     head=NULL;
   }
   else
   {
    temp=head;
    while(ptr->link !=NULL) // to reach end node of list
      {
        temp=ptr;
        ptr=ptr->link;
      }
    temp->link=NULL;
    free(ptr);
    ptr=NULL;
   }
   }
  if(ch==8) //at any position
  {
    int pos;
    temp=NULL;
    printf("enter position to delete element: ");
    scanf("%d",&pos);
    if(head->link==NULL)
    {
     free(head);
     head=NULL;
    }
    else if(pos==1)
     {
      head=ptr->link;
      free(ptr);
      ptr=NULL; 
     }
    else
    {
    while(pos!=1)
    {
      temp=ptr;
      ptr=ptr->link;
      pos--;
    }
    temp->link=ptr->link;
    free(ptr);
    ptr=NULL; 
    }
    
  } 
  
  if(ch==9) //for key
  {
   int key;
   printf("enter key to delete: ");
   scanf("%d",&key);
   temp=NULL;
   
   while(ptr!=NULL && ptr->data!=key) 
      {
        temp=ptr;
        ptr=ptr->link;
      }
   
   if (ptr==NULL) 
    {
     printf("The key is not found in the list.\n");
     //return head;
    }
   else if (temp == NULL) {
      head=ptr->link;
      free(ptr);
   }
   else {
      temp->link=ptr->link;
      free(ptr);}
   
   }
  printf("Element deleted\n");
  }
  return head;
}  

//10: count of nodes
void count_of_nodes(struct SLL *head)
{
  int count=0;
  if(head==NULL)
    printf("linked list is empty\n");
  struct SLL *ptr=NULL;
  ptr=head;
  while(ptr!=NULL)
  {
    count++;
    ptr=ptr->link;
  }
  printf("The total number of nodes:%d \n",count);
}   


int main()
{
  int ch,n;
  printf("No.of element to store:");
  scanf("%d",&n);
  struct SLL *head=NULL;
  head=create(head,n);
 
  // menu driven program
 
  printf("***MENU CHOICE***\n");
  printf("1.TRAVERSAL\n");
  printf("2.EMPTY CHECKING\n");
  printf("3.INSERT THE NODE AT BEGINNING\n");
  printf("4.INSERT THE NODE AT END\n");
  printf("5.INSERT THE NODE AT A POSITION\n");
  printf("6.DELETE THE NODE AT BEGINNING\n");
  printf("7.DELETE THE NODE AT END\n");
  printf("8.DELETE THE NODE AT A POSITION\n");
  printf("9.DELETE THE NODE FOR THE KEY\n");
  printf("10.TOTAL NUMBER OF NODES\n");
  printf("11.SEARCH THE ELEMENT\n");
  printf("12.QUIT\n");
  while(1)
 {
  printf("Enter option: ");
  scanf("%d",&ch);
  //switch case
  switch(ch)
  {
    case 1:
     traversal(head,ch);
     break;
    case 2:
     empty(head);
     break;
    case 3:
     head=insert(head,ch);
     break;
    case 4:
     head=insert(head,ch);
     break;
    case 5:
     head=insert(head,ch);
     break;
    case 6:
     head=delete(head,ch);
     break;
    case 7:
     head=delete(head,ch);
     break;
    case 8:
     head=delete(head,ch);
     break;
    case 9:
     head=delete(head,ch);
     break;
    case 10:
     count_of_nodes(head);
     break;
    case 11:
     traversal(head,ch);
     break;
    case 12:
     printf("QUITING...\n");
     return 0;
    default:
     printf("invalid choice\n");
  }
 }
 
 return 0;
}

