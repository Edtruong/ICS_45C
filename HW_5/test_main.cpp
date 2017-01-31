#include "String.h"
#include <iostream>
using namespace std;

int main()
{
	String firstString("First");
	String secondString("Second");
	String thirdString(firstString);
	String fourthString("Fourth");
	String fifthString = String();

	cout << "+: " << firstString + secondString << endl;
	cout << "+=: " << (firstString += secondString) << endl;
	cout << "indexOf(char): " << firstString.indexOf('t') << endl;
	cout << "LT: " << (secondString < firstString) << endl;
	cout << "<<: " << fifthString << endl;
	cout << "==: " << (fifthString == fourthString) << endl;
	cout << "[]: " << thirdString[1] << endl;
	fifthString = thirdString;
	cout << "<<: " << fifthString << " " << thirdString << endl;;
	cout << "[]: " << fifthString[1] << endl;
	cout << "[]: " << fifthString[10] << endl;


	cout << "Enter a test string: ";
	cin >> firstString;
	cout << firstString << endl;

	cout << (firstString < secondString) << endl;
	cout << (firstString == thirdString) << endl;
	return 0;
}
