#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	multiset<int> MS;
	multiset<int> odd;
	multiset<int> even;
	ifstream inFile("rand_numbers.txt");
	copy( istream_iterator<int>(inFile), istream_iterator<int>(), inserter( MS, MS.begin() ) );
	for_each( MS.begin(), MS.end(), [&](int i){ i % 2 == 0 ? even.insert(i) : odd.insert(i); } ) ;
	
	// Writing odd and even numbers to their respective text files
	ofstream outFile1("odd.txt");
	ofstream outFile2("even.txt");
	copy( odd.begin(), odd.end(), ostream_iterator<int>( outFile1, " " ) );
	copy( even.begin(), even.end(), ostream_iterator<int>( outFile2, " " ) ); 
	return 0;
}
