#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    
    int n;
    cout << "Введите количес��во вещественных чисел: ";
    cin >> n;

    vector<double> numbers(n);
    double product = 1.0;
    double minNegative = numeric_limits<double>::max();
    int minIndex = -1;

    cout << "Введите вещественные числа:\n";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];       
        if (numbers[i] < 0 && numbers[i] != static_cast<int>(numbers[i])) {
            product *= numbers[i];            
            if (numbers[i] < minNegative) {
                minNegative = numbers[i];
                minIndex = i;
            }
        }
    }

    cout << "Произведение отрицательных чисел с ненулевой дробной частью: " << product << endl;
    cout << "Наименьшее отрицательное число с ненулевой дробной частью: " << minNegative << endl;
    cout << "Индекс наименьшего числа: " << minIndex << endl;

    
    long long N;
    cout << "Введите натуральное число N (N < 10^9): ";
    cin >> N;

    int minDigit = 9;
    while (N > 0) {
        int digit = N % 10; 
        if (digit < minDigit) {
            minDigit = digit; 
        }
        N /= 10; 
    }

    cout << "Наименьшая цифра числа: " << minDigit << endl;

    return 0;
}
