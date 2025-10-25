#include<stdio.h>

int main()
{
    int n;

    printf("Enter a number : ");
    scanf("%d",&n);

    (n % 2 == 0)? printf("this is an even number") : printf("this is an odd number");

    (n > 0) ? printf("\n%d is positive", n) :(n < 0) ? printf("\n%d is negative", n) : printf("\n%d is zero", n);

    (n%3 == 0 && n%5 == 0) ? printf("\nthe number is a multiple of 3, 5") : printf("\nthe number is NOT a multiple of both 3, 5");

    
    return 0;

}
