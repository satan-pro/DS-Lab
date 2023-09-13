#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

int isFull(struct stack* s)
{
    if(s->top==s->size)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack* s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* s, int d)
{
    if(!isFull(s))
    {
        s->arr[++(s->top)]=d;
    }
}

int pop(struct stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow");
        exit(0);
    }
    else
    {
        return s->arr[(s->top)--];
    }
}

void peek(struct stack* s)
{
    printf("%d\n",s->arr[s->top]);
}

void eval(struct stack* s,char ch, int num1, int num2)
{
    int res=0;
    switch(ch)
    {
        case '+':res=num1+num2;
                break;
        case '-':res=num1-num2;
                break;
        case '*':res=num1*num2;
                break;
        case '/':res=num1/num2;
                break;
    }
    //printf("res : %d\n",res);
    push(s,res);
}

int main()
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    char exp[100];
    printf("Enter the expression : ");
    scanf("%s",exp);
    s->size = strlen(exp);
    //printf("%d\n",s->size);
    strrev(exp);
    s->top=-1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    for(int i=0; i<=s->size; i++)
    {
        char ch = exp[i];
        //printf("%c\n",ch);
        int d,num1,num2;
        switch(ch)
        {
            case '+':
            case '-':
            case '*':
            case '/': num1 = pop(s);
                      num2 = pop(s);
                      //printf("Num1 : %d\nNum2 : %d\n",num1,num2);
                      eval(s,ch,num1,num2);
                      break;
            default : if(isdigit(ch))
                      {
                        d = (int)(ch) - 48;
                        //printf("Operand : %d\n",d);
                        push(s,d);
                        //printf("Pushed\n");
                      }
        }
    }
    printf("The evaluated expression is : ");
    peek(s);
}
