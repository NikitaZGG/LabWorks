#ifndef MATRIX_HPP
#define MATRIX_HPP
using namespace std;

#include <vector>

namespace MatrixOperations {
    void readMatrix(vector<vector<int>>& matrix, int& n);
    bool hasDuplicateColumns(const vector<vector<int>>& matrix, int n);
    bool hasPrimeElement(const vector<vector<int>>& matrix, int n);
    void sortRowsBySum(vector<vector<int>>& matrix, int n);
    void writeMatrix(const vector<vector<int>>& matrix, int n);
}

#endif // MATRIX_HPP
