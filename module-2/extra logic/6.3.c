#include<stdio.h>
#include<string.h>

int main()
{
    char str[100], largest[100], temp[100];
    int spc = 0, num = 0, maxlen = 0, j = 0;

    printf("Enter string: ");
    gets(str);

    num = strlen(str);
   

    for (int i = 0; i <= num; i++)
    {
        if (str[i] != ' ' && str[i] != '\0') 
        {
            temp[j++] = str[i];
        }
        else 
        {
            temp[j] = '\0';
            if (j > 0)
            {
                if (j > maxlen) 
                {
                    maxlen = j;
                    strcpy(largest, temp);
                }
                spc++; 
            }
            j = 0; 
        }
    }

    printf("\nthere are %d words", spc);
    printf("\nlongest string is: %s ", largest);

    return 0;
}
