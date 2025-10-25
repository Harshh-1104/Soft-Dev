#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main() 
{
    string name;
    int rounds;

    cout << "enter ur name : ";
    cin >> name;

    cout << "how many number of rounds to play: ";
    cin >> rounds;

    srand(time(0)); 

    for (int i = 1; i <= rounds; i++) 
    {
        int computer = (rand() % 3) + 1;
        int player;

        cout << "\nRound " << i << ":\n";
        cout << "Choose 1) Rock, 2) Paper, (3) Scissor: ";
        cin >> player;

        cout << name << "'s choice: ";
        if (player == 1) cout << "\nRock";
        else if (player == 2) cout << "\nPaper";
        else if (player == 3) cout << "\nScissor";

        cout << "\nComputer's choice: ";
        if (computer == 1) cout << "\nRock";
        else if (computer == 2) cout << "\nPaper";
        else if (computer == 3) cout << "\nScissor";

        if (player == computer) 
        {
            cout << "\ntie";
        } 
        else if
        ((player == 1 && computer == 3) ||(player == 2 && computer == 1) || (player == 3 && computer == 2)) 
        {
            cout <<"\n" << name << " wins this round";
        } 
        else 
        {
            cout << "\nComputer wins this round";
        }
    }

    cout << "\nGame over " ;
    return 0;
}
