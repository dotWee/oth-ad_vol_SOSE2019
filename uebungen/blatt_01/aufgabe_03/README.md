# Aufgabe 3 (Abstrakter Datentyp)

Datei `Matrix.h`:

```cpp
#ifndef AD_VOL_SOSE2019_MATRIX_H
#define AD_VOL_SOSE2019_MATRIX_H

class Matrix {
public:
    Matrix();
    Matrix(int rows, int cols);

    void Init();
    void Print();

    void Input();
    
    Matrix Add(Matrix m);
    Matrix Mult(Matrix m);
    
    int rows;
    int cols;
    int** values;
};

#endif //AD_VOL_SOSE2019_MATRIX_H
```

Datei `Matrix.cpp`:

```cpp
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
```

Datei `Main.cpp`:

```cpp
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Matrix.h"

using namespace std;

int main(int argc, char *argv[])
{

    cout << "Matrix A" << endl;
    Matrix matrixA;
    matrixA.Init();
    matrixA.Input();
    matrixA.Print();

    cout << "Matrix B" << endl;
    Matrix matrixB;
    matrixB.Init();
    matrixB.Input();
    matrixB.Print();

    cout << "Führe Addition (A + A) durch" << endl;
    matrixA.Add(matrixA).Print();

    cout << "Führe Addition (A + B) durch" << endl;
    matrixA.Add(matrixB).Print();

    cout << "Führe Addition (B + B) durch" << endl;
    matrixB.Add(matrixB).Print();

    cout << "Führe Multiplikation (A * A) durch" << endl;
    matrixA.Mult(matrixA).Print();

    cout << "Führe Multiplikation (A * B) durch" << endl;
    matrixA.Mult(matrixB).Print();

    cout << "Führe Multiplikation (B * B) durch" << endl;
    matrixB.Mult(matrixB).Print();

    return 0;
}
```

Datei `Makefile`:

```makefile
```

Beispielausgabe:

```bash
$ make
clang++ -c Main.cpp
clang++ -c Matrix.cpp
clang++ Main.o Matrix.o -o Cmain
chmod +x Cmain
./Cmain
Matrix A
Definiere Anzahl der Zeilen: 2
Definiere Anzahl der Spalten: 2
Gib einen Wert für die Zahl in der 0 Reihe und in der 0 Spalte ein: 1
Gib einen Wert für die Zahl in der 0 Reihe und in der 1 Spalte ein: 2
Gib einen Wert für die Zahl in der 1 Reihe und in der 0 Spalte ein: 3
Gib einen Wert für die Zahl in der 1 Reihe und in der 1 Spalte ein: 4
12
34
Matrix B
Definiere Anzahl der Zeilen: 2
Definiere Anzahl der Spalten: 3
Gib einen Wert für die Zahl in der 0 Reihe und in der 0 Spalte ein: 1
Gib einen Wert für die Zahl in der 0 Reihe und in der 1 Spalte ein: 2
Gib einen Wert für die Zahl in der 0 Reihe und in der 2 Spalte ein: 3
Gib einen Wert für die Zahl in der 1 Reihe und in der 0 Spalte ein: 4
Gib einen Wert für die Zahl in der 1 Reihe und in der 1 Spalte ein: 5
Gib einen Wert für die Zahl in der 1 Reihe und in der 2 Spalte ein: 6
123
456
Führe Addition (A + A) durch
24
68
Führe Addition (A + B) durch
Fehler! Für die Matrixaddition sind zwei Matrizen gleicher Größe notwendig.Führe Addition (B + B) durch
246
81012
Führe Multiplikation (A * A) durch
710
1522
Führe Multiplikation (A * B) durch
91215
192633
Führe Multiplikation (B * B) durch
Fehler! Für die Matrixmultiplikation muss die Anzahl der Spalten des ersten Faktors (hier=3) gleichder Anzahl der Zeilen des zweiten Faktors (hier=2) sein!
```