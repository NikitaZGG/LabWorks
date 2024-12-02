#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned int x;
    int i;

    cout << "¬ведите число x (0 < x < 10^9): ";
    cin >> x;
    cout << "¬ведите индекс бита i : ";
    cin >> i;

    x |= (1 << i);

    std::cout << "–езультат: " << x << std::endl;

    return 0;
}