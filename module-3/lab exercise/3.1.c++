//Write a C++ program that takes a student’s marks as input 
//  and calculates the grade based on if-else conditions. 

#include <iostream>
using namespace std;


int main()
{
    int marks;
    cout << "Enter marks : ";
    cin >> marks;


    if (marks >= 90 && marks <= 100)
    {
        cout << "\nGrade : A" ;
    }
    else if (marks >= 80 && marks < 90)
    {
        cout << "\nGrade : B" ;
    }
    else if (marks >= 70 && marks < 80)
    {
        cout << "\nGrade : C" ;
    }
    else if (marks >= 60 && marks < 70)
    {
        cout << "\nGrade : D" ;
    }
    else if (marks >= 0 && marks < 60)
    {
        cout << "\nGrade : F" ;
    }
    else
    {
        cout << "\nInvalid marks";
    }


    return 0;
}
