#include<stdio.h>

int palinum(int n)
{
    int rn=0;
    while(n>0)
    {
        int rem = n % 10; 
        rn = (rn*10)+rem;
        n=n/10;   
    }
    return rn;

}


int main()
{
    int n,rn;

    printf("enter a value : ");
    scanf("%d",&n);

    rn=palinum(n);

    if(n==rn)
    printf("\ngiven number is palindrome");
    else
    printf("\nnumber is not palindrome");

    return 0;
}