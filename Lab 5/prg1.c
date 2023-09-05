/*Implement a menu driven program to define a stack of characters. Include push,
pop and display functions. Also include functions for checking error conditions
such as underflow and overflow (ref. figure 1) by defining isEmpty and isFull
functions. Use these function in push, pop and display functions appropriately. Use
type defined structure to define a STACK containing a character array and an
integer top. Do not use global variables.*/

#include <stdio.h>
#include <stdlib.h>
#include "charStack.h"

int main()
{
    stack s;
    s.size=0;
    int opt, flag=1;
    char ch, val;
    printf("Enter size of the stack\n");
    scanf("%d", &s.size);
    s.arr[s.size];
    s.top=0;
    do
    {
        printf("Choose your operation\n1. Push\n2. Pop\n");
        scanf("%d",&opt);
        //scanf("%d", &opt);
        switch(opt)
        {
            case 1: printf("Enter value\n");
                    getchar();
                    val = getchar();
                    if(isFull(&s))
                    {
                        printf("Sorry stack is full\n");
                    }
                    else
                    {
                        push(&s,val);
                    }
                    show(&s);
                    break;
            
            case 2: printf("Character popped from stack : %c\n",pop(&s));
                    show(&s);
                    break;

            default : flag=0;
                      break;
        }
    } while(flag);
    show(&s);
    return 0;
}