// Coins.h
#include <iostream>
using namespace std;

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;

class Coins
{
	public:
		Coins(int q, int d, int n, int p)
		{
			quarters = q, dimes = d, nickels = n, pennies = p;
	
		}
		void depositChange (Coins & c)
		{
			quarters += c.quarters;
			c.quarters = 0;
			dimes += c.dimes;
			c.dimes = 0;
			nickels += c.nickels;
			c.nickels = 0;
			pennies += c.pennies;
			c.pennies = 0;
		}
		bool hasSufficientAmount(int amount)
		{
			current = (quarters * CENTS_PER_QUARTER) + (dimes * CENTS_PER_DIME) + (nickels * CENTS_PER_NICKEL) + pennies;
			return current >= amount;
		}
		Coins extractChange( int amount)
		{
			if (!hasSufficientAmount(amount))
			{
				cout << "Error: amount extracted greater than stored amount" << endl;
			}
			count_q, count_d, count_n, count_p = 0;
			if (amount == 0)
			{
				Coins used(count_q, count_d, count_n, count_p);
				return used;
			}
			else if (amount >= 25 and quarters > 0)
			{
				quarters -= 1;
				count_q += 1;
				amount -= 25;
				extractChange(amount);
			}
			else if (amount >= 10 and dimes > 0) 
			{
				dimes -= 1;
				count_d += 1;
				amount -= 10;
				extractChange(amount);
			}
			else if (amount >= 5 and nickels > 0)
			{
				nickels -= 1;
				count_n += 1;
				amount -= 5;
				extractChange(amount);
			}
			else if (amount >= 1 and pennies > 0)
			{
				pennies -= 1;
				count_p += 1;
				amount -= 1;
				extractChange(amount);
			}
		}
			
		void print(ostream & out)
		{
			out << "Quarters: " << quarters << ", Dimes: " << dimes << ", Nickels: " << nickels << ", Pennies: " << pennies;
		}
	private:
		int quarters, dimes, nickels, pennies;
		int current;
		int count_q, count_d, count_n, count_p;
};

ostream & operator << (ostream & out, Coins & c)
{
	c.print(out);
	return out;
}
