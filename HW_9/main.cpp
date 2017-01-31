#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include "MapArray.h"
#include "SetList.h"
using namespace std;

void print_pair(pair<string, int> p)
{
	cout << p.first << " " << p.second << endl;
}

void allToLower(string & s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
}

int main()
{
	MapArray M(565);
	vector<string> V, V2;
	SetList<string> S;

	ifstream inFile1("sample_doc.txt");
	ifstream inFile2("stopwords.txt");
	ofstream outFile1("frequency.txt");
	
	// copies the stopwords from stopwords.txt to setlist S
	for_each(istream_iterator<string>(inFile2), istream_iterator<string>(), [&](string const & sw){S.insert(sw); });
	// copies words from sample_doc.txt into vector V
	copy(istream_iterator<string>(inFile1), istream_iterator<string>(), back_inserter(V));
	// changes every word in vector V to lowercase
	for_each(V.begin(), V.end(), allToLower);
	for_each(V.begin(), V.end(), [&](string & s) { if (S.find(s) == S.end()) M[s]++; });
	for_each(M.begin(), M.end(), print_pair);
	for_each(M.begin(), M.end(), [&](pair<string, int> p) { V2.push_back(p.first + " " + to_string(p.second)); });

	copy(V2.begin(), V2.end(), ostream_iterator<string>(outFile1, "\n"));
	return 0;
}
