// DEQUEUE USING ARRAY

#include <stdio.h>
#include <stdlib.h>

struct DEqueue
{
  int size;
  int f; // front end
  int r; // rear end
  int *arr;
};

int isEmpty(struct DEqueue *q) 
{
    if(q->r == q->f)
     return 1;
    else
     return 0;
}

int isFull(struct DEqueue *q) 
{
    if(q->r == q->size-1)
     return 1;
    else
     return 0;
}

void enqueueR(struct DEqueue *q,int value) //insert from rear
{
    if (isFull(q)) 
        printf("Queue is full. Cannot enqueue.\n");
    else 
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

void enqueueF(struct DEqueue *q,int value) //insert from rear
{
    if (isFull(q)) 
        printf("Queue is full. Cannot enqueue.\n");
    else 
    {
        q->arr[q->f] = value;
        q->f = q->f--;
    }
}

int dequeueF(struct DEqueue *q)  // delete from front
{
    int value;
    if (isEmpty(q)) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        value=-1;
    }
    else 
    {
        q->f++;
        value=q->arr[q->f];
    }
    return value;
}

int dequeueR(struct DEqueue *q)  // delete from REAR
{
    int value;
    if (isEmpty(q)) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        value=-1;
    }
    else 
    {
        value=q->arr[q->r];
        q->r = q->r--;
    }
    return value;
}

void traverse(struct DEqueue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
    } 
    else 
    {
        printf("Queue elements: ");
        for (int i = q->f+1; i <= q->r; i++) 
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void inputRestrictedDeque() 
{
    int option,item;
    struct DEqueue q;
    
    printf("Input-restricted Deque Menu:\n");
    printf("1. Insert at rear end\n");
    printf("2. Delete from front end\n");
    printf("3. Delete from rear end\n");
    printf("4. Display\n");
    printf("5. Quit\n");

    while (1) 
    {
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                enqueueR(&q,item);
                break;

            case 2:
                printf("dequeuing element %d\n",dequeueF(&q));
                break;

            case 3:
                printf("dequeuing element %d\n",dequeueR(&q));
                break;

            case 4:
                traverse(&q);
                break;

            case 5:
                printf("Quiting..\n");
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

void outputRestrictedDeque() 
{
    struct DEqueue q;
    int option,item;
    
    printf("Output-restricted Deque Menu:\n");
    printf("1. Insert at rear end\n");
    printf("2. Insert at front end\n");
    printf("3. Delete from front end\n");
    printf("4. Display\n");
    printf("5. Quit\n");
    while (1) 
    {
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                enqueueR(&q,item);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &item);
                enqueueF(&q,item);
                break;

            case 3:
                dequeueF(&q);
                break;

            case 4:
                traverse(&q);
                break;

            case 5:
                printf("Quiting..\n");
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}


int main() 
{
    struct DEqueue q;
    q.size = 3;
    q.f = q.r = 0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    
    printf("Input-restricted Deque\n");
    inputRestrictedDeque();

    printf("Output-restricted Deque\n");
    outputRestrictedDeque();
    
return 0;  
}
