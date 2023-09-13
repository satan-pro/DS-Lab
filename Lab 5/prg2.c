/*Convert a given decimal number to binary using stack.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "intStack.h"
#define MAX 10

int findLength(int n)
{
	int len=0;
	while(n>0)
	{
		len++;
		n/=10;
	}
	return len;
}
int main()
{
	stack s;
	int n;
	printf("Enter the decimal number\n");
	scanf("%d", &n);
	s.size=MAX;
	s.arr[s.size];
	s.top=0;
	while(n>0)
	{
		int r = n%2;
		printf("%d ",r);
		push(&s,r);
		n/=2;
	}
	int res=0;
	for(int i=s.top-1; i>=0; i--)
	{
		printf("%d", s.arr[i]);
	}
	printf("\n");
	/* while(s.top>=0)
	{
		int d = pop(&s);
		if(d==-1)
		{
			continue;
		}
		res = res*10+d;
	}
	printf("\nHello : %d", res); */
	while(!isEmpty(&s))
	{
		printf("%d\n",pop(&s));
	}
	return 0;
}