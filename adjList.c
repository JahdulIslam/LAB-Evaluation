#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph
{
    int vertices;
    struct Node** adjlist;
} Graph;

Node* createNode(int v)
{
    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));

    if (graph == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    graph->vertices = vertices;
    graph->adjlist = malloc(vertices*sizeof(Node));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjlist[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    Node* newNode = createNode(dest);
    newNode->next = graph->adjlist[src];
    graph->adjlist[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjlist[dest];
    graph->adjlist[dest] = newNode;
}


void printGraph(Graph* graph)
{
    printf("Adjacency list: \n");
    for (int i = 0; i < graph->vertices; i++)
    {
        printf("Vertex %d: ", i);
        Node* temp = graph->adjlist[i];
        while(temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    Graph* graph = createGraph(3);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    printGraph(graph);
    return 0;
}