// HW2 Problem 3
#include <iostream>
#include "Coins.h"
using namespace std;

int main()
{
	Coins myCoins(0, 0, 0, 0);
	cout << "Welcome to the CoinMenu!" << endl;
	cout << "------------------------" << endl;
	while (true)
	{
		int input;
		cout << "What would you like to do?\n(1) Deposit change\n(2) Extract change\n(3) Print balance\n(4) Quit\nPlease enter a number of your selection: ";
		cin >> input;
		if (input == 4)
		{
			break;
		}
		else if(input == 1)
		{
			int q, d, n, p;
			cout << "How many quarters would you like to deposit? ";
			cin >> q;
			cout << "How many dimes would you like to deposit? ";
			cin >> d;
			cout << "How many nickels would you like to deposit? ";
			cin >> n;
			cout << "How many pennies would you like to deposit? ";
			cin >> p;
			cout << "\n" << endl;
			Coins depositTemp(q, d, n, p);
			myCoins.depositChange(depositTemp);
		}
		else if(input == 2)
		{
			int q, d, n, p;
			cout << "How many quarters would you like extract? ";
			cin >> q;
			cout << "How many dimes would you like to extract? ";
			cin >> d;
			cout << "How many nickels would you like to extract? ";
			cin >> n;
			cout << "How many pennies would you like to extract? ";
			cin >> p;
			cout << "\n" << endl;
			myCoins.extractChange((q*25) + (d*10) + (n*5) + (p));
		}
		else if(input == 3)
		{
			cout << "This is your current balance: " << myCoins << "\n" <<  endl;
		}
		else
		{
			cout << "Please enter a number (1-4).\n" << endl;
		}

	}
}
