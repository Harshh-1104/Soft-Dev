#include <stdio.h>

int main()
{
    int n, i,j;

    printf("Enter a number : ");
    scanf("%d", &n);

    if (n == 1)
        {
            printf("\n%d is not a prime number", n);
            return 0;
        }
        
    for (i = 2; i < n; i++)
    {
       
        if(n % i == 0)
        {
            printf("\n%d is not a prime number", n);
            
        }
        for(j=2 ; j <= n ; j++)
        {
            printf("%d",j);
        }
    }
        printf(" %d ",i);
        printf("\n%d is a prime number",n);
       

    return 0;
}
