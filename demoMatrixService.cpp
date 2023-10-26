// demoMatrixService.cpp

#include "MatrixService.h"

#include <iostream>
using namespace std;

/**
 * Initialization of the MatrixService.
*/
MatrixService* MS = MatrixService::GetInstance(); 

/**
 * Reads user input for values of m & n of matrix, as well as entries for coresponding size matrix.
 * Method is going to proceed only first m*n user entries, remaining entries will be ignored. 
 * Since methood listens for specific quantity of input entries, it will continue to run untill recives all of them.
 * In such way you can fill up 2 x 3 matrix in those ways:
 * Way 1:           Way 2:      Way 3:
 * 1 2 3 4 5 6      1 2 3       1
 *                  4 5 6       2 3 4
 *                              5 6
 * 
 * All of the options will yield the same matrix:
 * | 1 2 3 |
 * | 4 5 6 |
 * 
*/
MatrixStruct getUserInputMatrix() {
    unsigned short m;
    unsigned short n;
    cout << "Type in dimensions of matrix (m x n) separated by space:\n";
    cin >> m >> n;
    if (m > MAT_MAX_SIZE || n > MAT_MAX_SIZE) {
        throw std::invalid_argument("getUserInputMatrix: Out of bounds of maximum matrix dimensions!\n");
    }
    cout << endl << "Type in the entries of matrix: \n";
    double temparr[m*n];
    for(int i = 0; i < (m*n); i++)
    {
        cin >> temparr[i];
    }
    cout << endl;
    return MS->createMatrixFromArray(temparr, m, n);
}

/**
 * Main methood.
 * Requests user input for matrix parameters and entries.
 * After what prints our inputed matrix, inputed matrix transpose and product of inputed matrix and it's transpose.
*/
int main(int argc, char* argv[])
{
    MatrixStruct test1 = getUserInputMatrix();
    MatrixStruct test2 = MS->getTranspose(test1);
    cout << "Input:\n";
    MS->printMatrix(test1);
    cout << "Transpose:\n";
    MS->printMatrix(test2);
    cout << "Original X Transpose:\n";
    MS->printMatrix(MS->getMatrixMaT(test1));

    return 0;
}