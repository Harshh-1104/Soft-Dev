//Write a C++ program that asks the user to guess a number between 1 and 100. The program should provide hints if the guess is too high or too low. Use loops to allow the user multiple attempts. 

#include <iostream>
#include <cstdlib>  //for rand, srand
#include <ctime>    //for time


using namespace std;


int main()
{
    srand(time(0));  
    int secretNumber = rand() % 100 + 1;  
    int guess;


    cout << "\nGuess the num between 1 to 100 : ";


    while (true)
    {
        cout << "Enter your guess : ";
        cin >> guess;


        if (guess < secretNumber)
        {
            cout << "\nToo low ";
        }
        else if (guess > secretNumber)
        {
            cout << "\nToo high ";
        }
        else
        {
            cout << "\nCongrats you guessed it right";
            break;
        }
    }


    return 0;
}



