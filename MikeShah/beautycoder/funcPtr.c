#include<stdio.h>

void fun(int x)
{

    printf("Value of x is: %d\n", x);

}

int add(int x, int y)
{
    return (x+y);
}

int sub(int x, int y)
{
    return (x-y);
}

int mult(int x, int y)
{
    return (x*y);
}

int div(int x, int y)
{
    return (x/y);
}

int (*select_opp())(int x, int y)
{
    int opp = 0;
    printf("select an opperation\n");
    printf("1) Add\n");
    printf("2) Sub\n");
    printf("3) Mult\n");
    printf("4) Div\n");

    scanf("%d", &opp);
    if(opp == 1)
    {
        return add;
    }
    else if(opp == 2)
    {
        return sub;
    }
    else if(opp == 3)
    {
        return mult;
    }
    else if(opp == 4)
    {
        return div;
    }   

    else
    {
        printf("Invalid selection\n");
        return NULL;
    }
}

int main()
{

    void (*fun_ptr)(int);
    fun_ptr = &fun;

    (*fun_ptr)(4);

/*    
    double (*add_ptr)(double, double) = &add;

    double a = 20;
    double b = 30;

    double result = add_ptr(a, b);
    printf("add result: %f\n", result);
*/


    int (*opp_array[])(int x, int y) = {add, sub, mult, div};

    int prod = opp_array[1](10, 20);

    int (*opp_ptr)(int x, int y) = select_opp();

    printf("Enter two numbers:\n");
    int a = 0;
    int b = 0;

    printf("a = ");
    scanf("%d", &a);
    printf("\n");

    printf("b = ");
    scanf("%d", &b); 
    printf("\n");

    printf("Result: %d\n", opp_ptr(a, b));

    return 0;

}

