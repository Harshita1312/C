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
//DFS IMPLEMENTATION OF GRAPH
void DFS(int i, int n, int grp[max][max], int visited[max])
{
  int j;
  printf("%d ",i);
  visited[i] = 1;
  for(int j=0;j<max;j++)
  {
        if(grp[i][j] == 1 && !visited[j])
        {
           DFS(j, n, grp, visited);
        }
      }
}

int main() 
{
    int n;
    int grp[max][max];
    int degree[max];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    createGraph(grp, n);
    
    //DFS IMPLEMENTATION
    int node,i;
    int visited[n];
    for(int i=0;i<n;i++){
      visited[i]=0;
    }
    printf("Enter start vertex: ");
    scanf("%d",&i);
    printf("Depth First Search:");
    DFS(i,n,grp,visited);
    
     printf("\n");
    return 0;
}
