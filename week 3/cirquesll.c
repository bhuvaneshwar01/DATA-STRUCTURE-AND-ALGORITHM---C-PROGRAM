#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    struct Node *front, *rear;
} Queue;

void enqueue(Queue *q, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
    q->rear->next = q->front;
}

void dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty");
        return;
    }

    if (q->front == q->rear)
    {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        struct Node *temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
}

void peek(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        printf("Front element of the queue is:%d", q->front->data);
    }
}

void displayQueue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct Node *temp = q->front;
    printf("\nElements in Circular Queue are: ");
    while (temp->next != q->front)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}
int main()
{
    Queue *q = (struct Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;

    int data, ch;
    char yn;
    printf("OPERATIONS:\n1.enqueue\n2.dequeue\n3.peek\n4.display\n");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);Naïve Algorithm – KMP Algorithm
        switch (ch)
        {
        case 1:
            printf("Enter data to enqueue:");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            peek(q);
            break;
        case 4:
            displayQueue(q);
            break;
        default:
            printf("Invalid Response:");
        }
        fflush(stdin);
        printf("\nDo you want to try again(y/n):");
        scanf("%c", &yn);
    } while (yn == 'y');
    return 0;
}
