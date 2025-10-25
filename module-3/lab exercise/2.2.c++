//Write a C++ program that performs both implicit and explicit type conversions and prints the results. 

#include <iostream>
using namespace std;


int main()
{
    int a = 11;
    double b;


    //implicit----
    b = a;
    cout << "\nImplicit : b = " << b ;


    double x = 4.3;
    int y;


    //explicit-----
    y = (int)x;
    cout << "\nExplicit : y = " << y ;


    return 0;
}


