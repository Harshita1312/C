
#include <stdio.h>
#define max 10

typedef struct {
    int in_degree;
    int out_degree;
    int total_degree;
} VD;

//ADJACENCY MATRIX METHOD FOR GRAPH CREATION
void createGraph(int grp[max][max], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grp[i][j] = 0;
        }
    }

    printf("\nEnter adjacencies (Y/N):\n");

    printf("Enter edges (Y/N):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                char input;
                printf("Vertices %d & %d are Adjacent? (Y/N) : ", i + 1, j + 1);
                scanf(" %c", &input);

                if (input == 'Y' || input == 'y' ) {
                    grp[i][j] = 1;
               }
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

void calculateVertexDegrees(int grp[][max], int n, VD vertexDegrees[]) {
    for (int i = 0; i < n; i++) {
        vertexDegrees[i].in_degree = 0;
        vertexDegrees[i].out_degree = 0;
        vertexDegrees[i].total_degree = 0;

        for (int j = 0; j < n; j++) {
            if (grp[i][j] == 1) {
                vertexDegrees[i].out_degree++;
            }

            if (grp[j][i] == 1) {
                vertexDegrees[i].in_degree++;
            }
        }

        vertexDegrees[i].total_degree = vertexDegrees[i].in_degree + vertexDegrees[i].out_degree;
    }
}

void displayVertexDegrees(VD vertexDegrees[], int n) {
    printf("\nVertex\tIn_Degree\tOut_Degree\tTotal_Degree\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, vertexDegrees[i].in_degree, vertexDegrees[i].out_degree, vertexDegrees[i].total_degree);
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > max) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    int grp[max][max];
    createGraph(grp, n);

    VD vertexDegrees[n];
    calculateVertexDegrees(grp, n, vertexDegrees);

    displayVertexDegrees(vertexDegrees, n);

    return 0;
}

