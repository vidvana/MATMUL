//
// Created by julia on 4/18/24.
//
#pragma once
#import <iostream>
#include <cmath>
#include "Matrix.h"

using namespace std;



Matrix::Matrix(int x_size, int y_size, float a1, float a2, float a3) {
    this->y_size = y_size;
    this->x_size = x_size;
    this->cells = (float **)malloc(x_size * sizeof(float *));
    for (int i = 0; i < x_size; i++) {
        cells[i] = (float *)malloc(y_size * sizeof(float));
    }
    if (a1 == 0.0 && a2 == 0.0 && a3 == 0.0) {
        for (int i = 0; i < this->y_size; i++) {
            for (int j = 0; j< this->x_size; j++) {
                this->cells[j][i] = 0;
            }
        }
    } else if (a2 == 0.0 && a3 == 0.0) {
        for (int i = 0; i < this->y_size; i++) {
            for (int j = 0; j< this->x_size; j++) {
                this->cells[j][i] = 0;
                if (i == j) {
                    this->cells[j][i] = a1;
                }
            }
        }
    } else if (a3 == 0.0) {
        for (int i = 0; i < this->y_size; i++) {
            for (int j = 0; j< this->x_size; j++) {
                this->cells[j][i] = 0;
                if (i == j) {
                    this->cells[j][i] = a1;
                } else if (fabs(i - j) == 1) {
                    this->cells[j][i] = a2;
                }
            }
        }
    } else {
        for (int i = 0; i < this->y_size; i++) {
            for (int j = 0; j< this->x_size; j++) {
                this->cells[j][i] = 0;
                if (i == j) {
                    this->cells[j][i] = a1;
                } else if (fabs(i - j) == 1) {
                    this->cells[j][i] = a2;
                } else if (fabs(i - j) == 2) {
                    this->cells[j][i] = a3;
                }
            }
        }
    }

    printf("Matrix created.\n");
}

Matrix::Matrix(float n, int x_size, int y_size) {
    this->y_size = y_size;
    this->x_size = x_size;
    this->cells = (float **)malloc(x_size * sizeof(float *));
    for (int i = 0; i < x_size; i++) {
        cells[i] = (float *)malloc(y_size * sizeof(float));
    }
    for (int i = 0; i < this->y_size; i++) {
        for (int j = 0; j< this->x_size; j++) {
            this->cells[j][i] = n;
        }
    }
    printf("Matrix created.\n");
}



Matrix::~Matrix() {
    for (int i = 0; i < this->x_size; i++) {
        free(this->cells[i]);
    }
    free(cells);
    printf("Matrix destroyed.\n");
}

void Matrix::print() {
    for (int i = 0; i < this->y_size; i++) {
        for (int j = 0; j< this->x_size; j++) {
            printf("%.2f  ", this->cells[j][i]);
        }
        printf("\n");
    }
}

Matrix::Matrix(int x_size, int y_size, float (*func)(int, int), int num) {
    this->y_size = y_size;
    this->x_size = x_size;
    this->cells = (float **)malloc(x_size * sizeof(float *));
    for (int i = 0; i < x_size; i++) {
        cells[i] = (float *)malloc(y_size * sizeof(float));
    }

    //this->print();
    if (x_size == 1) {
        for (int i = 0; i < this->y_size; i++) {
            this->cells[0][i] = func(i, num);

        }
    } else if (y_size == 1) {
        for (int i = 0; i < this->x_size; i++) {
            this->cells[i][0] = func(i, num);

        }
    }
    printf("Matrix (vector to be more specific) created.\n");

}

Matrix Matrix::operator*(const Matrix& mat) {
    if (this->x_size != mat.y_size) {
        throw runtime_error("Can't multiply matrices:\nthe width of the first one does not match the height of the second.\n");
    }
    Matrix result = Matrix(mat.x_size, this->y_size);
    for (int y = 0; y < this->y_size; y++) {
        for (int x = 0; x<mat.x_size; x++) {
            float val = 0;
            for (int n = 0; n< this->x_size; n++) {
                val = val + this->cells[n][y] * mat.getCell(x, n);
            }
            result.setCell(x, y, val);
        }
    }
    return result;
}

void Matrix::setCell(int x, int y, float num) {
    this->cells[x][y] = num;
}

float Matrix::getCell(int x, int y) const {
    return this->cells[x][y];
}

int Matrix::get_x() const {
    return this->x_size;
}

int Matrix::get_y() const {
    return this->y_size;
}


Matrix Matrix::diagonal() {
    Matrix mat = Matrix(this->x_size, this->y_size);
    int max_n = min(this->x_size, this->y_size);
    for (int n = 0; n < max_n; n++) {
        mat.setCell(n, n, this->getCell(n, n));
    }
    return mat;
}

Matrix Matrix::tril() {
    return Matrix(0, 0);
}

Matrix Matrix::triu() {
    return Matrix(0, 0);
}

