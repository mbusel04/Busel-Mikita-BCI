// MatrixService.h

#define MatrixService_h

/**
 * Limits the maximum size of matrices processed by the MatrixService
 * 
 * @showinitializer
*/
static const short MAT_MAX_SIZE = 8;

/**
 * Helper container that describes matrices of size m x n.
 * arr - entries of matrix which are stored in 2D array.
 * m - number of rows in the matrix.
 * n - number of columns in the matrix.
*/
struct MatrixStruct {
    double arr[MAT_MAX_SIZE][MAT_MAX_SIZE];
    unsigned short m = 0;
    unsigned short n = 0;

    bool operator==(const MatrixStruct& rhs);
};

class MatrixService 
{

    protected:

        MatrixService();

        static MatrixService* matrixService_;

    public:

        static MatrixService *GetInstance();

        MatrixStruct createEmptyMatrix(unsigned short m, unsigned short n);

        MatrixStruct createMatrixFromArray(double arr[], unsigned short m, unsigned short n);

        MatrixStruct getTranspose(MatrixStruct mat);

        MatrixStruct multiplyMatrices(MatrixStruct mat1, MatrixStruct mat2);

        MatrixStruct getMatrixMaT(MatrixStruct mat);

        void printMatrix(MatrixStruct mat);

        int getMatrixM(MatrixStruct mat) const {return mat.m; };

        int getMatrixN(MatrixStruct mat) const {return mat.n; };

        MatrixService(MatrixService &other) = delete;

        void operator=(const MatrixService &) = delete;

};
