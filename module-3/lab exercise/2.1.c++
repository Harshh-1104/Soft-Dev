//Write a C++ program that demonstrates the use of variables and constants. Create variables of different data types and perform operations on them. 

#include <iostream>
using namespace std;


int main()
{
   
    int age = 22;
    float height = 6.2;
    char grade = 'A';
   
    const double PI = 3.14;


   
    cout << "\nAge: " << age ;
    cout << "\nHeight: " << height ;
    cout << "\nGrade: " << grade ;
   


    double r = 2.5;
    double area = PI * r * r;
    cout << "\nArea : " << area;


   
    int new_a = age + 1;
    float new_h = height + 0.1;
    cout << "\nNext year age: " << new_a;
    cout << "\nIf taller by 0.1: " << new_h;


    return 0;
}
