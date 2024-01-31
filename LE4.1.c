#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
struct node
{
  struct node* prev;
  int data;
  struct node* next;
};
//adding to empty list
struct node* addToEmpty(struct node* head,int data)
{
  struct node* temp=malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;
  head=temp;
  return head;
}
//10.COUNT TOTAL NO.OF NODES
void totalNodes(struct node* ptr)
{
 int count=0;
 if(ptr!=NULL)
  {
   while(ptr!=NULL)
   {
    count++;
    ptr=ptr->next;
   }
   printf("Total no.of nodes : %d\n",count);
  }
 else
   printf("list is empty\n");
}
//11.SEARCH DATA
int search(struct node* ptr,int data)
{
  int found=0;
  if(ptr!=NULL)
  {
   while(ptr!=NULL)
   {
    if(data==ptr->data)
      found=1;
    ptr=ptr->next;
   }
  }
  return found;
}
//12. EMPTY CHECKING
void checkEmpty(struct node* head)
{
 if(head==NULL)
   printf("list is empty\n");
 else
   printf("list is not empty\n");
}
//1. TRAVERSING FORWARD
void traverseFrd(struct node* ptr)
{
  if(ptr!=NULL)
  {
  printf("elements of list: ");
  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
  }
  else
   printf("list is empty\n");
  
}
//2.TRAVERSING BACKWARD
void traverseBwd(struct node* ptr)
{
  printf("elements of list (in reverse order) : ");
  while(ptr->next!=NULL)
    ptr=ptr->next;
  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->prev;
  }
  printf("\n");
}
//3.INSERT ELEMENT AT BEGINNING
struct node* addAtBeg(struct node* head,int data)
{
  struct node* temp=malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;
  if(head==NULL)
  {
    head=addToEmpty(head,data); 
    return head;
  }
  temp->next = head;
  head->prev = temp;
  head=temp;
  //printf("element inserted at beg\n");
  return head;
}
//4.INSERT ELEMENT AT END
struct node* addAtEnd(struct node* head,int data)
{
  struct node* temp,*tp;
  temp=malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;
  tp=head;
  if(head==NULL)
  {
    head=addToEmpty(head,data); 
    return head;
  }
  while(tp->next != NULL)
     tp=tp->next;
  tp->next=temp;
  temp->prev=tp;
  //printf("element inserted at end\n");
  return head; 
}
//5.INSERT ELEMENT AT SOME POSITION
struct node* addAtPos(struct node* head,int data,int position)
{
  struct node* newP=NULL;
  struct node* temp=head;
  struct node* temp2=NULL;
  if(head==NULL)
  {
    head=addToEmpty(head,data); 
    return head;
  }
  newP=addToEmpty(newP,data);
  int pos=position;
  while(pos>2)
  {
    temp=temp->next;
    pos--;
  }
  if(temp->next==NULL)
    head=addAtEnd(head,data);
  else if(position==1)
    head=addAtBeg(head,data);
  else
  {
  temp2=temp->next;
  temp->next=newP;
  temp2->prev=newP;
  newP->prev=temp;
  newP->next=temp2;
  }
  printf("element inserted \n");
  return head;
}
//CREATING A DOUBLE LINKED LIST
struct node* createList(struct node* head)
{
  int n,data,i;
  printf("enter the no.of nodes: ");
  scanf("%d",&n);
  if(n==0)
    return head;
  printf("enter data for node 1: ");
  scanf("%d",&data);
  head=addToEmpty(head,data); 
  for(i=1;i<n;i++)
  {
    printf("enter data for node %d: ",i+1);
    scanf("%d",&data);
    head=addAtEnd(head,data); 
  }
  return head;
}
//6.7.8.9 DELETE ELEMENT FROM BEG,END,POSITION
struct node* delete(struct node* head,int ch,int pos,int data)
{
  struct node* ptr,*temp;
  ptr=head;
  temp=head;
  if(head==NULL)
  {
    printf("list is already empty\n");
    return head;
  }
  if(head->next==NULL & ch!=9)
  {
   free(head);
   head=NULL;
   printf("element deleted\n");
   return head;
  }
  if(ch==6 || pos==1)
  {
  head=head->next;
  free(head->prev);
  }
  if(ch==7)
  {
  while(ptr->next->next!=NULL)
    ptr=ptr->next;
  free(ptr->next);
  ptr->next=NULL;
  }
  if(ch==8 & pos!=1)
  {
   temp=ptr->next->next;
   if(temp==NULL)
   {
    free(ptr->next);
    ptr->next=temp;
    printf("element deleted\n");
    return head;
   }
   while(pos>2)
   {
    ptr=ptr->next;
    temp=ptr->next->next;
    pos--;
   }
   free(ptr->next);
   ptr->next=temp;
   temp->prev=ptr;
  }
  if(ch==9)
  {
  while(ptr!=NULL)
  {
    if(ptr->prev!=NULL & data==ptr->data & ptr->next==NULL)
    {
      ptr->prev->next=NULL;
      free(ptr);
      //printf("here 1 ");
      printf("element deleted\n");
      return head;
    }
    else if(ptr->prev==NULL & data==ptr->data & ptr->next==NULL)
    {
      free(ptr);
      head=NULL;
      //printf("here 2 ");
      printf("element deleted\n");
      return head;
    }
    else if(ptr->prev==NULL & data==ptr->data & ptr->next!=NULL)
    {
      head=ptr->next;
      head->prev=NULL;
      free(ptr);
      printf("element deleted\n");
      return head;
    }
    else if(data!=ptr->data)
    {
      ptr=ptr->next;
      temp=ptr->next;
      //printf("here 3 ");
    }
    else
    {
     ptr->prev->next=temp;
     temp->prev=ptr->prev;
     free(ptr);
     //printf("here 4 ");
     printf("element deleted\n");
     return head;
    }
  }
  }
  printf("element deleted\n");
  return head;
} 


int main()
{
    struct node* head=NULL;
    struct node* ptr;
    int ch,position,data,found;
    printf("Creating a double linked list\n");
    head=createList(head);
    
    // menu driven program
    printf("***MENU CHOICE***\n");
    printf("1: Traversal forward\n");
    printf("2: Traversal backward\n");
    printf("3: Insert the node at beginning\n");
    printf("4: Insert the node at end\n");
    printf("5: Insert the node at a position\n");
    printf("6: Delete the node from beginning\n");
    printf("7: Delete the node from end\n");
    printf("8: Delete the node at a position\n");
    printf("9: Delete the node for the key\n");
    printf("10: Total number of nodes\n");
    printf("11: Search the element\n");
    printf("12: Empty checking\n");
    printf("13: Quit\n");   
    
    while(1)
    {
       printf("Enter option: ");
       scanf("%d",&ch);
       //switch case
       switch(ch)
       {
        case 1:
          ptr=head;
          traverseFrd(ptr);
          break;
        case 2:
          ptr=head;
          traverseBwd(ptr);
          break; 
        case 3:
          printf("enter data to insert at beg: ");
          scanf("%d",&data);
          head=addAtBeg(head,data); 
          break;
        case 4:
          printf("enter data to insert at end: ");
          scanf("%d",&data);
          head=addAtEnd(head,data);
          break;
        case 5:
          printf("enter position: ");
          scanf("%d",&position);
          printf("enter data to insert at pos: ");
          scanf("%d",&data);
          head=addAtPos(head,data,position);
          break;
        case 6:
          head=delete(head,ch,position,data);
          break;
        case 7:
          head=delete(head,ch,position,data);
          break;
        case 8:
          printf("enter position: ");
          scanf("%d",&position);
          head=delete(head,ch,position,data);
          break;
        case 9:
          printf("enter data to delete: ");
          scanf("%d",&data);
          head=delete(head,ch,position,data);
          break;
        case 10:
          ptr=head;
          totalNodes(ptr);
          break;
        case 11:
          printf("enter data to search: ");
          scanf("%d",&data);
          ptr=head;
          found=search(ptr,data);
          if(found==1)
            printf("%d was found in list\n",data);
          else
            printf("%d was not found in list\n",data);
          break;
        case 12:
          checkEmpty(head);
          break;
        case 13:
          printf("QUITING...\n");
          return 0;
        default:
          printf("invalid choice\n");
       }
    }
    
    return 0;
}
