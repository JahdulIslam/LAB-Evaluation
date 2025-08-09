#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    return rear == MAX - 1;
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

void enqueue(int val)
{
    if (isFull())
    {
        printf("Queue overflow!\n");
        return;
    }

    if (isEmpty())
    {
        front = 0;
    }

    rear++;
    queue[rear] = val;
    printf("%d is enqueued\n", val);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("%d is dequeued\n", queue[front]);
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(19);
    enqueue(327);
    enqueue(7);
    enqueue(190);
    enqueue(302);

    display();

    dequeue();
    dequeue(); 
       
    display();
    return 0;
}