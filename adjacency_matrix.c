#include <stdio.h>
#define V 4

void addEdge(int mat[V][V], int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; //directed hoile ei line dorkar nai
}

void displayMatrix(int mat[V][V]){
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[V][V] = {0};

    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    displayMatrix(mat);
    return 0;
}