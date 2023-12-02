#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjLists;
    bool visited[MAX_VERTICES];
} Graph;
struct Stack
{
    int items[MAX_VERTICES];
    int top;
};
void initialize(struct Stack *s)
{
    s->top = -1;
}
void push(struct Stack *stack, int item)
{
    stack->top++;
    stack->items[stack->top] = item;
}

int pop(struct Stack *stack)
{
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
struct Node *createNode(int vertex)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node *));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int start, int n)
{
    int visited[MAX_VERTICES] = {0};
    struct Stack s;
    initialize(&s);

    push(&s, start);

    while (!isEmpty(&s))
    {
        int current = pop(&s);

        if (!visited[current])
        {
            printf("Visited %d\n", current);
            visited[current] = 1;

            for (int i = 0; i < n; i++)
            {
                if (adjMatrix[current][i] == 1 && !visited[i])
                {
                    push(&s, i);
                }
            }
        }
    }
}

void dfs(Graph *graph, int vertex)
{
    Node *adjList = graph->adjLists[vertex];
    Node *temp = adjList;

    graph->visited[vertex] = true;
    printf("%d -> ", vertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == false)
        {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
int main()
{
    int numVertices, v;
    int vertices, edges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    while (1)
    {
        int c;
        printf("\n1.DFS using adjacent matrix\n2.DFS using List \n3.Exit\n ");
        printf("Enter choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the number of vertices: ");
            scanf("%d", &numVertices);

            printf("Enter the adjacency matrix:\n");
            for (int i = 0; i < numVertices; i++)
            {
                for (int j = 0; j < numVertices; j++)
                {
                    scanf("%d", &adjMatrix[i][j]);
                }
            }
            printf("enter start vertex:");
            scanf("%d", &v);

            printf("DFS traversal:\n");
            DFS(adjMatrix, v, numVertices);

            break;
        case 2:
            printf("Enter the number of vertices for list: ");
            scanf("%d", &vertices);

            Graph *graph = createGraph(vertices);

            printf("Enter the number of edges: ");
            scanf("%d", &edges);

            for (int i = 0; i < edges; i++)
            {
                int src, dest;
                printf("Enter source and destination of edge %d: ", i + 1);
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
            }
            printf("enter start vertex:");
            scanf("%d", &v);

            printf("\nDFS Traversal:\n");
            dfs(graph, v);
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
