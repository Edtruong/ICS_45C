#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void lowerCase(string & s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void print(pair<string, int> p)
{
	cout << p.first << ":" << p.second << endl;
}

int main()
{
	map<string, int> M;
	vector<string> V;
	set<string> S; //contains the stopwords
	ifstream inFile("sample_doc.txt");
	copy( istream_iterator<string>(inFile), istream_iterator<string>(), back_inserter(V) );
	ifstream inFile2("stopwords.txt");
	copy( istream_iterator<string>(inFile2), istream_iterator<string>(), inserter( S, S.begin() ) );
	for_each( V.begin(), V.end(), lowerCase ); //change all strings to lower-case
	for_each( V.begin(), V.end(), [&](string & s){ S.count(s) == 0 ? M[s]++ : true; } );
	for_each( M.begin(), M.end(), print);

	//print map into file frequency.txt
	vector<string> V2; // holds the keys and values of map
	ofstream outFile("frequencies.txt");
	for_each( M.begin(), M.end(), [&](pair<string, int> p){ V2.push_back( p.first + " " + to_string(p.second) ); } );
	copy( V2.begin(), V2.end(), ostream_iterator<string>(outFile, "\n") );
	return 0;
}
