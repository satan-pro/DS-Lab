typedef struct
{
    int size;
    int top;
    char arr[];
}stack;

int isEmpty(stack* s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}

int isFull(stack* s)
{
    if(s->top==s->size)
        return 1;
    else
        return 0;
}

void push(stack* s, char data)
{
    if(!isFull(s))
    {
        (s)->arr[(s)->top++]=data;
    }
    else{
        printf("Stack overflow\n");
        exit(0);
    }
}

char pop(stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return (s)->arr[--(s)->top];
}

void show(stack* s)
{
    //printf("%d", s->top);
    for(int i=0; i<s->top; i++)
    {
        printf("%c ",s->arr[i]);
    }
    printf("\n");
}