#include "matrix.hpp"
using namespace std;

int main() {
    vector<vector<int>> matrix;
    int n;

    MatrixOperations::readMatrix(matrix, n);

    if (MatrixOperations::hasDuplicateColumns(matrix, n) && MatrixOperations::hasPrimeElement(matrix, n)) {
        MatrixOperations::sortRowsBySum(matrix, n);
    }

    MatrixOperations::writeMatrix(matrix, n);
    return 0;
}
