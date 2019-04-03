#include "MaxSum1D.h"
#include <vector>
#include <climits>

using namespace std;

#define DEBUG

MaxSum1D::MaxSum1D(int length) : length(length)
{
}

MaxSum1D::~MaxSum1D()
{
}

int MaxSum1D::calcSum(vector<int> value)
{
	int max, localMax = INT_MIN, temp;

	for (int i = 0; i < length; i++)
	{
		temp = max + value[i];
		if (temp > value[i])
		{
			max = temp;
		}
		else
		{
			max = value[i];
		}

		if (localMax > max)
		{
			max = localMax;
		}
	}
	return max;
}

int MaxSum1D::get_length()
{
	return length;
}

void MaxSum1D::resetLine()
{
	for (int &a : line)
	{
		a = 0;
	}
}
