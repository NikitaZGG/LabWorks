#include <iostream>
using namespace std;

int main() {
  
    int A, B, C;
    cout << "Введите натуральные числа A, B и C: ";
    cin >> A >> B >> C;

    if (A % B == 0) {
        if (B > C) {
            cout << "Результат: " << A / B + C << endl;
        }
        else {
            cout << "Результат: " << A / B - C << endl;
        }
    }
    else {
        cout << "Результат: " << (A + B) * C << endl;
    }

    int N;
    cout << "Введите номер месяца (1-12): ";
    cin >> N;

    switch (N) {
    case 1: cout << "Январь" << endl; break;
    case 2: cout << "Февраль" << endl; break;
    case 3: cout << "Март" << endl; break;
    case 4: cout << "Апрель" << endl; break;
    case 5: cout << "Май" << endl; break;
    case 6: cout << "Июнь" << endl; break;
    case 7: cout << "Июль" << endl; break;
    case 8: cout << "Август" << endl; break;
    case 9: cout << "Сентябрь" << endl; break;
    case 10: cout << "Октябрь" << endl; break;
    case 11: cout << "Ноябрь" << endl; break;
    case 12: cout << "Декабрь" << endl; break;
    default: cout << "Ошибка: Неверный номер месяца!" << endl; break;
    }

    
    int x;
    cout << "Введите значение x (-1 или 1): ";
    cin >> x;

    if (x == -1) {
        cout << "Negative number" << endl;
    }
    else if (x == 1) {
        cout << "Positive number" << endl;
    }
    else {
        cout << "Ошибка: x может принимать только значения -1 или 1" << endl;
    }

    return 0;
}
