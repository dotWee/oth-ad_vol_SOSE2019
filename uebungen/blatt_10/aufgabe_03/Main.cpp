#include <iostream>
#include <string>
#include "NaiveSearch.h"

using namespace std;

int main() {
	string text = "ALGORITHMEN UND DATENSTRUKTUREN";
	string pattern = "DATEN";

	NaiveSearch naive;
	cout << "Naive Search:" << endl;
	int naiveCNT = naive.naivSearch(text.c_str(), text.length(), pattern.c_str(), pattern.length());
	cout << "Found " << naiveCNT << endl;

	return 0;
}
