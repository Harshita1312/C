// LINEAR QUEUE USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int data;
  struct queue *next;
};

struct queue *f,*r = NULL;

int isEmpty() 
{
    if(f==NULL)
     return 1;
    else
     return 0;
}

int isFull() 
{
  struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    if(q==NULL)
     return 1;
    else
     return 0;
}

void enqueue(int value) //insert from rear
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    if (isFull()) 
        printf("Queue is full. Cannot enqueue.\n");
    else 
    {
        q->data=value;
        q->next=NULL;
        if (isEmpty()) 
          f=r=q;
        else
        {
          r->next=q;
          r=q;
        }
    }
}

int dequeue()  // delete from front
{
    int value=-1;
    struct queue *ptr=f;
    if (isEmpty())
        printf("Queue is empty. Cannot dequeue.\n");
    else 
    {
        f=f->next;
        value=ptr->data;
        free(ptr);
    }
    return value;
}

void traverse(struct queue *ptr) 
{
    if (isEmpty())
        printf("Queue is empty.\n");
    else
    {
    printf("Queue elements: ");
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
        printf("\n");
    }
}

int main() 
{
    int choice, item;
    
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Check queue is empty or not\n");
    printf("4. Check queue is full or not\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");

    while (1) 
    {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                printf("dequeuing element %d\n",dequeue());
                break;

            case 3:
                if (isEmpty()) 
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;

            case 4:
                if (isFull()) 
                    printf("Queue is full.\n");
                else 
                    printf("Queue is not full.\n");
                break;

            case 5:
                traverse(f);
                break;

            case 6:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
       }
return 0;  
}
