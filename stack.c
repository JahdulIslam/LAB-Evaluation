#include <stdio.h>
#define SIZE 100

typedef struct
{
    int items[SIZE];
    int top;
} Stack;

int isFull(Stack *s)
{
    if (s->top == SIZE - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *s, int val)
{
    if (isFull(s))
    {
        printf("Stack overflow!\n");
        return;
    }

    s->top++;
    s->items[s->top] = val;
    printf("%d is pushed!\n", val);
}

void pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
        return;
    }

    int popped = s->items[s->top];
    s->top--;
    printf("%d is popped!\n", popped);
}

void peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d is on top!\n", s->items[s->top]);
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Current stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}


int main()
{
    Stack myStack;
    myStack.top = -1;
    push(&myStack, 23);
    push(&myStack, 12);
    push(&myStack, 73);
    push(&myStack, 2);
    peek(&myStack);
    display(&myStack);
    pop(&myStack);
    pop(&myStack);
    peek(&myStack);
    display(&myStack);
}