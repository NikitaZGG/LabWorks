#include <iostream>
using namespace std;

int main() {
  
    int A, B, C;
    cout << "������� ����������� ����� A, B � C: ";
    cin >> A >> B >> C;

    if (A % B == 0) {
        if (B > C) {
            cout << "���������: " << A / B + C << endl;
        }
        else {
            cout << "���������: " << A / B - C << endl;
        }
    }
    else {
        cout << "���������: " << (A + B) * C << endl;
    }

    int N;
    cout << "������� ����� ������ (1-12): ";
    cin >> N;

    switch (N) {
    case 1: cout << "������" << endl; break;
    case 2: cout << "�������" << endl; break;
    case 3: cout << "����" << endl; break;
    case 4: cout << "������" << endl; break;
    case 5: cout << "���" << endl; break;
    case 6: cout << "����" << endl; break;
    case 7: cout << "����" << endl; break;
    case 8: cout << "������" << endl; break;
    case 9: cout << "��������" << endl; break;
    case 10: cout << "�������" << endl; break;
    case 11: cout << "������" << endl; break;
    case 12: cout << "�������" << endl; break;
    default: cout << "������: �������� ����� ������!" << endl; break;
    }

    
    int x;
    cout << "������� �������� x (-1 ��� 1): ";
    cin >> x;

    if (x == -1) {
        cout << "Negative number" << endl;
    }
    else if (x == 1) {
        cout << "Positive number" << endl;
    }
    else {
        cout << "������: x ����� ��������� ������ �������� -1 ��� 1" << endl;
    }

    return 0;
}
