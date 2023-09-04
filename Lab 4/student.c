#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[100];
    float cgpa;
};

typedef struct student stud;

void input(stud s)
{
    printf("Enter student name\n");
    gets(s.name);
    printf("Enter roll no\n");
    scanf("%d", &s.roll);
    printf("Enter student cgpa\n");
    scanf("%f", &s.cgpa);
}

void display(stud s)
{
    printf("Student Name : %s\nRoll : %d\nCGPA : %.2f",s.name, s.roll, s.cgpa);
}

int main()
{
    int n;
    printf("Enter the no of students\n");
    scanf("%d", &n);
    stud* arr = (stud*)malloc(n*sizeof(stud));
    
}
