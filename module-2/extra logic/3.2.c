#include<stdio.h>

int main()
{
    int n,i,r;

    printf("Enter the value that u want to multi : ");
    scanf("%d",&n);

    printf("\nEnter the range : ");
    scanf("%d",&r);


    for(i=1; i<=r ; i++)
    {
        printf("\n %d * %d = %d ", n , i , n*i);   
    }

return 0;

}