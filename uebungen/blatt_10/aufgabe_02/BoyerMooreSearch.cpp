#include "BoyerMooreSearch.h"
#include <iostream>

using namespace std;

BoyerMooreSearch::BoyerMooreSearch()
{
}

BoyerMooreSearch::~BoyerMooreSearch()
{
}

int BoyerMooreSearch::search(const char *text, int textLength, const char *pattern, int patternLength)
{
	int cnt = 0;
	int lengthAlphabet = 28;
	int shiftReg[lengthAlphabet];

	for (int i = 0; i < lengthAlphabet; ++i)
	{
		shiftReg[i] = patternLength;
	}
	for (int i = 0; i < patternLength; ++i)
	{
		shiftReg[getIndex(pattern[i])] = patternLength - i - 1;
	}

	int runner = patternLength - 1;
	while (runner < textLength)
	{
		cout << text << endl;
		for (int o = 0; o < runner; ++o)
		{
			cout << " ";
		}
		cout << "_";
		cout << endl;
		if (text[runner] == pattern[patternLength - 1])
		{
			bool match = true;
			int i;
			for (i = 0; i < patternLength; ++i)
			{

				if (text[runner - i] != pattern[patternLength - 1 - i])
				{
					match = false;
				}
				if (match == true)
				{
					for (int o = 0; o < runner - patternLength + (patternLength - i); ++o)
					{
						cout << " ";
					}
					for (int o = patternLength - i - 1; o < patternLength; ++o)
					{
						cout << pattern[o];
					}
					cout << endl;
				}

				if (match == false)
				{
					runner += shiftReg[getIndex(pattern[i])];
					break;
				}
			}

			if (match == true)
			{
				++cnt;
				runner += patternLength;
			}
		}
		else
		{
			runner += shiftReg[getIndex(text[runner])];
		}
		cout << endl;
	}

	return cnt;
}

int BoyerMooreSearch::getIndex(char c)
{
	int retVal;

	if (c == ' ')
		retVal = 26;
	else if (c == '\0')
		retVal = 27;
	else
		retVal = (int)c - 65;

	return retVal;
}
