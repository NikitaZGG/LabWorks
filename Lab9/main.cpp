#include <iostream>
using namespace std;

void printBytes(int number) {
    unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&number);

    cout << "Содержимое байтов числа " << number << ":\n";

    for (size_t i = 0; i < sizeof(int); ++i) {
        cout << "Байт " << i << ": " << static_cast<int>(bytePtr[i]) << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int number;
    cout << "Введите целое число: ";
    cin >> number;

    printBytes(number); 
    return 0;
}
