#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned int x;
    int i;

    cout << "������� ����� x (0 < x < 10^9): ";
    cin >> x;
    cout << "������� ������ ���� i : ";
    cin >> i;

    x |= (1 << i);

    std::cout << "���������: " << x << std::endl;

    return 0;
}