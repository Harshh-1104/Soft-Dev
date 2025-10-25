#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];     
    int sum = 0;
    float avg;

    printf("Enter how many values u want to store : ");
    scanf("%d", &n);

    printf("Enter values : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i]; 
    }

    printf("\nSum of given num = %d ", sum);

    avg = sum / n;
    printf("\nAvg of given array : %f ",avg);

    return 0;
}
