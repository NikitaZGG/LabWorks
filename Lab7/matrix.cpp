#include "matrix.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

namespace MatrixOperations {
    void readMatrix(vector<vector<int>>& matrix, int& n) {
        cin >> n;
        matrix.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];
    }

    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= sqrt(num); ++i)
            if (num % i == 0) return false;
        return true;
    }

    bool hasDuplicateColumns(const vector<vector<int>>& matrix, int n) {
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                bool equal = true;
                for (int i = 0; i < n; ++i) {
                    if (matrix[i][j] != matrix[i][k]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) return true;
            }
        }
        return false;
    }

    bool hasPrimeElement(const vector<vector<int>>& matrix, int n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (isPrime(abs(matrix[i][j]))) return true;
        return false;
    }

    void sortRowsBySum(vector<vector<int>>& matrix, int n) {
        sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
            return accumulate(a.begin(), a.end(), 0, [](int sum, int val) { return sum + abs(val); }) <
                   accumulate(b.begin(), b.end(), 0, [](int sum, int val) { return sum + abs(val); });
        });
    }

    void writeMatrix(const vector<vector<int>>& matrix, int n) {
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
}
