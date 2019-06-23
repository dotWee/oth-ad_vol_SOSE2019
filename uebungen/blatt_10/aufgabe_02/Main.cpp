#include <iostream>
#include <string>
#include "NaiveSearch.h"
#include "BoyerMooreSearch.h"

using namespace std;

int main()
{
	string text = "ALGORITHMEN UND DATENSTRUKTUREN";
	string pattern = "DATEN";

	NaiveSearch naive;
	cout << "Naive Search:" << endl;
	int naiveCNT = naive.naivSearch(text.c_str(), text.length(), pattern.c_str(), pattern.length());
	cout << "Found " << naiveCNT << endl;

	BoyerMooreSearch boyer;
	cout << "BoyerMooer Search:" << endl;
	int boyerCNT = boyer.search(text.c_str(), text.length(), pattern.c_str(), pattern.length());
	cout << "Found " << boyerCNT << endl;

	return 0;
}
