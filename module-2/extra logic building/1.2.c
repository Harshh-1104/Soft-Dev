#include <stdio.h>
#include <math.h>

int main()
{
    int n, num, rem, p;
    double sum;

    printf("\nArmstrong numb between 1 to 1000 : ");

    for (n = 1; n <= 1000; n++)
    {
        num = n;
        p = 0;
        sum = 0.0;

      
        while (num != 0)
        {
            num /= 10;
            p++;
        }

        num = n;

        
        while (num != 0)
        {
            rem = num % 10;
            sum += pow(rem, p);
            num /= 10;
        }

        if (sum == n)
        {
            printf("%d ", n);
        }
    }

    
    return 0;
}
