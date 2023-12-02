#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int r = -1;
int f = -1;

int isfull()
{
    if (r == max - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (r == -1 || f > r)
        return 1;
    else
        return 0;
}

int enqueue(int x)
{
    if (isfull())
        printf("Queue is full\n");
    else
    {
        if (f == -1 && r == -1)
        {
            f = 0;
            r = 0;
        }
        else
        {
            r++;
        }
        queue[r] = x;
        printf("\nEnqueue element is %d\n", x);
    }
}

int dequeue()
{
    int x;
    if (isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = queue[f];
        printf("\nDequeue element is: %d\n", x);
        f++;
    }
}

int display()
{
    int i;
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("\nDisplay elements in the queue:\n");
    for (i = f; i <= r; i++)
    {
        printf("Element at position %d is %d\n", i + 1, queue[i]);
    }
}

int main()
{
    int choice, element;

    do
    {
        printf("\nEnter 1 to enqueue, 2 to dequeue, 3 to display, and 0 to exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
