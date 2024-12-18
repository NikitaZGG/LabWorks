#include <iostream>
using namespace std;

// Тип данных, описывающий каждый отдельно взятый узел списка
struct Node
{
    int info;     // полезная информация, хранящаяся в этом узле
    Node* next;  // адрес следующего узла списка
};

// Распечатать список
void print_list(Node* top)
{
    Node* p = top;  // Адрес текущего элемента списка
    while (p != nullptr) {
        cout << p->info << " ";  // Печатаем полезную информацию текущего узла
        p = p->next;  // Адрес следующего узла становится текущим
    }
}

// Функция, проверяющая, что все элементы списка с вершиной `top` упорядочены по невозрастанию первой или последней цифры
bool list_is_sorted(Node* top)
{
    Node* p = top; // Адрес текущего узла списка
    // Проверка первой цифры
    int first_digit = top->info / 10; // Получаем первую цифру
    while (p != nullptr) {
        if (p->info / 10 != first_digit) return false; // Если первая цифра не совпадает
        p = p->next;  // Адрес следующего узла становится текущим
    }
    return true;
}

// Удалить составные числа и продублировать простые с цифрами 1, 5 или 7
void process_numbers(Node*& top)
{
    Node* p = top;
    Node* prev = nullptr;

    while (p != nullptr) {
        bool is_prime = true;
        if (p->info < 2) is_prime = false; // 0 и 1 не простые
        for (int i = 2; i * i <= p->info; i++) {
            if (p->info % i == 0) {
                is_prime = false;
                break;
            }
        }

        // Удаляем составные числа
        if (!is_prime) {
            if (prev == nullptr) {
                top = p->next; // Удаляем первый элемент
                delete p;
                p = top;
            }
            else {
                prev->next = p->next; // Удаляем текущий элемент
                delete p;
                p = prev->next;
            }
        }
        else {
            // Продублируем простые числа с цифрами 1, 5 или 7
            if (p->info % 10 == 1 || p->info % 10 == 5 || p->info % 10 == 7) {
                Node* new_node = new Node{ p->info, p->next };
                p->next = new_node;
                p = new_node->next; // Переходим к следующему элементу
            }
            else {
                prev = p;
                p = p->next; // Переходим к следующему элементу
            }
        }
    }
}

// Удаление списка
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

    int n;    // Количество элементов последовательности
    cin >> n; // Читаем с клавиатуры

    // Читаем первый элемент
    int x;
    cin >> x;

    // Создаём вершину списка
    top = new Node{ x, nullptr };
    Node* pp = top; // Указатель на последний узел

    // Читаем остальные элементы
    for (int i = 1; i < n; i++) {
        cin >> x;
        pp->next = new Node{ x, nullptr }; // Добавляем новый узел
        pp = pp->next; // Переходим к новому узлу
    }

    // Проверяем, упорядочена ли последовательность
    if (list_is_sorted(top)) {
        process_numbers(top); // Обрабатываем числа
    }
    else {
        // Сортировка по неубыванию (можно реализовать)
    }

    print_list(top); // Печатаем список
    delete_list(top); // Освобождаем память
    return 0;
}
