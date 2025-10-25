#include <stdio.h>

int main()
{
    int r;
    printf("enter how many rows u want to print : ");
    scanf("%d", &r);

    for (int n = 0; n < r; n++)
    {
        for (int s = 0; s < r - n - 1; s++)
        printf(" ");

        long long c = 1;
                             
        for (int i = 0; i <= n; i++)
        {
            printf("%lld ", c);
            c = c * (n - i) / (i + 1);      
        }
        printf("\n");
    }
    return 0;
}
