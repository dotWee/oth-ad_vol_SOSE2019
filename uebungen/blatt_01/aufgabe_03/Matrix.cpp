#include <cstring>
#include <cstdlib>
#include <iostream>
#include <random>
#include <limits>
#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
    rows = -1;
    cols = -1;
}

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
}

void Matrix::Init()
{

    while (rows < 0)
    {
        cout << "Definiere Anzahl der Zeilen: ";
        cin >> rows;
    }

    while (cols < 0)
    {
        cout << "Definiere Anzahl der Spalten: ";
        cin >> cols;
    }

    values = new int *[rows];
    for (int r = 0; r < rows; ++r)
    {
        values[r] = new int[cols];

        for (int c = 0; c < cols; ++c)
        {
            values[r][c] = 0;
        }
    }
}

void Matrix::Print()
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            cout << values[r][c];
        }

        cout << endl;
    }
}

void Matrix::Input()
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            cout << "Gib einen Wert für die Zahl in der " << r << " Reihe und in der " << c << " Spalte ein: ";

            cin >> values[r][c];
        }
    }
}

Matrix Matrix::Add(Matrix m)
{
    if (cols != m.cols || rows != m.rows)
    {
        cout << "Fehler! Für die Matrixaddition sind zwei Matrizen gleicher Größe notwendig.";
        return Matrix();
    }

    Matrix result = Matrix(rows, cols);
    result.Init();

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            result.values[r][c] = values[r][c] + m.values[r][c];
        }
    }

    return result;
}

Matrix Matrix::Mult(Matrix m)
{
    if (cols != m.rows)
    {
        printf("Fehler! Für die Matrixmultiplikation muss die Anzahl der Spalten des ersten Faktors (hier=%d) gleich der Anzahl der Zeilen des zweiten Faktors (hier=%d) sein!.", cols, m.rows);
        return Matrix();
    }

    Matrix result = Matrix(rows, m.cols);
    result.Init();

    for (int r = 0; r < result.rows; ++r)
    {
        for (int c = 0; c < result.cols; ++c)
        {
            for (int k = 0; k < cols; ++k)
            {
                result.values[r][c] += values[r][k] * m.values[k][c];
            }
        }
    }

    return result;
}