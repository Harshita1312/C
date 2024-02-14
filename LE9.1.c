#include <stdio.h>

#define max 10

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
}

void calculateDegree(int grp[max][max], int n, int degree[max]) {
    int i, j;

    for (i = 0; i < n; i++) {
        degree[i] = 0;

        for (j = 0; j < n; j++) {
            if (grp[i][j] == 1) {
                degree[i]++;
            }
        }
    }
}

void displayDegree(int degree[max], int n) {
    printf("\nVertex  Degree\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i + 1, degree[i]);
    }
}

int main() {
    int n;
    int grp[max][max];
    int degree[max];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    createGraph(grp, n);
    calculateDegree(grp, n, degree);
    displayDegree(degree, n);

    return 0;
}
