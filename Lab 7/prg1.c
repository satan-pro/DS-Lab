/*Implement a circular queue of Strings using structures. Include functions insertcq,
deletecq and displaycq.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QUEUE
{
    int front;
    int rear;
    int size;
    char** arr;
};

typedef struct QUEUE* queue;

int isFull(queue q)
{
    if((q->rear+1)%q->size==q->front)
    {
        return 1;
    }
    return 0;
}

int isEmpty(queue q)
{
    if(q->front == q->rear)
        return 1;
    return 0;
}

void insertcq(queue q, char* str)
{
    if(!isFull(q))
    {
        printf("Argument passed : %s\nRear : %d", str,q->rear);
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = (char*)malloc(strlen(str)*sizeof(char));
        printf("space created\n");
        q->arr[q->rear]=str;
    }
    else{
        printf("Queue is full\n");
    }
}

char* deletecq(queue q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty...Nothing to delete\n");
        return NULL;
    }
    else{
        q->front = (q->front+1)%q->size;
        return q->arr[q->front];
    }
}

void displaycq(queue q)
{
    for(int i=q->front+1; i<=q->rear; i=(i+1)%q->size)
    {
        printf("%s\n",q->arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of queue : ");
    scanf("%d",&n);
    queue q = (queue)malloc(sizeof(struct QUEUE));
    q->size=n;
    q->front=q->rear=-1;
    q->arr = (char**)malloc(n*sizeof(char*));
    int flag=1;
    char data[100];
    char* d;
    while(flag)
    {
        int ch;
        printf("Enter your choice\n1.Enqueue\n2.Dequeue\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data to enter : ");
                    scanf("%s", &data);
                    insertcq(q,data);
                    displaycq(q);
                    break;

            case 2: d = deletecq(q);
                    printf("Data deleted : %s\n",d);
                    displaycq(q);
                    break;

            default : flag=0;
        }
    }
    return 0;
}