#include "MaxSum2D.h"
#include "MaxSum1D.h"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

MaxSum2D::MaxSum2D(int lines, int rows) : lines(lines), rows(rows)
{
	maxSum = INT_MIN;
}

MaxSum2D::~MaxSum2D()
{
}

int MaxSum2D::get_MaxSum()
{
	return maxSum;
}

void MaxSum2D::calcMaxSum()
{
	MaxSum1D calcer1D(rows);
	vector<int> tempLine;

	for (int i = 0; i < lines; ++i)
	{
		tempLine.resize(0);
		tempLine.resize(rows);

		int temp = 0;

		for (int j = i; j < lines; ++j)
		{
			for (int k = 0; k < rows; ++k)
			{
				tempLine[k] = tempLine[k] + field[j][k];
			}

			temp = calcer1D.calcSum(tempLine);

			if (temp > maxSum)
			{
				maxSum = temp;
			}
		}
		calcer1D.resetLine();
	}
}

void MaxSum2D::set_field(vector<vector<int>> transverValue)
{
	field = transverValue;

#ifdef DEBUG
	//gibt matrix aus
	for (vector<int> line : field)
	{
		for (int entry : line)
		{
			cout << entry;
		}
		cout << endl;
	}
	cout << endl;
#endif
}
