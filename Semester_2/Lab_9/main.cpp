#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

struct QueueNode {
  int value;
  QueueNode *next;
};

void add_queue(QueueNode *&first, QueueNode *&last, int value);
bool del_queue(QueueNode *&first, QueueNode *&last, int &value);

struct StackNode {
    int value;
    StackNode *next;
};

void add_stack(StackNode *&first, int value);
bool del_stack(StackNode *&first, int &value);
void reverse_stack(StackNode *&first);
void print_stack(StackNode *&first);

struct DequeNode {
    int value;
    DequeNode *next;
    DequeNode *previous;
};

void add_deque_at_start(DequeNode *&first, DequeNode *&last, int value);
bool del_deque_at_start(DequeNode *&first, DequeNode *&last, int &value);
void add_deque_at_end(DequeNode *&first, DequeNode *&last, int value);
bool del_deque_at_end(DequeNode *&first, DequeNode *&last, int &value);

void pause() {
    cin.ignore(1024, '\n');
    cin.get();
}

int irand(int a, int b) {
    return rand()%(b-a+1)+a;
}

void fillStackFromInput(StackNode *&first, size_t count) {
    for (size_t i = 0; i < count; i++) {
        int value;
        cin >> value;
        add_stack(first, value);
    }
}

void task1(StackNode *&first) {
    size_t count;
    cout << "Введите кол-во элементов: ";
    cin >> count;
    cout << "Введите элементы через пробел" << endl;
    fillStackFromInput(first, count);
}

void fillStackWithRandomNumbers(StackNode *&first, size_t count) {
    for (size_t i = 0; i < count; i++) {
        add_stack(first, irand(-100, 100));
    }
}

void task2(StackNode *&first) {
    size_t count;
    cout << "Введите кол-во элементов: ";
    cin >> count;
    fillStackWithRandomNumbers(first, count);
}

void task3(StackNode *&first) {
    int value;
    cout << "Введите элемент: ";
    cin >> value;
    add_stack(first, value);
}

void task4(StackNode *&first) {
    int value;
    auto success = del_stack(first, value);
    if (success) 
        cout << "Вынутое значение: " << value << endl;
    else
        cout << "Стек пустой" << endl;
    pause();
}

void task5(StackNode *&first) {
    reverse_stack(first);
}

void task6(StackNode *&first) {
    print_stack(first);
    pause();
}

void fillQueueFromInput(QueueNode *&first, QueueNode *&last, size_t count) {
    for (size_t i = 0; i < count; i++) {
        int value;
        cin >> value;
        add_queue(first, last, value);
    }
}

void task7(QueueNode *&first, QueueNode *&last) {
    size_t count;
    cout << "Введите кол-во элементов: ";
    cin >> count;
    cout << "Введите элементы через пробел" << endl;
    fillQueueFromInput(first, last, count);
}

void fillQueueWithRandowNumbers(QueueNode *&first, QueueNode *&last, size_t count) {
    for (size_t i = 0; i < count; i++) {
        add_queue(first, last, irand(-100, 100));
    }
}

void task8(QueueNode *&first, QueueNode *&last) {
    size_t count;
    cout << "Введите кол-во элементов: ";
    cin >> count;
    fillQueueWithRandowNumbers(first, last, count);
}

void task9(QueueNode *&first, QueueNode *&last) {
    int value;
    cout << "Введите элемент: ";
    cin >> value;
    add_queue(first, last, value);
}

void task10(QueueNode *&first, QueueNode *&last) {
    int value;
    auto success = del_queue(first, last, value);
    if (success) 
        cout << "Вынутое значение: " << value << endl;
    else
        cout << "Очередь пустая" << endl;
    pause();
}

void fillDequeFromInput(DequeNode *&first, DequeNode *&last, size_t count) {
    for (size_t i = 0; i < count; i++) {
        int value;
        cin >> value;
        add_deque_at_end(first, last, value);
    }
}

void task11(DequeNode *&first, DequeNode *&last) {
    size_t count;
    cout << "Введите кол-во элементов: ";
    cin >> count;
    cout << "Введите элементы через пробел" << endl;
    fillDequeFromInput(first, last, count);
}

void fillDequeWithRandomNumbers(DequeNode *&first, DequeNode *&last, size_t count) {
    for (size_t i = 0; i < count; i++) {
        add_deque_at_end(first, last, irand(-100, 100));
    }
}

void task12(DequeNode *&first, DequeNode *&last) {
    size_t count;
    cout << "Введите кол-во элементов: ";
    cin >> count;
    fillDequeWithRandomNumbers(first, last, count);
}

void task13(DequeNode *&first, DequeNode *&last) {
    int value;
    cout << "Введите элемент: ";
    cin >> value;
    add_deque_at_start(first, last, value);
}

void task14(DequeNode *&first, DequeNode *&last) {
    int value;
    auto success = del_deque_at_start(first, last, value);
    if (success) 
        cout << "Вынутое значение: " << value << endl;
    else
        cout << "Дек пустой" << endl;
    pause();
}

void task15(DequeNode *&first, DequeNode *&last) {
    int value;
    cout << "Введите элемент: ";
    cin >> value;
    add_deque_at_end(first, last, value);
}

void task16(DequeNode *&first, DequeNode *&last) {
    int value;
    auto success = del_deque_at_end(first, last, value);
    if (success) 
        cout << "Вынутое значение: " << value << endl;
    else
        cout << "Дек пустой" << endl;
    pause();
}

int main() {
    StackNode *stack = 0;

    QueueNode *queueFirst = 0;
    QueueNode *queueLast = 0;

    DequeNode *dequeFirst = 0;
    DequeNode *dequeLast = 0;

    unsigned n = 1;
    while (n) {
        cout << "Возможные действия:\n\n";
        cout << "\tСтек:\n" << "\t1. Ввести стек\n" << "\t2. Рандомно заполнить стек\n" \
        << "\t3. Добавить элемент в стек\n" << "\t4. Вынуть элемент из стека\n" \
        << "\t5. Перевернуть стек\n" << "\t6. Вывести стек\n\n";

        cout << "\tОчередь:\n" << "\t7. Ввести очередь\n" << "\t8. Рандомно заполнить очередь\n" \
        << "\t9. Добавить элемент в очередь\n" << "\t10. Вынуть элемент из очереди\n\n";

        cout << "\tДек:\n" << "\t11. Ввести дек\n" << "\t12. Рандомно заполнить дек\n" \
        << "\t13. Добавить элемент в начало дека\n" << "\t14. Вынуть элемент из начала дека\n" \
        << "\t15. Добавить элемент в конец дека\n" << "\t16. Вынуть элемент из конца дека\n\n";

        cout << "\t0. Выход\n";

        cout << "Введите действие: ";
        cin >> n;
        switch (n) {
            case 0:
                exit(0);

            case 1:
                task1(stack);
                break;
            case 2:
                task2(stack);
                break;
            case 3:
                task3(stack);
                break;
            case 4:
                task4(stack);
                break;
            case 5:
                task5(stack);
                break;
            case 6:
                task6(stack);
                break;

            case 7:
                task7(queueFirst, queueLast);
                break;
            case 8:
                task8(queueFirst, queueLast);
                break;
            case 9:
                task9(queueFirst, queueLast);
                break;
            case 10:
                task10(queueFirst, queueLast);
                break;

            case 11:
                task11(dequeFirst, dequeLast);
                break;
            case 12:
                task12(dequeFirst, dequeLast);
                break;
            case 13:
                task13(dequeFirst, dequeLast);
                break;
            case 14:
                task14(dequeFirst, dequeLast);
                break;
            case 15:
                task15(dequeFirst, dequeLast);
                break;
            case 16:
                task16(dequeFirst, dequeLast);
                break;
        }
    } 
}

bool del_queue(QueueNode *&first, QueueNode *&last, int &value) {
    if (!first)
        return false;
    value = first->value;
    if (first == last) {
        delete first;
        first = last = 0;
    } else {
        QueueNode *p = first;
        first = first->next;
        delete p;
    }
    return true;
}

void add_queue(QueueNode *&first, QueueNode *&last, int value) {
    QueueNode *p = new QueueNode;
    p->value = value;
    p->next = 0;
    if (!first) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

void add_stack(StackNode *&first, int value) {
    StackNode *p = new StackNode;
    p->value = value;
    p->next = 0;
    if (first) {
        p->next = first;
    }
    first = p;
}

bool del_stack(StackNode *&first, int &value) {
    if (!first) return false;
    StackNode *p = first;
    first = first->next;
    value = p->value;
    delete p;
    return true;
}

void reverse_stack(StackNode *&first) {
    if (!first) return;
    StackNode *p = 0;
    while (true) {
        int value;
        bool success = del_stack(first, value);
        if (!success) break;
        add_stack(p, value);
    }
    first = p;
}

void print_stack(StackNode *&first) {
    reverse_stack(first);
    StackNode *p;
    while (true) {
        int value;
        bool success = del_stack(first, value);
        if (!success) break;
        cout << value << ' ';
        add_stack(p, value);
    }
    first = p;
}

void add_deque_at_start(DequeNode *&first, DequeNode *&last, int value) {
    DequeNode *p = new DequeNode;
    p->value = value;
    p->next = 0;
    p->previous = 0;
    if (!first) {
        first = last = p;
    } else {
        p->next = first;
        first->previous = p;
        first = p;
    }
}

bool del_deque_at_start(DequeNode *&first, DequeNode *&last, int &value) {
    if (!first) return 0;
    value = first->value;
    DequeNode *p = first;
    first = first->next;
    if (first)
        first->previous = 0;
    else
        last = 0;
    delete p;
    return 1;
}

void add_deque_at_end(DequeNode *&first, DequeNode *&last, int value) {
    DequeNode *p = new DequeNode;
    p->value = value;
    p->next = 0;
    p->previous = 0;
    if (!last) {
        last = first = p;
    } else {
        p->previous = last;
        last->next = p;
        last = p;
    }
}

bool del_deque_at_end(DequeNode *&first, DequeNode *&last, int &value) {
    if (!last) return 0;
    value = last->value;
    DequeNode *p = last;
    last = last->previous;
    if (last)
        last->next = 0;
    else 
        first = 0;
    delete p;
    return 1;
}