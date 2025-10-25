#include <stdio.h>

int main()
{
    
    int arr[10];
    int i, j, temp,max,min;
    

    
    printf("\nEnter 10 int : ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }


    max = min = arr[0];

   
    for (i = 1; i < 10; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("\nMax num = %d ", max);
    printf("\nMini num = %d ", min);

  
    for (i = 0; i < 9; i++)        //bubble sort
    {
        for (j = i+1; j < 10 ; j++)
        {
           if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

   
    printf("\nAscending order : ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
