#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue implementation for BFS
typedef struct Queue // FIFO
{
    int items[MAX_NODES];
    int front, rear;
} Queue;

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjLists;
} Graph;
Queue *createQueue();
void enqueue(Queue *q, int);
int dequeue(Queue *q);
int isEmpty(Queue *q);

// Queue functions
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue *q)
{
    return q->rear == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_NODES - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("\nQueue is empty");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
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

void bfs(Graph *graph, int startVertex)
{
    Queue *q = createQueue();
    int visited[100];
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    enqueue(q, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d -> ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
void BFS(int adjacencyMatrix[MAX_NODES][MAX_NODES], int numVertices, int startVertex)
{
    int visited[MAX_NODES];
    Queue *queue = createQueue();

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
}

int main()
{
    int numVertices, v;
    int vertices, edges;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    while (1)
    {
        int c;
        printf("\n1.BFS using adjacent matrix\n2.BFS using List \n3.Exit\n ");
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
                    scanf("%d", &adjacencyMatrix[i][j]);
                }
            }
            printf("enter start vertex:");
            scanf("%d", &v);
            printf("BFS traversal using Graph:\n");
            BFS(adjacencyMatrix, numVertices, v);

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
            printf("\nBFS Traversal using list:\n");
            bfs(graph, v);
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

