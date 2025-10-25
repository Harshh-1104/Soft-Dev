#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int secret, guess, tries = 0;

    srand(time(NULL));         
    secret = rand() % 100 + 1; 

    printf("\nGuess the number (1-100)\n You have 5 tries");

    while (tries < 5)
    {         
        printf("Try %d: ", tries + 1);
        scanf("%d", &guess);    

        if (guess == secret)
            {
                printf("\nYou have guessed correct");
                return 0;
            }
        else if (guess < secret)
            {
                printf("\nToo low");
            }
        else
            {
                printf("\nToo high");
            }
        tries++;
    }

    printf("\nOut of tries \nNumber was %d", secret);
    return 0;
}
