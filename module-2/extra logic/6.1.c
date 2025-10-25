#include <stdio.h>


void rev(char str[])
{
    int i;
   
    for(i = 0; str[i] != '\0'; i++);
    {
        while(i > 0)
        {
            i--;
            printf("%c", str[i]);
        }
    }
}

int main()
{
    char str[100];
    
    printf("Enter string: ");
    scanf("%s", str);

    printf("\nreversed string:");
    rev(str);
    

    return 0;
}
