#include<stdio.h>

int main()
{
    int num,rnum=0,sum=0;
    
    printf("Enter Any Number : ");
    scanf("%d",&num);
    
    while(num>0)
    {
        int rem = num % 10;
        sum+=rem;
        rnum = (rnum*10)+rem;
        num=num/10;   
    }
    
    printf("\nSum of given number : %d",sum);
    printf("\nReverse Number is : %d",rnum);
    
    
    
    return 0;
}