/*Implement a queue with two stacks without transferring the elements of the second
stack back to stack one. (use stack1 as an input stack and stack2 as an output stack)*/
#include <stdio.h>
#include <stdlib.h>
#include "intStack.h"

int main()
{
    stack* s1=(stack*)malloc(sizeof(stack));
    stack* s2=(stack*)malloc(sizeof(stack));
    int n, data, ch, flag=1;
    printf("Enter size of queue\n");
    scanf("%d", &n);
    s1->size=n;
    s2->size=n;
    s1->arr[s1->size];
    s2->arr[s2->size];
    s1->top=0;
    s2->top=0;

    do{
        printf("Enter your choice\n1.Enqueue, 2.Dequeue, 3.Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter number to enqueue\n");
                    scanf("%d", &data);
                    if(!isFull(s1))
                    {
                        push(s1, data);
                        show(s1);
                    }
                    else{
                        printf("Queue is full\n");
                    }
                    break;

            case 2: if(isEmpty(s1))
                    {
                        printf("Queue is Empty\n");
                    }
                    else{
                        while(s1->top>0)
                        {
                            push(s2, pop(s1));
                        }
                    }
                    printf("Number dequeued : %d\n",pop(s2));
                    break;

            default : flag=0;


        }
    }while(flag);
    return 0;
}