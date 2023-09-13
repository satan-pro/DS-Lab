#include <stdio.h>

typedef struct
{
    int size;
    int top;
    int arr[];
}stack;

int isEmpty(stack* s)
{
    if(s->top<0)
        return 1;
    else
        return 0;
}

int isFull(stack* s)
{
    if(s->top>=s->size)
        return 1;
    else
        return 0;
}

void push(stack* s, int data)
{
    if(isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->arr[s->top]=data;
        s->top++;
    }
}

int pop(stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    --s->top;
    return s->arr[s->top];
}

void show(stack* s)
{
    for(int i=0; i<s->top; i++)
    {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}