//Write two small programs: one using Procedural Programming (POP) to calculate the area of a rectangle, and another using Object-Oriented Programming (OOP) with a class and object for the same task.
 // Objective : Highlight the difference between POP and OOP approaches. 

// Using POP : 

#include <stdio.h>


int main()
{
    float l, w, a;


    printf("length : ");
    scanf("%f", &l);


    printf("width : ");
    scanf("%f", &w);


    a = l * w;
    printf("\nArea : %f", a);


    return 0;
}
