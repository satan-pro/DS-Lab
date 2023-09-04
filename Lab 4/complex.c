#include <stdio.h>
#include <stdlib.h>

struct complex
{
    float real;
    float img;
};

typedef struct complex comp;

comp input()
{
    comp c;
    printf("Enter the real and imaginary part\n");
    scanf("%f %f", &c.real, &c.img);
    return c;
}

comp add(comp c1, comp c2)
{
    comp c3;
    c3.real = c1.real+c2.real;
    c3.img = c1.img+c2.img;
    return c3;
}

comp diff(comp c1, comp c2)
{
    comp c3;
    c3.real = c1.real-c2.real;
    c3.img = c1.img-c2.img;
    return c3;
}

comp multiply(comp c1, comp c2)
{
    comp c3;
    c3.real = c1.real*c2.real - c1.img*c2.img;
    c3.img = c1.real*c2.img + c1.img*c2.real;
    return c3;
}

void display(comp c)
{
    printf("%.2f + %.2fi\n", c.real, c.img);
}

int main()
{
    comp c1 = input();
    comp c2 = input();
    comp sum = add(c1, c2);
    comp sub = diff(c1, c2);
    comp prod = multiply(c1, c2);
    printf("The numbers are :\n");
    display(c1);
    display(c2);
    printf("Sum : ");
    display(sum);
    printf("Difference : ");
    display(sub);
    printf("Product : ");
    display(prod);
    return 0;
}

