#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct _graphType {
    int n;
    int adjMatrix[MAX_SIZE][MAX_SIZE]; // 인접행렬
} graphType;

void createGraph(graphType *g)
{
    int i, j;
    g->n = 0;
    for (i = 0; i<MAX_SIZE; i++)
    {
        for (j = 0; j<MAX_SIZE; j++)
            g->adjMatrix[i][j] = 0;
    }
}

// 정점을 삽입
void insertVertex(graphType *g, int v)
{
    if (((g->n) + 1) > MAX_SIZE)
    {
        printf("\nERROR");
        return;
    }
    g->n++;
}

void insertEdge(graphType *g, int u, int v)
{
    if (u >= g->n || v >= g->n)
    {
        printf("\nERROR");
        return;
    }
    g->adjMatrix[u][v] = 1;
}

void print_adjMatrix(graphType *g)
{
    int i, j;
    for(i=0; i<(g->n); i++)
    {
        printf("\n\t\t");
        for (j=0; j<(g->n); j++)
            printf("%2d", g->adjMatrix[i][j]);
    }
    printf("\n");
}

int main()
{
    int i;
    graphType *G1;
    G1 = (graphType*)malloc(sizeof(graphType));
    createGraph(G1);

    for (i=0; i<4; i++)
    {
        insertVertex(G1, i);
    }

    insertEdge(G1, 0, 1);
    insertEdge(G1, 0, 3);
    insertEdge(G1, 1, 0);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 3);
    insertEdge(G1, 2, 1);
    insertEdge(G1, 2, 3);
    insertEdge(G1, 3, 0);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 2);

    printf("\b G1의 인접 행렬");
    print_adjMatrix(G1);
    return 0;
}