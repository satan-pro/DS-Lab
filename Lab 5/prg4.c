/* Given an array arr with n elements and a number k, k<n. The task is to delete k
elements which are smaller than next element (i.e., we delete arr[i] if arr[i] <
arr[i+1]) or become smaller than next because next element is deleted. Example:
Input: arr[] = {20, 10, 25, 30, 40}, k = 2
Output: 25 30 40
Explanation: First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20
because 25 is moved next to it and it also starts following the condition. */

#include <stdio.h>
#include <stdlib.h>

int delete(int d, int size, int arr[])
{
    for(int i=d; i<size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    return size;
}

int task(int size, int n, int arr[])
{
    for(int i=1; i<=n; i++)
    {
        int j=0;
        int flag=0;
        while(j<size-1 && flag==0)
        {
            if(arr[j]<arr[j+1])
            {
                size = delete(j,size,arr);
                flag=1;
            }
            j++;
        }
    }
    return size;
}

void print(int size, int arr[])
{
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int n,k;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter array elements\n");
        scanf("%d",&arr[i]);
    } 
    
    printf("Enter k\n");
    scanf("%d", &k);
    n = task(n,k,arr);
    print(n,arr);
}