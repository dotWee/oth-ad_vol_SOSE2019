#include "Matrix.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int Matrix::get_m()
{
	return m;
}

int Matrix::get_n()
{
	return n;
}

Matrix::Matrix(int m, int n) : n(n), m(m)
{
	internMatrix.resize(m);
	for (int i = 0; i < m; i++)
		internMatrix[i].resize(n);
}

void Matrix::Init()
{
	for (vector<int> &a : internMatrix)
		for (int &b : a)
			b = 0;
}

void Matrix::fillRND()
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			internMatrix[i][j] = rand() % 10;
		}
	}
}

void Matrix::Print()
{
	for (vector<int> a : internMatrix)
	{
		for (int b : a)
		{
			cout << b << " ";
		}
		cout << "\n";
	}
}

void Matrix::Input()
{
	for (vector<int> &a : internMatrix)
		for (int &b : a)
			cin >> b;
}

Matrix Matrix::Add(Matrix M)
{
	if (m != M.get_m() || n != M.get_n())
	{
		cout << "Zeilen bzw. Spaltenanzahlen passen nicht \n";
		Matrix nullM(0, 0);
		return nullM;
	}
	Matrix retVal(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			retVal.setValue(i, j, internMatrix[i][j] + M.getValue(i, j));
		}
	}
	return retVal;
}

Matrix Matrix::Sub(Matrix M)
{
	if (m != M.get_m() || n != M.get_n())
	{
		cout << "Zeilen bzw. Spaltenanzahlen passen nicht \n";
		Matrix nullM(0, 0);
		return nullM;
	}
	Matrix retVal(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			retVal.setValue(i, j, internMatrix[i][j] - M.getValue(i, j));
		}
	}
	return retVal;
}

void Matrix::setValue(int mm, int nn, int value)
{
	if ((mm >= 0 && mm < this->m) && (nn >= 0 && nn < this->n))
		internMatrix[mm][nn] = value;
}

int Matrix::getValue(int m, int n)
{
	int retVal;
	if ((m >= 0 && m < this->m) && (n >= 0 && n < this->n))
		retVal = internMatrix[m][n];
	else
		retVal = -42;
	return retVal;
}

Matrix Matrix::Mult(Matrix M)
{
	return Mult(M, 0, m);
}

Matrix Matrix::Mult(Matrix M, int start, int stop)
{
	if (stop - start == 16)
	{
		return this->Mult_Old(M);
	}

	if (stop - start == 2)
	{
		Matrix retVal(2, 2);
		retVal.setValue(0, 0, (this->getValue(0, 0)) * (M.getValue(0, 0)) + (this->getValue(0, 1)) * (M.getValue(1, 0)));
		retVal.setValue(0, 1, (this->getValue(0, 0)) * (M.getValue(0, 1)) + (this->getValue(0, 1)) * (M.getValue(1, 1)));
		retVal.setValue(1, 0, (this->getValue(1, 0)) * (M.getValue(0, 0)) + (this->getValue(1, 1)) * (M.getValue(1, 0)));
		retVal.setValue(1, 1, (this->getValue(1, 0)) * (M.getValue(0, 1)) + (this->getValue(1, 1)) * (M.getValue(1, 1)));
		return retVal;
	}

	int newLength = (stop - start) / 2;
	Matrix O11(newLength, newLength);
	Matrix O12(newLength, newLength);
	Matrix O21(newLength, newLength);
	Matrix O22(newLength, newLength);

	Matrix H1(newLength, newLength);
	Matrix H2(newLength, newLength);
	Matrix H3(newLength, newLength);
	Matrix H4(newLength, newLength);
	Matrix H5(newLength, newLength);
	Matrix H6(newLength, newLength);
	Matrix H7(newLength, newLength);

	Matrix M11(newLength, newLength);
	M11 = copyTo(*this, 0, newLength, 0, newLength);
	Matrix M12(newLength, newLength);
	M12 = copyTo(*this, newLength, stop, 0, newLength);
	Matrix M21(newLength, newLength);
	M21 = copyTo(*this, 0, newLength, newLength, stop);
	Matrix M22(newLength, newLength);
	M22 = copyTo(*this, newLength, stop, newLength, stop);

	Matrix N11(newLength, newLength);
	N11 = copyTo(M, 0, newLength, 0, newLength);
	Matrix N12(newLength, newLength);
	N12 = copyTo(M, newLength, stop, 0, newLength);
	Matrix N21(newLength, newLength);
	N21 = copyTo(M, 0, newLength, newLength, stop);
	Matrix N22(newLength, newLength);
	N22 = copyTo(M, newLength, stop, newLength, stop);

	H1 = (M11.Add(M22)).Mult((N11.Add(N22)), 0, newLength);
	H2 = (M21.Add(M22).Mult(N11, 0, newLength));
	H3 = M11.Mult((N12.Sub(N22)), 0, newLength);
	H4 = M22.Mult((N21.Sub(N11)), 0, newLength);
	H5 = (M11.Add(M12)).Mult(N22);
	H6 = (M21.Sub(M11)).Mult((N11.Add(N12)), 0, newLength);
	H7 = (M12.Sub(M22)).Mult((N21.Add(N22)), 0, newLength);

	O11 = H1.Add(H4).Sub(H5).Add(H7);
	O12 = H3.Add(H5);
	O21 = H2.Add(H4);
	O22 = H1.Sub(H2).Add(H3).Add(H6);

	return merge(O11, O12, O21, O22, 0, newLength);
}

Matrix Matrix::merge(Matrix O11, Matrix O12, Matrix O21, Matrix O22, int start, int stop)
{
	int length = stop - start;
	Matrix retVal(2 * length, 2 * length);

	for (int i = 0; i < length * 2; ++i)
	{
		for (int j = 0; j < length * 2; ++j)
		{
			if (i < length && j < length)
				retVal.setValue(i, j, O11.getValue(i, j));

			else if (i < length && j >= length)
				retVal.setValue(i, j, O12.getValue(i, j - length));

			else if (i >= length && j < length)
				retVal.setValue(i, j, O21.getValue(i - length, j));

			else if (i >= length && j >= length)
				retVal.setValue(i, j, O22.getValue(i - length, j - length));
			else
				cout << endl
					 << "Go and cry something went wrong" << endl;
		}
	}
	return retVal;
}

Matrix Matrix::copyTo(Matrix M, int startH, int stopH, int startV, int stopV)
{
	Matrix retVal(stopV - startV, stopH - startH);
	for (int i = startV; i < stopV; ++i)
	{
		for (int j = startH; j < stopH; ++j)
		{
			retVal.setValue(i - startV, j - startH, M.getValue(i, j));
		}
	}
	return retVal;
}

Matrix Matrix::Mult_Old(Matrix M)
{
	if (this->n != M.get_m())
	{
		cout << "linien-Nr. != spalten-Nr.";
		Matrix nullM(0, 0);
		return nullM;
	}
	Matrix retVal(m, M.get_n());

	for (int j = 0; j < M.get_n(); j++) // j = spaltennr2 = spaltennr_erg
	{
		for (int l = 0; l < m; l++) // l = zeilennr1 = zeilennr_erg
		{
			int value = 0;
			for (int p = 0; p < n; p++) // p = spaltennr1 bzw. zeilennr2
			{
				value += internMatrix[l][p] * M.getValue(p, j);
			}
			retVal.setValue(l, j, value);
		}
	}

	return retVal;
}
