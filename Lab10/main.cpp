#include <iostream>
using namespace std;

// ��� ������, ����������� ������ �������� ������ ���� ������
struct Node
{
    int info;     // �������� ����������, ���������� � ���� ����
    Node* next;  // ����� ���������� ���� ������
};

// ����������� ������
void print_list(Node* top)
{
    Node* p = top;  // ����� �������� �������� ������
    while (p != nullptr) {
        cout << p->info << " ";  // �������� �������� ���������� �������� ����
        p = p->next;  // ����� ���������� ���� ���������� �������
    }
}

// �������, �����������, ��� ��� �������� ������ � �������� `top` ����������� �� ������������� ������ ��� ��������� �����
bool list_is_sorted(Node* top)
{
    Node* p = top; // ����� �������� ���� ������
    // �������� ������ �����
    int first_digit = top->info / 10; // �������� ������ �����
    while (p != nullptr) {
        if (p->info / 10 != first_digit) return false; // ���� ������ ����� �� ���������
        p = p->next;  // ����� ���������� ���� ���������� �������
    }
    return true;
}

// ������� ��������� ����� � �������������� ������� � ������� 1, 5 ��� 7
void process_numbers(Node*& top)
{
    Node* p = top;
    Node* prev = nullptr;

    while (p != nullptr) {
        bool is_prime = true;
        if (p->info < 2) is_prime = false; // 0 � 1 �� �������
        for (int i = 2; i * i <= p->info; i++) {
            if (p->info % i == 0) {
                is_prime = false;
                break;
            }
        }

        // ������� ��������� �����
        if (!is_prime) {
            if (prev == nullptr) {
                top = p->next; // ������� ������ �������
                delete p;
                p = top;
            }
            else {
                prev->next = p->next; // ������� ������� �������
                delete p;
                p = prev->next;
            }
        }
        else {
            // ������������ ������� ����� � ������� 1, 5 ��� 7
            if (p->info % 10 == 1 || p->info % 10 == 5 || p->info % 10 == 7) {
                Node* new_node = new Node{ p->info, p->next };
                p->next = new_node;
                p = new_node->next; // ��������� � ���������� ��������
            }
            else {
                prev = p;
                p = p->next; // ��������� � ���������� ��������
            }
        }
    }
}

// �������� ������
void delete_list(Node* top)
{
    Node* p = top;
    while (p != nullptr) {
        Node* temp = p->next;
        delete p;
        p = temp;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Node* top = nullptr;

    int n;    // ���������� ��������� ������������������
    cin >> n; // ������ � ����������

    // ������ ������ �������
    int x;
    cin >> x;

    // ������ ������� ������
    top = new Node{ x, nullptr };
    Node* pp = top; // ��������� �� ��������� ����

    // ������ ��������� ��������
    for (int i = 1; i < n; i++) {
        cin >> x;
        pp->next = new Node{ x, nullptr }; // ��������� ����� ����
        pp = pp->next; // ��������� � ������ ����
    }

    // ���������, ����������� �� ������������������
    if (list_is_sorted(top)) {
        process_numbers(top); // ������������ �����
    }
    else {
        // ���������� �� ���������� (����� �����������)
    }

    print_list(top); // �������� ������
    delete_list(top); // ����������� ������
    return 0;
}
