#include <stdio.h>
#include <stdlib.h>
#define max 10
//ADJACENCY MATRIX METHOD FOR GRAPH CREATION
void createGraph(int grp[max][max], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grp[i][j] = 0;
        }
    }

    printf("\nEnter adjacencies (Y/N):\n");

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            char response;
            printf("Vertices %d & %d are Adjacent? (Y/N): ", i + 1, j + 1);
            scanf(" %c", &response);

            if (response == 'Y' || response == 'y') {
                grp[i][j] = 1;
                grp[j][i] = 1; // Undirected graph
            }
        }
    }
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ",grp[i][j]);
        }
        printf("\n");
    }
}
// LINEAR QUEUE USING ARRAY
struct queue
{
  int size;
  int f; // front end
  int r; // rear end
  int *arr;
};
int isEmpty(struct queue *q) {
    if(q->r == q->f)
     return 1;
    else
     return 0;
}
int isFull(struct queue *q) {
    if(q->r == q->size-1)
     return 1;
    else
     return 0;
}
void enqueue(struct queue *q,int value){
    if (isFull(q)) 
        printf("Queue is full. Cannot enqueue.\n");
    else {
        q->r++;
        q->arr[q->r] = value;
    }
}
int dequeue(struct queue *q){
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        value=-1;
    }
    else {
        q->f++;
        value=q->arr[q->f];
    }
    return value;
}

int main() 
{
    int n;
    int grp[max][max];
    int degree[max];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    createGraph(grp, n);
    //queue
    struct queue q;
    q.size = n+1;
    q.f = q.r = -1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    //BFS IMPLEMENTATION
    int node,i;
    int visited[n];
    for(int i=0;i<n;i++){
      visited[i]=0;
    }
    printf("Enter start vertex: ");
    scanf("%d",&i);
    printf("Breadth First Search: %d ",i);
    visited[i] = 1;
    enqueue(&q,i);
    while(!isEmpty(&q))
    {
      node = dequeue(&q);
      for(int j=0;j<max;j++)
      {
        if(grp[node][j] == 1 && visited[j] == 0)
        {
          printf("%d ",j);
          visited[j]=1;
          enqueue(&q,j);
        }
      }
    }
     printf("\n");
    return 0;
}
