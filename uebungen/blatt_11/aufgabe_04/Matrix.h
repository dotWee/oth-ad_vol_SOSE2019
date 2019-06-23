#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
  private:
    int n, m;
    vector<vector<int> > internMatrix;
    Matrix Mult(Matrix M, int start, int stop);
    Matrix copyTo(Matrix M, int startH, int stopH, int startV, int stopV);
    Matrix merge(Matrix O11, Matrix O12, Matrix O21, Matrix O22, int start, int stop);

  public:
    int get_m();
    int get_n();
    void setValue(int m, int n, int value);
    int getValue(int m, int n);
    Matrix(int m, int n);
    void Init();
    void Print();
    void Input();
    Matrix Add(Matrix M);
    Matrix Sub(Matrix M);
    Matrix Mult(Matrix M);
    Matrix Mult_Old(Matrix M);
    void fillRND();
};

#endif /* MATRIX_H_ */
