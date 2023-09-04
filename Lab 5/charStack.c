/*Implement a menu driven program to define a stack of characters. Include push,
pop and display functions. Also include functions for checking error conditions
such as underflow and overflow (ref. figure 1) by defining isEmpty and isFull
functions. Use these function in push, pop and display functions appropriately. Use
type defined structure to define a STACK containing a character array and an
integer top. Do not use global variables.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stack
{
    int size;
    int top;
    char* arr;
};
typedef struct stack* stackptr;

int isEmpty(stackptr s)
{
    if(s->top<s->size)
        return 1;
    else
        return 0;
}

int isFull(stackptr s)
{
    if(s->top>=s->size)
        return 1;
    else
        return 0;
}

void push(stackptr* s, int data)
{
    if(isEmpty(*s))
    {
        (*s)->arr[(*s)->top++]=data;
    }
}

int pop(stackptr *s)
{
    if(isEmpty(*s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return (*s)->arr[--(*s)->top];
}

void show(stackptr s)
{
    for(int i=s->top; i<s->size; i++)
    {
        printf("%c ",s->arr[i]);
    }
    printf("\n");
}

int main()
{
    stackptr s;
    int opt;
    char ch, val;
    printf("Enter size of the stack\n");
    scanf("%d", &s->size);
    s->arr = (char*)calloc(s->size,sizeof(char));
    s->top=0;
    do
    {
        printf("Choose your operation\n1. Push\n2. Pop\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter value\n");
                    scanf("%c", &val);
                    if(isFull(s))
                    {
                        printf("Sorry stack is full\n");
                    }
                    else
                    {
                        push(&s,val);
                    }
                    show(s);
                    break;
            
            case 2: printf("Character popped from stack : %c\n",pop(&s));
                    show(s);
                    break;
        }
        printf("Do you want to continue? (y/n)\n");
        ch = getch();
    } while(ch=='y');
    show(s);
}
