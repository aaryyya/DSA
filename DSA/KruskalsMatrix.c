#include <stdlib.h>
#define max 999
int i, j, a, b, min, n, ne = 0;
int parent[10];
int FindParent(int x)
{
    while (x != parent[x])
        x = parent[x];
    return x;
}
void Union(int a, int b)
{
    i = FindParent(a);
    j = FindParent(b);
    parent[j] = i;
}
void kruskals(int adjMatrix[n][n], int n)
{
    int mst = 0;
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    printf("\n\tMST: \n");

    while (ne < n - 1)
    {
        for (i = 0, min = 999; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (parent[i] != parent[j] && adjMatrix[i][j] < min)
                {
                    min = adjMatrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        Union(a, b);
        ne++;
        printf("Edge %d : %d - %d = %d \n", ne, a, b, adjMatrix[a][b]);

        adjMatrix[a][b] = adjMatrix[b][a] = 999;
        mst += min;
    }
    printf("\n %d is min dist\n", mst);
}
int main()
{

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adjMatrix[n][n];

    printf("Enter edges & weight : \n");
    for (int i = 0; i < n; i++)
    {

        adjMatrix[i][i] = 999;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf("weight of %d-%d : ", i, j);
            scanf("%d", &adjMatrix[i][j]);
            adjMatrix[j][i] = adjMatrix[i][j];
        }
    }

    printf("\nEntered matrix is : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", adjMatrix[i][j]);
        }
        printf("\n");
    }

    kruskals(adjMatrix, n);
    return 0;
}

