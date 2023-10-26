// MatrixService.cpp

#include "MatrixService.h"
#include <iostream>


// MatrixStruct

/**
 * Override of equals operator (==) for MatrixStruct.
 * 
 * @relatesalso MatrixStruct.
 * 
 * @param rhs (Right Hand Side) of comparison operation.
 * @return true value in case if dimensions m & n are equal and 2D array of the objects have same entries, otherwise returns false.
 * 
*/
 bool MatrixStruct::operator==(const MatrixStruct& rhs)
 {
    if(this->m != rhs.m || this->n != rhs.n) {
        return 0;
    }
    bool result = 1;
    for(int i = 0; i < rhs.m; i++)
    {
        for(int j = 0; j < rhs.n; j++)
        {
            if(this->arr[i][j] != rhs.arr[i][j]) {
                result = 0;
            }
        }
    }
    return result;
 }

// MatrixService

/**
 * Initialization of instance for MatrixService singleton.
 * 
 * @hideinitializer
*/
MatrixService* MatrixService::matrixService_{nullptr};

/**
 * Default constructor for MatrixService.
*/
MatrixService::MatrixService() {};

/**
 * Get instance of an object if it was created, otherwise creates new instance.
*/
MatrixService *MatrixService::GetInstance()
{
    if(matrixService_==nullptr){
        matrixService_ = new MatrixService();
    }
    return matrixService_;
}

/**
 * Creates new MatrisStruct object of size m x n and fills up all it's entries with 0.
 * 
 * @throws std::invalid_argument. Throws in case if m or n value exceeds maximum matrix size (MAT_MAX_SIZE).
 * 
 * @param m quantity of rows in the created matrix.
 * @param n quantity of columns in the created matrix.
 * 
 * @return New MatrixStruct of m x n dimension and all entries of 2D array equal 0.
*/
MatrixStruct MatrixService::createEmptyMatrix(unsigned short m, unsigned short n)
{   
    if(m > MAT_MAX_SIZE || n > MAT_MAX_SIZE) {
        throw std::invalid_argument("createEmptyMatrix: Out of bounds of maximum matrix dimensions!\n");
    }
    MatrixStruct mat;
    mat.m = m;
    mat.n = n;
    for(int i = 0; i < mat.m; i++)
    {
        for(int j = 0; j < mat.n; j++)
        {
            mat.arr[i][j] = 0;
        }
    }
    return mat;
}

/**
 * Creates new MatrisStruct object of size m x n and fills up all it's entries with first m*n values of input 1D array.
 * Algorithm fills up rows of the matrix first. 
 * So 3 x 4 matrix with input array = {1,2,3,...,11,12} will be filled up like example below:
 * | 1  2   3   4  |
 * | 5  6   7   8  |
 * | 9  10  11  12 | 
 * 
 * @throws std::invalid_argument. Throws in case if m or n value exceeds maximum matrix size (MAT_MAX_SIZE).
 * 
 * @param m quantity of rows in the created matrix.
 * @param n quantity of columns in the created matrix.
 * 
 * @return New MatrixStruct of m x n dimension and all entries of 2D array filled with input 1D array entries.
*/
MatrixStruct MatrixService::createMatrixFromArray(double arr[], unsigned short m, unsigned short n) 
{
    if(m > MAT_MAX_SIZE || n > MAT_MAX_SIZE) {
        throw std::invalid_argument("createMatrixFromArray: Out of bounds of maximum matrix dimensions!\n");
    }
    MatrixStruct mat;
    mat.m = m;
    mat.n = n;
    for(int i = 0; i < mat.m; i++)
    {
        for(int j = 0; j < mat.n; j++)
        {
            mat.arr[i][j] = arr[j+i*n];
        }
    }
    return mat;
}


/**
 * Creates a new matrix, which is a transpose of an input matrix.
 * For input matrix transpose will return matrix with rows and columns swapped.
 * Example:
 * Input:       Transpose:
 * | 1 2 3 |    | 1 4 |
 * | 4 5 6 |    | 2 5 |
 *              | 3 6 |
 * 
 * @param mat input matrix of MatrixStruct type.
 * 
 * @return New MatrixStruct which is a transpose of input matrix.
*/
MatrixStruct MatrixService::getTranspose(MatrixStruct mat)
{
    MatrixStruct tmat;
    tmat.m = mat.n;
    tmat.n = mat.m;
    for(int i = 0; i < tmat.n; i++)
    {
        for(int j = 0; j < tmat.m; j++)
        {
            tmat.arr[j][i] = mat.arr[i][j];
        }
    }

    return tmat;
}

/**
 * Multiplies entries of 2 input matrices, and returns a new matrix of size number of columns of first matrix by numbe of rows of second matrix.
 * 
 * @throws std::invalid_argument. Throws in case if number of columns of first input matrix doesn't equal number of rows of second input matrix.
 * 
 * @param mat1 first input matrix of MatrixStruct type, which entries will be multiplied by second.
 * @param mat2 second input matrix of MatrixStruct type, which will multiply on first one.
 * 
 * @return New MatrixStruct with a dimensions of number of rows equal to number of columns of first input matrix x number of columns equal
 * to number of rows of second input matrix.
*/
MatrixStruct MatrixService::multiplyMatrices(MatrixStruct mat1, MatrixStruct mat2) 
{ 
    if(mat1.m != mat2.n) {
        throw std::invalid_argument("multiplyMatrices: Rows of Mat1 don't match quantity of Cols of Mat2!\n");
    }
    MatrixStruct resmat;
    resmat.m = mat1.m;
    resmat.n = mat2.n;
    for (int i = 0; i < resmat.m; i++) { 
        for (int j = 0; j < resmat.n; j++) {
            resmat.arr[i][j] = 0; 
            for (int k = 0; k < mat2.m; k++) { 
                resmat.arr[i][j] += mat1.arr[i][k] * mat2.arr[k][j]; 
            }
        } 
    } 
    return resmat;
} 

/**
 * Gets a transpose of a matrix and multiplies input matrix by it's transpose. 
 * 
 * @relatesalso getTranspose(MatrixStruct mat);
 * @relatesalso multiplyMatrices(MatrixStruct mat1, MatrixStruct mat2);
 * 
 * @exceptsafe Has a potential to throw std::invalid_argument from multiplyMatrices(), but due to logic of the algorithm
 * matrices mat and temp should be multiplicable under any conditions.
 * 
 * @param mat input matrix of MatrixStruct type to be multiplied by it's transpose.
 * 
 * @return returns a product of input matrix and it's transpose.
*/
MatrixStruct MatrixService::getMatrixMaT(MatrixStruct mat)
{
    MatrixStruct temp;
    temp = MatrixService::getTranspose(mat);
    return MatrixService::multiplyMatrices(mat, temp);
}

/**
 * Prints out the matrix of MatrixStruct in a grid of size specified by internal variable of input object.
 * 
 * @param mat input matrix of MatrixStruct type to be printed out.
*/
void MatrixService::printMatrix(MatrixStruct mat)
{
    for(int i = 0; i < mat.m; i++)
    {
        for(int j = 0; j < mat.n; j++)
        {
            std::cout << mat.arr[i][j] << " \n"[j == mat.n-1];
        }
    }
    std::cout << std::endl;
}
