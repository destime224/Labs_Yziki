#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

struct ListNode{
	int value;
	ListNode *nextNode;
};

void inputList(ListNode *&first, int size);
void printList(ListNode *p);
void addIntoListFirst(ListNode *&first, int value);
bool addIntoListAfter(ListNode *&first, int nodeBeforeAddedOne, int value);
void deleteElementInListWithIndex(ListNode *&first, int index);
void searchInList(ListNode *first, ListNode *&searchNode, int value);

void pause() {
    cin.ignore(1024, '\n');
    cin.get();
}

int irand(int a, int b) {
    return rand()%(b-a+1)+a;
}

void randomList(ListNode *&list, int size) {
    list = new ListNode;

    ListNode *p = list;
    p->value = irand(-100, 100);
    for (unsigned i = 0; i < size-1; i++) {
        p->nextNode = new ListNode;
        p = p->nextNode;
        p->value = irand(-100, 100);
    }
    p->nextNode = NULL;
}

void deleteWholeList(ListNode *&list) {
    if (list == NULL) return;
    ListNode *p = list;
    list = NULL;
    while (p->nextNode) {
        ListNode *w = p->nextNode;
        delete p;
        p = w;
    }
    delete p;
}

void task1(ListNode *&list) {
    deleteWholeList(list);
    size_t listSize;
    cout << "Введите размер списка: ";
    cin >> listSize;
    cout << "Вводите элементы списка↓" << endl;
    inputList(list, listSize);
}

void task2(ListNode *&list) {
    deleteWholeList(list);
    size_t listSize;
    cout << "Введите размер списка: ";
    cin >> listSize;
    randomList(list, listSize);
}

void task3(ListNode *&list) {
    printList(list);
    pause();
}

void task4(ListNode *&list) {
    int el;
    cout << "Введите элемент: ";
    cin >> el;
    addIntoListFirst(list, el);
}

void task5(ListNode *&list) {
    int el; size_t i;
    cout << "Введите индекс и элемент (через пробел): ";
    cin >> i >> el;

    bool success = addIntoListAfter(list, i, el);
    if (!success) {
        cout << "Произошла ошибка при добавлении элемента" << endl;
        pause();
    }
}

unsigned countNodesOfList(ListNode *list) {
    unsigned n = 0;
    ListNode *p = list;
    while (p) {
        n++;
        p = p->nextNode;
    }
    return n;
}

bool addIntoListLast(ListNode *&list, int el) {
    auto listSize = countNodesOfList(list);
    return addIntoListAfter(list, listSize-1, el);
}

void task6(ListNode *&list) {
    int el;
    cout << "Введите элемент: ";
    cin >> el;
    bool success = addIntoListLast(list, el);
    if (!success) {
        cout << "Произошла ошибка при добавлении элемента" << endl;
        pause();
    }
}

bool addIntoListBefore(ListNode *list, int nodeAfterAddedOne, int value) {
    return addIntoListAfter(list, nodeAfterAddedOne-1, value);
}

void task7(ListNode *&list) {
    int el; size_t i;
    cout << "Введите индекс и элемент (через пробел): ";
    cin >> i >> el;

    bool success = addIntoListBefore(list, i, el);
    if (!success) {
        cout << "Произошла ошибка при добавлении элемента" << endl;
        pause();
    }
}

void task8(ListNode *&list) {
    size_t i;
    cout << "Введите индекс: ";
    cin >> i;
    deleteElementInListWithIndex(list, i);
}

void deleteFirstElementInList(ListNode *&list) {
    deleteElementInListWithIndex(list, 0);
}

void task9(ListNode *&list) {
    deleteFirstElementInList(list);
}

void deleteLastElementInList(ListNode *&list) {
    auto listSize = countNodesOfList(list);
    deleteElementInListWithIndex(list, listSize-1);
}

void task10(ListNode *&list) {
    deleteLastElementInList(list);
}

void task11(ListNode *&list) {
    deleteWholeList(list);
}

void task12(ListNode *&list) {
    cout << "В списке " << countNodesOfList(list) << " элементов" << endl;
    pause();
}

void getNodeOfList(ListNode *list, int index, ListNode *&node) {
    node = list;
    for (unsigned i = 0; i < index; i++) {
        node = node->nextNode;
        if (node == NULL) {
            break;
        }
    }
}

void printNodeInfo(ListNode *node, size_t index) {
    cout << "Данные о узле:\n" << "\tИндекс: " << index << "\n\tИнформация: " << node->value << "\n\tАдрес: " << node << "\n\tАдрес следующего узла: " << node->nextNode << endl;
}

void task13(ListNode *&list) {
    size_t i;
    cout << "Введите индекс: ";
    cin >> i;

    ListNode *node = NULL;
    getNodeOfList(list, i, node);
    if (node) {
        printNodeInfo(node, i);
    } else {
        cout << "Данного узла нет" << endl;
    }
    pause();
}

void task14(ListNode *&list) {
    int el;
    cout << "Введите элемент: ";
    cin >> el;
    ListNode *searchNodes = NULL;
    searchInList(list, searchNodes, el);
    cout << "Найденные образцы:" << endl;
    ListNode *p = searchNodes;
    size_t i = 0;
    while(p != NULL) {
        cout << "Образец " << i++ << ":" << endl;
        ListNode *node;
        getNodeOfList(list, p->value, node);
        printNodeInfo(node, p->value);
        p = p->nextNode;
    }
    pause();
}

void copyList(ListNode *list, ListNode *&copy) {
    if (list == NULL) {
        copy = NULL;
        return;
    }
    ListNode *p = list;
    ListNode *newList = new ListNode;
    copy = newList;
    newList->value = p->value;
    p = p->nextNode;
    while (p) {
        newList->nextNode = new ListNode;
        newList = newList->nextNode;
        newList->value = p->value;
        p = p->nextNode;
    }
    newList->nextNode = NULL;
}

void printDiffLists(ListNode *node, ListNode *copyNode, size_t index) {
    cout << "Данные о узлах (старый, скопированный):\n" << "\tИндекс: " << index << "\n\tИнформация: " << node->value << ", " << copyNode->value << "\n\tАдрес: " << node << ", " << copyNode << "\n\tАдрес следующего узла: " << node->nextNode << ", " << copyNode->nextNode << endl;
}

void task15(ListNode *list) {
    ListNode *copy = NULL;
    copyList(list, copy);

    cout << "Скопированный список: ";
    printList(copy);
    cout << "Узлы: " << endl;
    ListNode *p = list;
    ListNode *cp = copy;
    size_t i = 0;
    while(p != NULL) {
        cout << "Образцы " << i << ":" << endl;
        printDiffLists(p, cp, i++);
        p = p->nextNode;
        cp = cp->nextNode;
    }
    deleteWholeList(copy);
    pause();
}

void splitListIntoTwo(ListNode *list, ListNode *&one, ListNode *&two, bool (*func)(int value)) {
    ListNode *p = list;
    ListNode *onePt = one;
    ListNode *twoPt = two;
    while (p) {
        ListNode *n = new ListNode;
        n->nextNode = NULL;
        n->value = p->value;
        if (func(n->value)) {
            if (onePt == NULL) {
                one = n;
                onePt = n;
            } else {
                onePt->nextNode = n;
                onePt = n;
            }
        } else {
            if (twoPt == NULL) {
                two = n;
                twoPt = n;
            } else {
                twoPt->nextNode = n;
                twoPt = n;
            }
        }
        p = p->nextNode;
    }
}

void task16(ListNode *list) {
    if (list == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    ListNode *one = NULL;
    ListNode *two = NULL;

    splitListIntoTwo(list, one, two, [](int value){return value % 2 == 0;});
    ListNode *p = one;
    cout << "Список №1:" << endl;
    size_t i = 0;
    while (p) {
        cout << "Узел " << i << ":" << endl;
        printNodeInfo(p, i++);
        p = p->nextNode;
    }
    cout << endl;

    p = two;
    cout << "Список №2:" << endl;
    i = 0;
    while (p) {
        cout << "Узел" << i << ":" << endl;
        printNodeInfo(p, i++);
        p = p->nextNode;
    }
    pause();
}

void sortList(ListNode *&list) {
    unsigned listSize = countNodesOfList(list);
    ListNode **nodesArray = new ListNode*[listSize];

    auto p = list;
    for (size_t i = 0; i < listSize; i++) {
        nodesArray[i] = p;
        p = p->nextNode;
    }

    stable_sort(nodesArray, nodesArray + listSize, [](ListNode *a, ListNode *b){return a->value < b->value;});
    for (size_t i = 0; i < listSize; i++) {
        if (i+1 == listSize) {
            nodesArray[i]->nextNode = NULL;
        } else {
            nodesArray[i]->nextNode = nodesArray[i+1];
        }
    }
    list = nodesArray[0];
    delete[] nodesArray;
}

void task17(ListNode *&list) {
    sortList(list);
    cout << "Отсортированный список: " << endl;
    ListNode *p = list;
    size_t i = 0;
    while (p) {
        cout << "Узел №" << i << ":" << endl;
        printNodeInfo(p, i++);
        p = p->nextNode;
    }
    pause();
}

int main() {
    srand(time(0));
    ListNode *list = NULL;

    unsigned n;
    while (1) {
        cout << "Выберите действия:\n\n" << "\t1. Ввод списка\n" << "\t2. Случайно заполнить список\n" << "\t3. Вывод списка\n" \
            << "\t4. Вставить элемент в начало списка\n" << "\t5. Вставить элемент в середину списка\n" \
            << "\t6. Вставить элемент в конец списка\n" << "\t7. Вставить элемент в середину перед i-ым элементом\n" \
            << "\t8. Удалить элемент из списка\n" << "\t9. Удалить элемент из начала списка\n" << "\t10. Удалить элемент из конца списка\n" \
            << "\t11. Удалить весь список\n" << "\t12. Подсчитать элементы\n" << "\t13. Получить доступ к элементу\n" \
            << "\t14. Поиск элемента\n" << "\t15. Создать копию списка\n" << "\t16. Разбить список на две части\n" << "\t17. Сортировать список\n" \
            << "\t0. Выход\n" << endl;
        cout << "Введите действие: ";
        cin >> n;
        switch (n) {
            case 1: 
                task1(list);
                break;
            case 2:
                task2(list);
                break;
            case 3:
                task3(list);
                break;
            case 4:
                task4(list);
                break;
            case 5:
                task5(list);
                break;
            case 6:
                task6(list);
                break;
            case 7:
                task7(list);
                break;
            case 8:
                task8(list);
                break;
            case 9:
                task9(list);
                break;
            case 10:
                task10(list);
                break;
            case 11:
                task11(list);
                break;
            case 12:
                task12(list);
                break;
            case 13:
                task13(list);
                break;
            case 14:
                task14(list);
                break;
            case 15:
                task15(list);
                break;
            case 16:
                task16(list);
                break;
            case 17:
                task17(list);
                break;
            case 0:
                exit(0);
        }
    }
}

void inputList(ListNode *&first, int size)
{
	first = new ListNode;
	cin >> first->value;
	ListNode *p = first;
	for (int i = 0; i<size - 1; i++){
		p->nextNode = new ListNode;
		p = p->nextNode;
		cin >> p->value;
	}
	p->nextNode = 0;
}

void printList(ListNode *p)
{
	while (p){
		cout << p->value << " ";
		p = p->nextNode;
	}
	cout << endl;
}

void addIntoListFirst(ListNode *&first, int value)
{
	ListNode *q = new ListNode;
	q->value = value;
	q->nextNode = first;
	first = q;
}

bool addIntoListAfter(ListNode *&first, int nodeBeforeAddedOne, int value)
{
	if (nodeBeforeAddedOne < 0 || !first) return 0; 
	ListNode *p = first;
	int i = 0;
	for (i = 0; i < nodeBeforeAddedOne && p->nextNode; i++) p = p->nextNode;
	if (i<nodeBeforeAddedOne) return 0;
	ListNode *w = new ListNode;
	w->value = value;
	w->nextNode = p->nextNode;
	p->nextNode = w;
	return 1;
}

void deleteElementInListWithIndex(ListNode *&first, int index)
{
    if (index == 0) {
        ListNode *w = first;
        first = w->nextNode;
        delete w;
        return;
    }
	ListNode *p = first;
	for (int i = 0; i < index - 1 && p->nextNode; i++) p = p->nextNode;

	ListNode *w = p->nextNode;
	p->nextNode = w->nextNode;
	delete w;
}

void searchInList(ListNode *first, ListNode *&searchNode, int value)
{
	if (!first) return;
	ListNode *p = first;
	int i = 0;
	while (p){
		if (p->value == value) addIntoListFirst(searchNode, i);
		i++;
		p = p->nextNode;
	}
}
