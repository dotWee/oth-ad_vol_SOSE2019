#include <cstring>
#include <cstdlib>
#include <iostream>
#include <random>
#include <limits>
#include <sys/time.h>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
    rows = -1;
    cols = -1;
}

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
}

void Matrix::Init() {

    while (rows < 0) {
        cout << "Definiere Anzahl der Zeilen: ";
        cin >> rows;
    }

    while (cols < 0) {
        cout << "Definiere Anzahl der Spalten: ";
        cin >> cols;
    }

    values = new int*[rows];
    for (int r = 0; r < rows; ++r) {
        values[r] = new int[cols];

        for (int c = 0; c < cols; ++c) {
            values[r][c] = 0;
        }
    }
}

void Matrix::Print() {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << values[r][c];
        }

        cout << endl;
    }
}

void Matrix::Input() {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << "Gib einen Wert für die Zahl in der " << r << " Reihe und in der " << c << " Spalte ein: ";

            cin >> values[r][c];
        }
    }
}

long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

Matrix Matrix::Add(Matrix m) {
    if (cols != m.cols || rows != m.rows) {
        cout << "Fehler! Für die Matrixaddition sind zwei Matrizen gleicher Größe notwendig." << endl;
        return Matrix();
    }

    Matrix result = Matrix(rows, cols);
    result.Init();

    long timestamp = timeInMilliseconds();
    int steps = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            result.values[r][c] = values[r][c] + m.values[r][c];
            steps++;
        }
    }

    timestamp = timeInMilliseconds() - timestamp;
    printf("Berechnung dauerte %ld ms, %d Rechenschritte wurden ausgeführt\n", timestamp, steps);
    return result;
}

Matrix Matrix::Mult(Matrix m) {
    if (cols != m.rows) {
        printf("Fehler! Für die Matrixmultiplikation muss die Anzahl der Spalten des ersten Faktors (hier=%d) gleich der Anzahl der Zeilen des zweiten Faktors (hier=%d) sein!.\n", cols, m.rows);
        return Matrix();
    }

    Matrix result = Matrix(rows, m.cols);
    result.Init();

    long timestamp = timeInMilliseconds();
    int steps = 0;

    for (int r = 0; r < result.rows; ++r) {
        for (int c = 0; c < result.cols; ++c) {
            for (int k = 0; k < cols; ++k) {
                result.values[r][c] += values[r][k] * m.values[k][c];
                steps += 2; // 2 da Multiplikation + Division
            }
        }
    }

    timestamp = timeInMilliseconds() - timestamp;
    printf("Berechnung dauerte %ld ms, %d Rechenschritte wurden ausgeführt\n", timestamp, steps);
    return result;
}