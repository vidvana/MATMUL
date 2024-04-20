#include <iostream>
#include <cmath>
#include "Matrix.h"

using namespace std;

float mySin(int n, int y)
{
    return sinf((float) (n * (y + 1)));
}

int main() {
    // int index = 193124;
    int f = 3;
/*

    Matrix mat1 = Matrix(5, 9);
    mat1.print();
    Matrix mat2 = Matrix(5, 9, 1);
    mat2.print();
    Matrix mat3 = Matrix(5, 9, 1, 2);
    mat3.print();
    Matrix mat4 = Matrix(5, 9, 1, 2, 3);
    mat4.print();
*/

    Matrix v1 = Matrix(1, 10, &mySin, f);
    v1.print();

    if (true) {
        Matrix m1 = Matrix(3, 2);
        m1.setCell(0,0,4);
        m1.setCell(1,0,5);
        m1.setCell(2,0,6);
        m1.setCell(0,1,4);
        m1.setCell(1,1,16);
        m1.setCell(2,1,5);
        m1.print();

        Matrix m2 = Matrix(3, 3);
        m2.setCell(0,0,1);
        m2.setCell(1,0,25);
        m2.setCell(2,0,3);
        m2.setCell(0,1,3);
        m2.setCell(1,1,2);
        m2.setCell(2,1,1);
        m2.setCell(0,2,1);
        m2.setCell(1,2,2);
        m2.setCell(2,2,3);
        m2.print();

        Matrix result = m1 * m2;
        printf("The result matrix: \n");
        result.print();
    }



    return 0;
}
