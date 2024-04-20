//
// Created by julia on 4/20/24.
//
#pragma once
#include "Functions.h"
#include <cmath>




float norm(const Matrix v) {
    float norm = 0.0;
    for (int i = 0; i < v.get_x(); i++) {
        for (int j = 0; j < v.get_y(); j++) {
            norm += powf(v.getCell(i, j), 2);
        }
    }
    return sqrtf(norm);
}

Matrix jacobi(const Matrix A, const Matrix b) {
    Matrix D = A.diagonal();
    Matrix L = A.tril();
    Matrix U = A.triu();
    Matrix x = Matrix(1.0, A.get_x(), 1);
    Matrix result = Matrix(1, 1);
    return result;
}

Matrix gauss(const Matrix A, const Matrix b) {
    Matrix result = Matrix(1, 1);
    return result;
}