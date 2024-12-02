#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;

bool startsWithOne(int num) {
    return to_string(num).front() == '1';
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}


bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
   
    int n;
    cout << "Введите количество чисел (n <= 10000): ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Введите последовательность чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }
    if (any_of(nums1.begin(), nums1.end(), startsWithOne)) {
        sort(nums1.begin(), nums1.end());
    }
    cout << "Отсортированная последовательность: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    cout << "Введите количество чисел для задания 2 (n <= 1000): ";
    cin >> n;
    vector<int> nums2(n);
    cout << "Введите последовательность чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    sort(nums2.begin(), nums2.end(), [](int a, int b) {
        if (to_string(a).front() != to_string(b).front()) {
            return to_string(a).front() < to_string(b).front();
        }
        if (sumOfDigits(a) != sumOfDigits(b)) {
            return sumOfDigits(a) < sumOfDigits(b);
        }
        return a < b;
        });
    cout << "Отсортированная последовательность: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;


    int rows, cols;
    cout << "Введите размеры матрицы (n, m <= 100): ";
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введите элементы матрицы: ";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    int closestRow = -1;
    int closestSum = INT_MAX;
    for (int i = 0; i < rows; ++i) {
        int rowSum = accumulate(matrix[i].begin(), matrix[i].end(), 0);
        if (abs(rowSum) < abs(closestSum)) {
            closestSum = rowSum;
            closestRow = i;
        }
    }
    if (closestRow != -1) {
        fill(matrix[closestRow].begin(), matrix[closestRow].end(), 0);
    }
    cout << "Матрица после замены: " << endl;
    for (const auto& row : matrix) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }

 
    cout << "Введите количество чисел для задания 4: ";
    cin >> n;
    vector<int> nums4(n);
    cout << "Введите последовательность чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums4[i];
    }
    set<int> uniqueNums;
    vector<int> result;
    for (int num : nums4) {
        if (uniqueNums.insert(num).second) {
            result.push_back(num);
            result.push_back(num); // дублируем
        }
    }
    cout << "Результат: ";
    for (int num : result) cout << num << " ";
    cout << endl;

   
    cout << "Введите количество чисел для задания 5 (n <= 10000): ";
    cin >> n;
    vector<int> nums5(n);
    cout << "Введите последовательность чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums5[i];
    }
    vector<int> filtered;
    for (int num : nums5) {
        if (to_string(num).find('7') != string::npos && to_string(num).find('6') == string::npos) {
            continue; 
        }
        filtered.push_back(num);
        if (isPrime(num)) {
            filtered.push_back(num); 
        }
    }
    cout << "Результат: ";
    for (int num : filtered) cout << num << " ";
    cout << endl;

    return 0;
}
