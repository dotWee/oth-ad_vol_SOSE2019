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