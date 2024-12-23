#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

template<typename T> T** createNxMArray(size_t n, size_t m);
template<typename T> void deleteNxMArray(T **arr, size_t n, size_t m);
void AskNAndM(size_t &n, size_t &m);
template<typename T> void fillInArrayFromInput(T **arr, size_t n, size_t m);
template<typename T> void fillInArrayRandomNumbers(T **arr, size_t n, size_t m);
template<typename T> T generateRandomNumber(T min, T max);
template<typename T> void printNxMArray(T **arr, size_t n, size_t m);
float carculateSumOfFloatNumbersGreaterThanMaximumOfNegativeNumbersInNxMArray(float **arr, size_t n, size_t m);
void sortNxMArrayByProductOfEventElementsOfNxMArray(float **arr, size_t n, size_t m);
float carculateProductOfEvenElementsOfArray(float arr[], size_t n);
void countAllZerosPositiveAndNegativeNumbersInNxMArrayAndPrintTheseAll(float **arr, size_t n, size_t m);
template<typename T> T** multiplyArrayToArray(T **vec1, size_t n1, size_t m1, T **vec2, size_t n2, size_t m2);
template<typename T> T* multiplyArrayToVector(T **arr, size_t n, size_t m, T vec[]);

int main() {
    srand(time(0));
    unsigned task_number;
    cout << "Введите номер задания: ";
    cin >> task_number;

    switch (task_number) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
    }
}

void task1() {
    size_t n, m;
    AskNAndM(n, m);

    int **arr = createNxMArray<int>(n, m); 
    fillInArrayRandomNumbers(arr, n, m);
    printNxMArray(arr, n, m); 
    deleteNxMArray(arr, n, m);
}

void task2() {
    size_t n, m;
    AskNAndM(n, m);

    float **arr = createNxMArray<float>(n, m);
    fillInArrayRandomNumbers(arr, n, m);
    printNxMArray(arr, n, m);
    deleteNxMArray(arr, n, m);
}

void task3() {
    size_t n = 4;
    size_t m = 8;

    float **arr = createNxMArray<float>(n, m);
    fillInArrayRandomNumbers(arr, n, m);
    cout << carculateSumOfFloatNumbersGreaterThanMaximumOfNegativeNumbersInNxMArray(arr, n, m);
    deleteNxMArray(arr, n, m);
}

void task4() {
    size_t n, m;
    AskNAndM(n, m);

    float **arr = createNxMArray<float>(n, m);
    fillInArrayRandomNumbers(arr, n, m);
    sortNxMArrayByProductOfEventElementsOfNxMArray(arr, n, m);
    printNxMArray(arr, n, m);
    deleteNxMArray(arr, n, m);
}

void task5() {
    size_t n, m;
    AskNAndM(n, m);

    float **arr = createNxMArray<float>(n, m);
    fillInArrayRandomNumbers(arr, n, m);
    printNxMArray(arr, n, m);
    cout << endl;
    countAllZerosPositiveAndNegativeNumbersInNxMArrayAndPrintTheseAll(arr, n, m);
    deleteNxMArray(arr, n, m);
}

void task6() {
    size_t n, m;
    AskNAndM(n, m);

    float **arr = createNxMArray<float>(n, m);
    fillInArrayRandomNumbers(arr, n, m);
    printNxMArray(arr, n, m);

    float *vec = new float[m];
    cout << "ВЫВОД МАССИВА" << endl;
    for (size_t i = 0; i < m; i++) {
        vec[i] = generateRandomNumber<float>(-100, 100);
        cout << vec[i] << '\t';
    }
    cout << endl;

    float *result = multiplyArrayToVector(arr, n, m, vec);
    cout << "ВЫВОД МАССИВА" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << result[i] << '\t';
    }

    deleteNxMArray(arr, n, m);
    delete[] vec;
    delete[] result;
}

void task7() {
    size_t n1, m1;
    AskNAndM(n1, m1);

    size_t n2, m2;
    AskNAndM(n2, m2);

    if (m1 != n2) {
        cout << "Не удалось перемножить матрицы";
        return;
    }

    int **vec1 = createNxMArray<int>(n1, m1);
    fillInArrayRandomNumbers(vec1, n1, m1);
    printNxMArray(vec1, n1, m1);

    int **vec2 = createNxMArray<int>(n2, m2);
    fillInArrayRandomNumbers(vec2, n2, m2);
    printNxMArray(vec2, n2, m2);
    
    int **result = multiplyArrayToArray(vec1, n1, m1, vec2, n2, m2);
    printNxMArray(result, n1, m2);

    deleteNxMArray(vec1, n1, m2);
    deleteNxMArray(vec2, n1, m2);
    deleteNxMArray(result, n1, m2);
}

// Создаёт динамический массив размерности N на M
template<typename T> T** createNxMArray(size_t n, size_t m) {
    T **arr = new T*[n];
    for (size_t i = 0; i < n; i++)
        arr[i] = new T[m];
    return arr;
}

// Удаляет динамический массив размерности N на M
template<typename T> void deleteNxMArray(T **arr, size_t n, size_t m) {
    for (size_t i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}

// Возращает рандомное число в диапазоне
template<typename T> T generateRandomNumber(T min, T max) {
    // Функция `constexpr` используется вместе с `std::is_integral<T>::value` чтобы определить целочисленный тип данных или с точкой
    if constexpr(is_integral<T>::value)
        return rand() % (max - min + 1) + min;
    else 
        return min + static_cast<T>(rand()) / static_cast<T>(RAND_MAX) * (max - min);
}

// Спрашивает у пользователя переменные N и M
void AskNAndM(size_t &n, size_t &m) {
    cout << "Введите N и M: ";
    cin >> n >> m;
}

// Заполняет массив N на M числами из ввода
template<typename T> void fillInArrayFromInput(T **arr, size_t n, size_t m) {
    for (size_t i = 0; i < n; i++) {
        cout << "Массив №" << i << endl;
        for (size_t j = 0; j < m; j++) {
            cout << "Введите число: ";
            cin >> arr[i][j]; 
        }
    }
}

// Заполняет массив N на M рандомными числами
template<typename T> void fillInArrayRandomNumbers(T **arr, size_t n, size_t m) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++) 
            arr[i][j] = generateRandomNumber<T>(-100, 100);
}

// Выводит массив N на M
template<typename T> void printNxMArray(T **arr, size_t n, size_t m) {
    cout << endl << "ВЫВОД МАССИВА" << endl;
    // for (size_t i = 0; i < n; i++) {
        // cout << "Массив №" << i << ":" << endl;
        // for (size_t j = 0; j < m; j++)
            // cout << "\tЭлемент №" << j << "\t" << arr[i][j] << endl; 
    // }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

float carculateSumOfFloatNumbersGreaterThanMaximumOfNegativeNumbersInNxMArray(float **arr, size_t n, size_t m) {
    // Получаем максимальное отрицательное число
    float maximumNegativeNumber = -100;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            float ijElement = arr[i][j];
            if (ijElement < 0 && ijElement > maximumNegativeNumber)
                maximumNegativeNumber = ijElement;
        }
    }

    // Считаем сумму чисел больше данного максимального отрицательного числа
    float sum = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            float ijElement = arr[i][j];
            if (ijElement > maximumNegativeNumber) {
                sum += ijElement;
            }
        }
    }
    return sum;
}

void sortNxMArrayByProductOfEventElementsOfNxMArray(float **arr, size_t n, size_t m) {
    float *products = new float[n];
    for (size_t i = 0; i < n; i++) {
        float product = carculateProductOfEvenElementsOfArray(arr[i], m);
        products[i] = product;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i+1; j < n; j++) {
            if (products[i] > products[j]) {
                swap(products[i], products[j]);
                swap(arr[i], arr[j]);
            }
        }
    }
}

float carculateProductOfEvenElementsOfArray(float arr[], size_t n) {
    float product = 1;
    for (size_t i = 0; i < n; i+=2) product *= arr[i];
    return product;
}

void countAllZerosPositiveAndNegativeNumbersInNxMArrayAndPrintTheseAll(float **arr, size_t n, size_t m) {
    // Считаем положительные, отрицательные и нули
    int **result = createNxMArray<int>(m, 3);

    for (size_t j = 0; j < m; j++) {
        for (size_t i = 0; i < 3; i++) {
            result[j][i] = 0;
        }
        for (size_t i = 0; i < n; i++) {
            if (arr[i][j] < 0) result[j][1]++;
            else if (arr[i][j] > 0) result[j][0]++;
            else result[j][0]++;
        }
    }

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << result[j][i] << '\t'; 
        }
        cout << endl;
    } 
    deleteNxMArray(result, m, 3);
}

template<typename T> T** multiplyArrayToArray(T **vec1, size_t n1, size_t m1, T **vec2, size_t n2, size_t m2) {
    T **result = createNxMArray<T>(n1, m2);

    for (size_t i1 = 0; i1 < n1; i1++) {
        for (size_t j1 = 0; j1 < m2; j1++) {
            result[i1][j1] = 0;
            for (size_t i = 0; i < m1; i++) {
                result[i1][j1] += vec1[i1][i] * vec2[i][j1];
            }
        }
    }

    return result;
}

template<typename T> T* multiplyArrayToVector(T **arr, size_t n, size_t m, T vec[]) {
    T *result = new T[n];

    for (size_t i = 0; i < n; i++) {
        result[i] = 0;
        for (size_t j = 0; j < m; j++) {
            result[i] = arr[i][j] * vec[j];
        }
    }
    return result;
}