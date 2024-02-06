// LINEAR QUEUE USING ARRAY

#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int size;
  int f; // front end
  int r; // rear end
  int *arr;
};

int isEmpty(struct queue *q) 
{
    if(q->r == q->f)
     return 1;
    else
     return 0;
}

int isFull(struct queue *q) 
{
    if(q->r == q->size-1)
     return 1;
    else
     return 0;
}

void enqueue(struct queue *q,int value) //insert from rear
{
    if (isFull(q)) 
        printf("Queue is full. Cannot enqueue.\n");
    else 
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct queue *q)  // delete from front
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

void traverse(struct queue *q) 
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

int main() 
{
    struct queue q;
    q.size = 2;
    q.f = q.r = -1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    
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
                enqueue(&q,item);
                break;

            case 2:
                printf("dequeuing element %d\n",dequeue(&q));
                break;

            case 3:
                if (isEmpty(&q)) 
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;

            case 4:
                if (isFull(&q)) 
                    printf("Queue is full.\n");
                else 
                    printf("Queue is not full.\n");
                break;

            case 5:
                traverse(&q);
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

