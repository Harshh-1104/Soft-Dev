//Write a C++ program that demonstrates arithmetic, relational, logical, and bitwise operators. Perform operations using each type of operator and display the results.

#include <iostream>
using namespace std;


int main()
{
    int a = 11, b = 4;


    //arithmetic
    cout << "\nArithmetic : ";
    cout << "\na + b = " << (a + b)   ;
    cout << "\na - b = " << (a - b)   ;
    cout << "\na * b = " << (a * b)   ;
    cout << "\na / b = " << (a / b)   ;
    cout << "\na % b = " << (a % b)   ;


    //relational
    cout << "\n\nRelational : " ;
    cout << "\na == b: " << (a == b)   ;
    cout << "\na != b: " << (a != b)   ;
    cout << "\na > b: " << (a > b)     ;
    cout << "\na < b: " << (a < b)     ;
    cout << "\na >= b: " << (a >= b)   ;
    cout << "\na <= b: " << (a <= b)   ;


    //logical
    bool x = true, y = false;
    cout << "\n\nLogical  : "          ;
    cout << "\nx && y: " << (x && y)   ;
    cout << "\nx || y: " << (x || y)   ;
    cout << "\n!x: " << (!x)           ;


    //bitwise
    cout << "\n\nBitwise  : "          ;
    cout << "\na & b = " << (a & b)    ;
    cout << "\na | b = " << (a | b)    ;
    cout << "\n~a = " << (~a)          ;
    cout << "\na << 1 = " << (a << 1)  ;
    cout << "\na >> 1 = " << (a >> 1)  ;


    return 0;
}
