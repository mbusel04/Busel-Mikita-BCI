// testMatrixService.ccp

#include "MatrixService.h"
#include <iostream>

#define IS_TRUE(x) { if (!(x)) std::cout << "FAILURE: " <<__FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

MatrixService* MS = MatrixService::GetInstance(); 

/**
 * @test
 * Test if created matrix has proper size of m x n.
*/
void testArrayAssignment() {
    double input1[] = {0,0,0,0,0,0};
    unsigned short m1 = 2;
    unsigned short n1 = 3;
    MatrixStruct output1 = MS->createEmptyMatrix(2,3);
    IS_TRUE(output1 == MS->createMatrixFromArray(input1, m1, n1));
}

/**
 * @test
 * Checks if transpose method works correctly.
 * Case 1 - Transpose of empty equals to empty.
 * Case 2:
 * Input:           Expected:
 * | 1 2 3 4 5 |    | 1 |
 *                  | 2 |
 *                  | 3 |
 *                  | 4 |
 *                  | 5 |
 *
*/
void testTranspose() {
    double inputArr1[] = {};
    MatrixStruct input1 = MS->createMatrixFromArray(inputArr1, 0, 0);
    double outputArr1[] = {};
    MatrixStruct output1 = MS->createMatrixFromArray(outputArr1, 0, 0);
    IS_TRUE(output1 == MS->getTranspose(input1));

    double inputArr2[] = {1,2,3,4,5};
    MatrixStruct input2 = MS->createMatrixFromArray(inputArr2, 1, 5);
    double outputArr2[] = {1,2,3,4,5};
    MatrixStruct output2 = MS->createMatrixFromArray(outputArr2, 5, 1);
    IS_TRUE(output2 == MS->getTranspose(input2));
}

/**
 * @test
 * Checks for work of matrix multiplication method.
 * Case 1 - Multiply empty by empty should reuslt empty.
 * Case 2:
 * Input1:      Input2:     Expect:
 * | -2 0 3 |   | -1 -1 |   | 11 11 |
 * |  0 1 7 |   |  2  2 |   | 23 23 |
 *              |  3  3 |
 * 
*/
void testMultiplication() {
    double inputArr1[] = {};
    MatrixStruct input1 = MS->createMatrixFromArray(inputArr1, 0, 0);
    double inputArr2[] = {};
    MatrixStruct input2 = MS->createMatrixFromArray(inputArr2, 0, 0);
    double outputArr1[] = {};
    MatrixStruct output1 = MS->createMatrixFromArray(outputArr1, 0, 0);
    IS_TRUE(output1 == MS->multiplyMatrices(input1, input2));

    double inputArr3[] = {-2,0,3,0,1,7};
    MatrixStruct input3 = MS->createMatrixFromArray(inputArr3, 2, 3);
    double inputArr4[] = {-1,-1,2,2,3,3};
    MatrixStruct input4 = MS->createMatrixFromArray(inputArr4, 3, 2);
    double outputArr2[] = {11,11,23,23};
    MatrixStruct output2 = MS->createMatrixFromArray(outputArr2, 2, 2);
    IS_TRUE(output2 == MS->multiplyMatrices(input3,input4));
}

void testMaT() {
    double inputArr1[] = {};
    MatrixStruct input1 = MS->createMatrixFromArray(inputArr1, 0, 0);
    double outputArr1[] = {};
    MatrixStruct output1 = MS->createMatrixFromArray(outputArr1, 0, 0);
    IS_TRUE(output1 == MS->getTranspose(input1));

    double inputArr2[] = {1,2,3};
    MatrixStruct input2 = MS->createMatrixFromArray(inputArr2, 1, 3);
    double outputArr2[] = {1,2,3,2,4,6,3,6,9};
    MatrixStruct output2 = MS->createMatrixFromArray(outputArr2, 3, 3);
    IS_TRUE(output2 == MS->getMatrixMaT(input2));
}
/**
 * Main method.
 * All currently active to run tests.
*/
int main(void) {
    testArrayAssignment();
    testTranspose();
    testMultiplication();
}
