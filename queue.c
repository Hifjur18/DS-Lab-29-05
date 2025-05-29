
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return 0;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
    printf("%d enqueued\n", value);
    return 1;
}

int dequeue()
{
    if (front == -1 || front >= rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front];
    front++;
    return val;
}

int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

int display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return 0;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
    return rear - front + 1;
}

int main()
{
    int n, val;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        if (enqueue(val) == 0)
        {
            printf("Failed to enqueue element %d\n", val);
        }
    }

    display();
    printf("Front element: %d\n", peek());
    printf("Dequeued element: %d\n", dequeue());
    display();

    return 0;
}
