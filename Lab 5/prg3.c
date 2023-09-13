#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charStack.h"

int main()
{
    char str[100];
    printf("Enter the string : ");
    /* scanf("%s",str); */
    gets(str);
    stack s;
    s.size = strlen(str);
    char org[s.size];
    strcpy(org,str);
    printf("%d\n",s.size);
    s.top=0;
    s.arr[s.size];
    for(int i=0; i<s.size; i++)
    {
        char ch = str[i];
        push(&s,ch);
       // printf("Pushed %c\n",ch);
    }
    show(&s);
    int flag = 1;
    for(int i=s.size-1; i>=0; i--)
    {
        char ch = pop(&s);
        printf("Popped : %c Rev char : %c\n",ch,org[i]);
        if(ch!=org[i])
        {
            flag = 0;
            break;
        }
    }
    if(flag==1)
    {
        printf("Palindrome\n");
    }
    else 
    {
        printf("Not a Palindrome\n");
    }
}

