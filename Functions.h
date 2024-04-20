//
// Created by julia on 4/20/24.
//
#pragma once
#include "Matrix.h"

#ifndef MATMUL_FUNCTIONS_H
#define MATMUL_FUNCTIONS_H


float norm(const Matrix v);
Matrix jacobi(const Matrix A, const Matrix b);
Matrix gauss(const Matrix A, const Matrix b);


#endif //MATMUL_FUNCTIONS_H
