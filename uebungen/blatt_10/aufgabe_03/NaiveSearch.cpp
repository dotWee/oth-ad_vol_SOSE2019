#include "NaiveSearch.h"
#include <iostream>

using namespace std;

NaiveSearch::NaiveSearch()
{
}

NaiveSearch::~NaiveSearch()
{
}

int NaiveSearch::naivSearch(const char *text, int textLength, const char *pattern, int patternLength)
{
	int cnt = 0;

	for (int i = 0; i < textLength - patternLength; ++i)
	{
		cout << text << endl;
		for (int o = 0; o < i; ++o)
		{
			cout << "_";
		}

		if (text[i] == pattern[0])
		{
			bool match = true;
			for (int j = 0; j < patternLength; ++j)
			{
				if (pattern[j] != text[i + j])
				{
					match = false;
					i += j;
					break;
				}
				cout << pattern[j];
			}
			if (match == true)
			{
				++cnt;
			}
		}
		cout << endl
			 << endl;
	}
	return cnt;
}
