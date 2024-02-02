#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node* next;
};
//ADDING TO AN EMPTY LIST
struct node* addToEmpty(int data)
{
  struct node* temp= malloc(sizeof(struct node));
  temp->data=data;
  temp->next=temp;
  return temp;
}
//1. TRAVERSING 
void traverse(struct node* tail)
{
  struct node* ptr;
  if(tail!=NULL)
  {
  printf("elements of list: ");
  if(tail->next!=tail)
  {  
    ptr= tail->next;
    
    do
    {
      printf("%d ",ptr->data);
      ptr=ptr->next;
    }
    while(ptr!=tail->next);
  }
  else
  {
    printf("%d ",tail->data);
  }
  printf("\n");
  }
  else
   printf("list is empty\n");
}
//2. EMPTY CHECKING
void checkEmpty(struct node* tail)
{
 if(tail==NULL)
   printf("list is empty\n");
 else
   printf("list is not empty\n");
}
//11.search for element
int search(struct node* tail,int data)
{
  int index = 0;
  struct node* temp;
  if(tail == NULL)
     return -2;
  temp = tail->next;
  do
  {
    if(temp->data==data)
         return index;
    temp = temp->next;
    index++;
  }
  while(temp!=tail->next);
  return -1; 
  
}
//3.INSERT ELEMENT AT BEGINNING
struct node* addAtBeg(struct node* tail,int data)
{
  struct node* new=malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;
  if(tail==NULL)
  {
    tail=addToEmpty(data);
    return tail;
  }
  else
  {
    new->next = tail->next;
    tail->next = new;
  }
  //printf("element inserted \n");
  return tail;
}
//4. INSERT ELEMENT AT END
struct node* addAtEnd(struct node* tail,int data)
{
  struct node* new=malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;
  if(tail==NULL)
  {
    tail=addToEmpty(data);
    return tail;
  }
  else
  {
    new->next = tail->next;
    tail->next = new;
    tail = tail->next;
  }
  //printf("element inserted \n");
  return tail;
}
//5.INSERT ELEMENT AT A POSITION
struct node* addAtPos(struct node* tail,int data,int position)
{
  struct node* new=malloc(sizeof(struct node));
  struct node* temp;
  int pos=position;
  new->data = data;
  new->next = NULL;
  if(tail==NULL)
  {
    tail=addToEmpty(data);
    return tail;
  }
  if(position==1)
  {
    tail=addAtBeg(tail,data);
    return tail;
  }
  if(position!=1)
  {
    temp=tail->next;
    while(pos>2)
    {
      temp=temp->next;
      pos--;
    }
    if(temp->next==tail->next)
    {
      tail=addAtEnd(tail,data);
      return tail;
    }
    else
    {
      new->next = temp->next;
      temp->next = new;
    }
    
  }
  printf("element inserted \n");
  return tail;
}
//6. DELETE ELEMENT AT BEGINNING
struct node* delete(struct node* tail,int data,int ch,int pos)
{
  struct node *ptr,*ptr2;
  if(tail==NULL)
  {
    printf("list is already empty\n");
    return tail;
  }
  if(tail->next == tail || tail->data==data)
  {
    free(tail);
    tail=NULL;
    printf("element deleted\n");
    return tail;
  }
  ptr=tail->next;
  if(ch==6 || pos==1)
  {
    tail->next=ptr->next;
    free(ptr);
    ptr=NULL;
  }
  if(ch==7)
  {
    while(ptr->next != tail);
    {
     ptr=ptr->next;
    }
    ptr->next=tail->next;
    free(tail);
    tail=ptr;
  }
  if(ch==8 & pos!=1)
  {
    while(pos>2)
    {
      ptr=ptr->next;
      pos--;
    }
    ptr2 = ptr->next;
    ptr->next = ptr2->next;
    if(ptr2 == tail)
      tail = ptr;
    free(ptr2);
    ptr2=NULL;
  }
  if(ch==9)
  {
    ptr2=tail->next;
    while(ptr != tail);
    {
     if(ptr->data==data)
     {
       ptr2->next=ptr->next;
       free(ptr);
       ptr=NULL;
       printf("element deleted\n");
       return tail;
     }
     else
     {
       ptr2=ptr;
       ptr=ptr->next;
     }
    }
  }
  printf("element deleted\n");
  return tail;
}
//CREATING A DOUBLE LINKED LIST
struct node* createList(struct node* tail)
{
  int n,data,i;
  printf("enter the no.of nodes: ");
  scanf("%d",&n);
  if(n==0)
    return tail;
  printf("enter data for node 1: ");
  scanf("%d",&data);
  tail=addToEmpty(data); 
  for(i=1;i<n;i++)
  {
    printf("enter data for node %d: ",i+1);
    scanf("%d",&data);
    tail=addAtEnd(tail,data); 
  }
  return tail;
}
void countnodes(struct node* tail)
{
  struct node* temp=tail->next;
  int count = 0;
  while(temp!=tail)
  {
    temp = temp->next;
    count++;
  }
  count++;
  printf("total no.of nodes: %d\n",count);
}
  


int main()
{
  int ch,data,pos,index;
  data,pos=0;
  struct node* tail=NULL;
  printf("Creating a single circular linked list\n");
  tail = createList(tail);
    
  // menu driven program
    printf("***MENU CHOICE***\n");
    printf("1: Traversal \n");
    printf("2: Empty checking\n");
    printf("3: Insert the node at beginning\n");
    printf("4: Insert the node at end\n");
    printf("5: Insert the node at a position\n");
    printf("6: Delete the node from beginning\n");
    printf("7: Delete the node from end\n");
    printf("8: Delete the node at a position\n");
    printf("9: Delete the node for the key\n");
    printf("10: Total number of nodes\n");
    printf("11: Search the element\n");
    printf("12: Quit\n");   
    
    while(1)
    {
       printf("Enter option: ");
       scanf("%d",&ch);
       //switch case
       switch(ch)
       {
        case 1:
          traverse(tail);
          break;
        case 2:
          checkEmpty(tail);
          break; 
        case 3:
          printf("enter data to insert at beg: ");
          scanf("%d",&data);
          tail=addAtBeg(tail,data);
          break;
        case 4:
          printf("enter data to insert at end: ");
          scanf("%d",&data);
          tail=addAtEnd(tail,data);
          break;
        case 5:
          printf("enter position: ");
          scanf("%d",&pos);
          printf("enter data to insert at pos: ");
          scanf("%d",&data);
          tail=addAtPos(tail,data,pos);
          break;
        case 6:
          tail=delete(tail,data,ch,pos);
          break;
        case 7:
          tail=delete(tail,data,ch,pos);
          break;
        case 8:
          printf("enter position: ");
          scanf("%d",&pos);
          tail=delete(tail,data,ch,pos);
          break;
        case 9:
          printf("enter data to delete: ");
          scanf("%d",&data);
          tail=delete(tail,data,ch,pos);
          break;
        case 10:
          countnodes(tail);
          break;
        case 11:
          printf("enter data to search: ");
          scanf("%d",&data);
          index = search(tail,data);
          if(index == -1)
             printf("element not found\n");
          else if(index == -2)
             printf("list is empty\n");
          else
             printf("element was found\n");
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



