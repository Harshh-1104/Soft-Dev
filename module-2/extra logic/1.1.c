#include<stdio.h>

int main()
{
    float n1,n2;
    int select;
    int a,b;
   
    printf("Enter first number : ");
    scanf("%f",&n1);
    printf("\nEnter second number : ");
    scanf("%f",&n2);

    a=n1;
    b=n2;

    printf("\nEnter what u want to do : ");
    printf("\nPress '1' for addition(+)");
    printf("\nPress '2' for sub(-)");
    printf("\nPress '3' for multi(*)");
    printf("\nPress '4' for division(/)");
    printf("\nPress '5' for modules(%%)\n");
    scanf("%d",&select);


    switch (select)
    {
        case 1 :
        printf("\n %f + %f = %.2f ", n1 , n2, n1+n2);
        break;

        case 2 :
        printf("\n %f - %f = %.2f ", n1 , n2, n1-n2);
        break;

        case 3 :
        printf("\n %f * %f = %.2f ", n1 , n2, n1*n2);
        break;

        case 4 :
        printf("\n %f / %f = %.2f ", n1 , n2, n1/n2);
        break;

        case 5 :
        printf("\n %d %% %d = %d ", a , b, a % b );
        break;


        default:
        printf("\nInvalid operator. Please select number from menu");

    }
    
return 0;
}