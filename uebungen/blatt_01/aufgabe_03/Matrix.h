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