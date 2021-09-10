#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10

typedef struct _graphNode {
    struct _graphNode *link;
    int vertex;
} graphNode;

typedef struct _graphType {
    int n; // 정점의 갯수를 확인하기 위한 int형 변수
    graphNode *adjList_H[MAX_VERTEX]; // 그래프 정점들에 대한 헤드 포인터들을 담는 배열
} graphType;

void createGraph(graphType *g)
{
    int v;
    g->n = 0;
    for (v=0; v<MAX_VERTEX; v++)
    {
        g->adjList_H[v] = NULL;
    }
}

// 정점 삽입
void insertVertex(graphType *g, int v)
{
    if (((g->n)+1) > MAX_VERTEX) 
    {
        printf("\nERROR");
        return;
    }
    g->n++;
}

void insertEdge(graphType *g, int u, int v)
{
    graphNode *node;
    if (((u >= g->n) || (v >= g->n)))
    {
        printf("\nERROR");
        printf("\n 그래프에 없는 정점입니다.");
        return;
    }
    
    node = (graphNode*)malloc(sizeof(graphNode));
    node->vertex = v;
    node->link = g->adjList_H[u];
    g->adjList_H[u] = node;
}

void print_adjList(graphType *g)
{
    int i;
    graphNode *cur;
    for (i=0; i < (g->n); i++)
    {
        printf("\n\t\t 정점 %c의 인접 리스트", i+65);
        cur = g->adjList_H[i];
        while(cur)
        {
            printf(" -> %c", cur->vertex + 65);
            cur = cur->link;
        }
    }
}

int main()
{
    int i;
    graphType *G1;
    G1 = (graphType*)malloc(sizeof(graphType));
    createGraph(G1);
    
    for (i=0; i<4; i++)
    {
        insertVertex(G1 ,i);
    }

    insertEdge(G1, 0, 3);
    insertEdge(G1, 0, 1);
    insertEdge(G1, 1, 3);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 0);
    insertEdge(G1, 2, 1);
    insertEdge(G1, 3, 2);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 0);

    printf("\b G1의 인접 리스트");
    print_adjList(G1);
    return 0;

}