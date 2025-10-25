#include <stdio.h>

int main()
{
    int r, i, j;

    printf("Enter the range : ");
    scanf("%d", &r);

    printf("\nPrime num btwn 1 and %d are : ", r);
    for (i = 2; i <= r; i++)
    {
        for (j = 2; j < i; j++)
        {

            if (i % j == 0)
            {
                break; 
            }
        }

        if (j == i)
        { 
            printf(" %d ", i);
        }
    }

    printf("\n");
    return 0;
}
