#include <iostream>
using namespace std;

double knot_to_mile (int knot){
	return (knot * 6076) / (double)5280;}

int main(){
	int knots;
	cout << "Please enter the number of knots: ";
	cin >> knots;
	cout << knot_to_mile(knots) << " knots" << endl;}
