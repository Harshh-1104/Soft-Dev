#include <stdio.h>

//recursive method

int fact(int n) 
{
    if(n == 1)
    return 1;
    else
    return n * fact(n-1);
}


int main()
{
    int n;

    printf("Enter Any Number: ");
    scanf("%d", &n);

    printf("\nFactorial : %d", fact(n));

    
}

