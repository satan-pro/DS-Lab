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
	//s.size = findLength(n);
	s.arr[s.size];
	printf("%d\n", s.top);
	while(n>=1)
	{
		push(&s,n%2);
		n/=2;
		printf("%d ", s.top);
	}
	show(&s);
	printf("%d", s.top);
	int res=0;
	while(s.top>=1)
	{
		res = res*10 + pop(&s);
	}
	printf("\nHello : %d", res);
	/*while(s.top>=0)
	{
		printf("%d",pop(&s));
	}*/
	return 0;
}