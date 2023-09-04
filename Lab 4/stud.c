/*Write a C program to implement the following functions. Use pointers and
dynamic memory management functions.
i. To read one Student object where Student is a structure with name, roll
number and CGPA as the data members
ii. To display one Student object
iii. To sort an array of Student structures according to the roll number.
*/

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    int roll;
    float cgpa;
};

typedef struct student* stud;

void input(stud s)
{
    printf("Enter student name\n");
    scanf("%s", &(s->name));
    printf("Enter roll number\n");
    scanf("%d", &(s->roll));
    printf("Enter cgpa\n");
    scanf("%f", &(s->cgpa));
}

void sort(int n, struct student arr[])
{
    struct student temp;
    int index;
    for(int i=0; i<n-1; i++)
    {
        index=i;
        for(int j=i+1; j<n; j++)
        {

            if(arr[j].roll<arr[index].roll)
            {
                index=j;
            }
        }
        temp = arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
}

void display(stud s)
{
    printf("Student Name : %s\nRoll Number : %d\nCGPA : %.2f\n", s->name, s->roll, s->cgpa);
}

int main()
{
    stud s1 = (stud)malloc(sizeof(struct student));
    input(s1);
    display(s1);
    int n;
    printf("Enter the no of records you want to input\n");
    scanf("%d", &n);
    struct student arr[n];
    for(int i=0; i<n; i++)
    {
        input(&arr[i]);
    }
    sort(n,arr);
    for(int i=0; i<n; i++)
    {
        display(&arr[i]);
    }
    return 0;
}
