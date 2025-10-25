//Write a C++ program that accepts an array of integers, calculates the sum and average, and displays the results.

#include <iostream>
using namespace std;
 
int main()
{
	int n, sum = 0;
	float avg;
	int num[100];
 
	cout << "how many numbers : ";
	cin >> n;
 
	cout << "\nEnter numbers : ";
	for (int i = 0; i < n; i++)
	{
    	cin >> num[i];
    	sum += num[i];
	}
 
	avg = (float)sum / n;
 
	cout << "Sum = " << sum << endl;
	cout << "Average = " << avg << endl;
 
	return 0;
}
