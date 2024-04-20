//
// Created by julia on 4/18/24.
//


#include <memory>

#ifndef MATMUL_MATRIX_H
#define MATMUL_MATRIX_H
#endif //MATMUL_MATRIX_H


class Matrix {
public:
    Matrix(int x_size, int y_size, float a1 = 0.0, float a2 = 0.0, float a3 = 0.0);
    Matrix(int x_size, int y_size, float (*func)(int, int), int num);
    Matrix operator*(const Matrix& mat);
    void setCell(int x, int y, float num);
    float getCell(int x, int y) const;
    void print();
    ~Matrix();

private:
    float ** cells;
    int y_size;
    int x_size;
};

