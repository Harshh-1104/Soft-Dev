#include<stdio.h>
#include<string.h>

int main()
{
    int v=0,c=0,d=0,s=0,i=0;
    char str[100];


    printf("enter a string : ");
    scanf("%s",str);

    while(str[i] != '\0')
    {

    char set=str[i];

    if (set == 'a' || set == 'e' || set == 'i' || set == 'o' || set == 'u')
    {
        v++;
    }
    else if(set >= '0' && set<='9')
    {
        d++;
    }
    else if (set >= 'a' && set <= 'z')
    {
        c++;
    }
    else
    {
        s++;
    }
        i++;
   }

   printf("\nVowels : %d ",v);
    printf("\nConsonant : %d ",c);
     printf("\nSpecial : %d ",s);
      printf("\nDigit : %d ",d);


     return 0;
}

 

