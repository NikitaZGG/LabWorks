#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B, C;
    int p;
    cin >> A >> B >> C;

    if (A + B > C && A + C > B && B + C > A) {
        p = (A + B + C) / 2.0;
        cout << endl << sqrt(p * (p - A) * (p - B) * (p - C)) << endl;
    }
    else {
        cout << "Треугольник не существует" << endl;
    }

    return 0;
}