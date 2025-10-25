#include <stdio.h>
#include<string.h>


void palinstr(char str[],char restr[])
{
    int i,j=0;
   
    for(i = 0; str[i] != '\0'; i++);
    {
    
        while(i > 0)
        {
            i--;
            restr[j]=str[i];
            j++;
        }
        restr[j] = '\0';
    }
}

int main()
{
    char str[100],restr[100];
    
    printf("Enter a string: ");
    scanf("%s", str);

    palinstr(str,restr);

    if(strcmp(str,restr)==0)
    printf("\ngiven string is palindrome");
    else
    printf("\ngiven string is not palindrome");
    

    return 0;
}
