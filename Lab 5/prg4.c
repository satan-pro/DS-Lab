#include <stdio.h>
#include <stdlib.h>

#define MAX 5;

struct arr{
    int size;
    int arr[];
};

/* void push(struct arr* a, int d)
{
    if(a->top<(a->size-1))
    {
        a->arr[++a->top]=d;
    }
} */

void delete(int d, struct arr* a)
{
    for(int i=d; i<a->size-1; i++)
    {
        a->arr[i]=a->arr[i+1];
    }
    a->size--;
}

void task(struct arr* a, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<a->size; j++)
        {
            if(a->arr[j]<a->arr[j+1])
            {
                delete(j,a);
            }
        }
    }
}

void print(struct arr* a)
{
    for(int i=0; i<a->size; i++)
    {
        printf("%d ",a->arr[i]);
    }
}

int main()
{
    struct arr a;
    int n,k;
    printf("Enter size of array\n");
    scanf("%d", &n);
    a.size = n;
    a.arr[a.size];
    /* a.arr[a.size]={20,10,25,30,40}; */
    //a.top=-1;
    /* printf("%d",a.size);*/
    for(int i=0; i<a.size; i++)
    {
        printf("Enter array elements\n");
        scanf("%d",&n);
        a.arr[i]=n;
    } 
    
    printf("Enter k\n");
    scanf("%d", &k);
    task(&a,k);
    print(&a);
}