/*Implement two circular queues of integers in a single array where first queue will
run from 0 to N/2 and second queue will run from N/2+1 to N-1 where N is the size
of the array.*/

#include <stdio.h>
#include <stdlib.h>

struct QUEUE
{
	int start;
    int front;
    int rear;
    int size;
};
typedef struct QUEUE* queue;

struct ARRAY
{
	queue q1;
	queue q2;
	int max;
	int* arr;
};
typedef struct ARRAY* array;

int isFull(queue q)
{
    if(((q->rear+1)%q->size+q->start)==q->front)
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

void enqueue(array a, queue q, int data)
{
	if(!isFull(q))
	{
		q->rear = ((q->rear+1)%q->size)+q->start;
		a->arr[q->rear]=data;
	}
	else
	{
		printf("Queue is Full\n");
	}
}

int dequeue(array a, queue q)
{
	if(isEmpty(q))
	{
		printf("Queue is empty\n");
		exit(0);
	}
	else
	{
		q->front = (q->front+1)%q->size+q->start;
		return a->arr[q->front];
	}
}

void display(array a, queue q)
{
	for(int i = q->front+1; i<=q->rear; i++)
	{
		printf("%d ",a->arr[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	array a = (array)malloc(sizeof(struct ARRAY));
	a->max = n;
	a->arr = (int*)malloc(a->max*sizeof(int));
	a->q1 = (queue)malloc(sizeof(struct QUEUE));
	a->q1->size = a->max/2;
	a->q1->front=a->q1->rear=-1;
	a->q1->start=0;
	a->q2 = (queue)malloc(sizeof(struct QUEUE));
	a->q2->size = (a->max)-(a->max/2);
	a->q2->front=a->q2->rear = (a->max/2)-1;
	a->q2->start=5;


	int flag=1;
    int d;
    while(flag)
    {
        int ch,ch1;
        printf("1.Queue1\n2.Queue2\n");
        scanf("%d",&ch);
        printf("Enter your choice\n1.Enqueue\n2.Dequeue\n");
			        scanf("%d",&ch1);
			        switch(ch1)
			        {
			            case 1: printf("Enter data to enter : ");
			                    scanf("%d", &d);
			                    if(ch==1)
			                    {
			                    	enqueue(a,a->q1,d);
			                    	display(a,a->q1);
			                    }
			                    else if(ch==2)
			                    {
			                    	enqueue(a,a->q2,d);
			                    	display(a,a->q2);
			                    }
			                    break;

			            case 2: if(ch==1)
			            		{
			            			d = dequeue(a,a->q1);
			            			printf("Data deleted : %d\n",d);
			                    	display(a,a->q1);
			            		}
			            		else if(ch==2)
			            		{
			            			d = dequeue(a,a->q2);
			            			printf("Data deleted : %d\n",d);
			            			display(a,a->q2);
			            		}
			                    
			                    break;

			            default : flag=0;
			        }
        
    }
    return 0;
}

