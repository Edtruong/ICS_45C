//HW 2 Problem 2
#include "Coins.h"
#include <iostream>
using namespace std;
const int CENTS_FOR_CHIPS = 68;


int main()
{
	Coins pocket(5, 3, 6, 8);
	Coins piggyBank(50, 50, 50, 50);
	Coins payForChips = pocket.extractChange(CENTS_FOR_CHIPS);
	cout << "After buying a bag of chips for " << CENTS_FOR_CHIPS << " cents, I have " << pocket << " left in my pocket." << endl;
	pocket.depositChange(piggyBank);
	cout << "After transferring some coins from my piggyBank, I now have " << pocket << " in my pocket" << endl;
	cout << "And now I have " << piggyBank << " left in my piggyBank" << endl;
	Coins vacuum(2, 4, 9, 2);
	piggyBank.depositChange(vacuum);
	cout << "I found some coins in my sofa while vacuuming. Now I have " << piggyBank << " in my piggyBank!" << endl;

}
