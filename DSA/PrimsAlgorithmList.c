#include <stdio.h>
#include <stdlib.h>
#define MAX 999
struct node
{
    int weight, vertex;
    struct node *next;
};
int findMin(struct node *A[], int dist[], int visited[], int n)
{
    int min = MAX, u;
    struct node *p;
    for (int i = 0; i < n - 1; i++)
    {
        p = A[i];
        while (p->next != NULL)
        {
            if (dist[p->vertex] < min && visited[p->vertex] == 0)
            {
                min = dist[p->vertex];
                u = p->vertex;
            }
            p = p->next;
        }
    }
    return u;
}
void prims(struct node *A[], int n)
{
    int visited[10], parent[10], dist[10], u;
    struct node *p;
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        dist[i] = MAX;
        visited[i] = 0;
    }
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        u = findMin(A, dist, visited, n);
        p = A[u];
        visited[u] = 1;
        while (p != NULL)
        {
            if (p->weight < dist[p->vertex] && visited[p->vertex] == 0)
            {
                dist[p->vertex] = p->weight;
                parent[p->vertex] = u;
            }
            p = p->next;
        }
    }
    printf("Edge & weight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d %d\n", parent[i], i, dist[i]);
    }
}
// void AdjList(struct node *A[], int n)
// {
//     int v1, v2, w, ope;
//     struct node *p, *new;
//     while (1)
//     {
void AdjList(struct node *A[], int n)
{
    int v1, v2, w, ope;
    struct node *p, *new;
    while (1)
    {
        printf("1.Enter edges\n2.find mst\n");
        scanf("%d", &ope);
        switch (ope)
        {
        case 1:
            printf("Enter edges and weight: ");
            scanf("%d %d %d", &v1, &v2, &w);
            new = (struct node *)malloc(sizeof(struct node));
            new->vertex = v2;
            new->weight = w;
            new->next = NULL;
            p = A[v1];
            if (p == NULL)
                A[v1] = new;
            else
            {
                while (p->next != NULL)
                    p = p->next;
                p->next = new;
            }
            new = (struct node *)malloc(sizeof(struct node));
            new->vertex = v1;
            new->weight = w;
            new->next = NULL;
            p = A[v2];
            if (p == NULL)
                A[v2] = new;
            else
            {
                while (p->next != NULL)
                    p = p->next;
                p->next = new;
            }
            break;
        case 2:
            prims(A, n);
            break;
        }
    }
}
//     }
// }
int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    struct node *A[10];
    for (int i = 0; i < n; i++)
    {
        A[i] = NULL;
    }
    AdjList(A, n);
    return 0;
}
