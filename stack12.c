#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

int push(int value)
{
    if (top >= SIZE - 1)
    {
        printf("Stack Overflow\n");
        return 0;
    }
    top++;
    stack[top] = value;
    printf("%d\n", value);
    return 1;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = stack[top];
    top--;
    return popped;
}

int peek()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int display()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
        return 0;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return top + 1;
}

int main()
{
    int n, val;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        if (push(val) == 0)
        {
            printf("Failed to push element %d\n", val);
        }
    }

    display();
    printf("Top element: %d\n", peek());
    printf("Popped element: %d\n", pop());
    display();

    return 0;
}

