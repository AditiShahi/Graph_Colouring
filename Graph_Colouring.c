#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int n;               
int m;               
int graph[MAX][MAX];  
int color[MAX];     
char vertexNames[MAX];

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(int v) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoringUtil(v + 1))
                return true;

            color[v] = 0; 
        }
    }
    return false;
}

void graphColoring() {
    if (graphColoringUtil(0) == false) {
        printf("\nNo solution exists with %d colors.\n", m);
        return;
    }

    printf("\nColor assigned to each vertex (frequency allocation):\n");
    for (int i = 0; i < n; i++) {
        printf("%c -> Color %d\n", vertexNames[i], color[i]);
    }
}

int main() {
    printf("Enter number of vertices (cells): ");
    scanf("%d", &n);

    printf("Enter names of vertices :\n");
    for (int i = 0; i < n; i++)
        scanf(" %c", &vertexNames[i]);

    printf("\nEnter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("\nEnter number of available colors (frequency ranges): ");
    scanf("%d", &m);

    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < n; i++)
        printf("%c ", vertexNames[i]);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%c ", vertexNames[i]);
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    graphColoring();

    return 0;
}
