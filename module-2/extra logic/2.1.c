#include <stdio.h>

int main()
{
    int marks;

    
    printf("Enter the students marks : ");
    scanf("%d", &marks);

    
    if (marks > 90)
    {
        printf("\nGrade : A");
    } 
    else if (marks > 75 && marks <= 90)
    {
        printf("\nGrade : B");
    } 
    else if (marks > 50 && marks <= 75)
    {
        printf("\nGrade : C");
    } 
    else
    {
        printf("\nGrade : D");
    }

    return 0;
}
