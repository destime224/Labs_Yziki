#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

void task1(unsigned n);
void task2(unsigned n);
void task3(unsigned n);
void task4(unsigned n);
void task5(unsigned n);
void task6(unsigned n);
void task7(unsigned n);
void task8(unsigned n);
void task9(unsigned n);
void task10(unsigned n);

int* createIntArray(unsigned length);
float* createFloatArray(unsigned length);
void printArrayInt(int array[], unsigned length);
void printArrayFloat(float array[], unsigned length);
int* createIntArrayFromInput(unsigned length);
float* createFloatArrayFromInput(unsigned length);
void floatSelectionSort(float array[], unsigned size);
bool isFloatEven(float number);
void intFastSort(int array[], unsigned size);
void helpIntFastSort(int array[], unsigned size, unsigned low, unsigned high);
unsigned partition(int array[], unsigned size, unsigned low, unsigned high);
int intBinarySearch(int array[], unsigned size, int key);
int helpIntBinarySearch(int array[], unsigned size, int key, unsigned first, unsigned last);
int LinealSearch(float array[], unsigned size, float element);
float multiplyElements(float array[], unsigned size);
int summarizeElementsAreBetweenFirstAndLastNegativeNumbers(int array[], unsigned size, bool &error);
void changeAllNonZeroElementsToRandomGeneratedNegativeNumbers(float array[], unsigned size);
void sortArrayFirstElementsAreEven(float array[], unsigned size);

int main() {
    srand(time(0));
    unsigned n;
    cout << "Введите размер массива: ";
    cin >> n;

    unsigned e;
    cout << "Введите номер задания: ";
    cin >> e;

    switch (e)
    {
    case 1:
        task1(n);
        break;
    case 2:
        task2(n);
        break;
    case 3:
        task3(n);
        break;
    case 4:
        task4(n);
        break;
    case 5:
        task5(n);
        break;
    case 6:
        task6(n);
        break;
    case 7:
        task7(n);
        break;
    case 8:
        task8(n);
        break;
    case 9:
        task9(n);
        break;
    case 10:
        task10(n);
        break;
    default:
        cout << "Задания под номером " << e << " не существует" << endl;
        exit(1);
    }
}

void task1(unsigned n) {
    int *array = createIntArray(n);
    printArrayInt(array, n);
    delete[] array;
}

void task2(unsigned n) {
    float *array = createFloatArray(n);
    printArrayFloat(array, n);
    delete[] array;
}

void task3(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    cout << multiplyElements(array, n);
    delete[] array;
}

float multiplyElements(float array[], unsigned size) {
    float M = 1;
    for (unsigned i = 0; i < size; i+=2)
        M *= array[i];
    return M; 
}

void task4(unsigned n) {
    int* array = createIntArrayFromInput(n);

    bool error;
    int summ = summarizeElementsAreBetweenFirstAndLastNegativeNumbers(array, n, error);
    if (!error)
        cout << summ << endl;
    else
        cout << "Найти сумму не удалось" << endl;
    
    delete[] array;
}

int summarizeElementsAreBetweenFirstAndLastNegativeNumbers(int array[], unsigned size, bool &error) {
    int first = -1;
    int last = -1;
    int S = 0;
    for (unsigned i = 0; i < size; i++)
        if (array[i] < 0)
            if (first == -1)
                first = i;
            else
                last = i;
    
    if (first == -1 || last == -1) {
        error = true;
        return 0;
    }
    
    for (unsigned i = first+1; i < last; i++) 
        S += array[i];

    error = false;
    return S;
}

void task5(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    changeAllNonZeroElementsToRandomGeneratedNegativeNumbers(array, n);
    printArrayFloat(array, n);
    delete[] array;
}

void changeAllNonZeroElementsToRandomGeneratedNegativeNumbers(float array[], unsigned size) {
    for (unsigned i = 0; i < size; i++) 
        if (abs(array[i]) < __FLT_EPSILON__)
            array[i] =  rand() % 100 - 99 + fmod((float)rand() / (float)rand(), 1);
}

void task6(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    float findEl;
    cout << "Введите элемент, который нужно найти: ";
    cin >> findEl;

    int i = LinealSearch(array, n, findEl);
    if (i != -1)
        cout << "Номер элемента: " << i << endl;
    else
        cout << "Элемент не найден" << endl;
    delete[] array;
}

int LinealSearch(float array[], unsigned size, float element) {
    for (unsigned i = 0; i < size; i++) 
        if (abs(array[i] - element) < __FLT_EPSILON__) {
            return i;
        }
    return -1;
}

void task7(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    floatSelectionSort(array, n);
    printArrayFloat(array, n);
    delete[] array;
}

void task8(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    sortArrayFirstElementsAreEven(array, n);
    printArrayFloat(array, n);
    delete[] array;
}

void sortArrayFirstElementsAreEven(float array[], unsigned size) {
    unsigned i = 0;
    unsigned j = size-1;

    for (unsigned k = 0; k < size/2; k++) {
        float el = array[k];
        if (isFloatEven(el)) {
            float buf = array[i];
            array[i] = el;
            array[k] = buf;
            i++;
        } else {
            float buf = array[j];
            array[j] = el;
            array[k] = buf;
            j--;
        }
    }
}

void task9(unsigned n) {
    int *array = createIntArrayFromInput(n);
    intFastSort(array, n);
    printArrayInt(array, n);
    delete[] array;
}

void task10(unsigned n) {
    int *array = createIntArrayFromInput(n);
    int key;
    cout << "Введите число, которое надо найти: ";
    cin >> key;
    intFastSort(array, n);
    int index = intBinarySearch(array, n, key);
    if (index != -1) {
        cout << "Индекс элемента: " << index << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    delete[] array;
}


int* createIntArray(unsigned length) {
    int *array = new int[length];
    for (unsigned i = 0; i < length; i++)
        array[i] = rand() % 200 - 100;
    return array;
}

float* createFloatArray(unsigned length) {
    float *array = new float[length];
    for (unsigned i = 0; i < length; i++)
        array[i] = rand() % 198 - 99 + fmod((float)rand() / (float)rand(), 1);
    return array;
}

void printArrayInt(int array[], unsigned length) {
    for (unsigned i = 0; i < length; i++)
        cout << "Элемент #" << i << " - " << array[i] << endl;
}

void printArrayFloat(float array[], unsigned length) {
    for (unsigned i = 0; i < length; i++)
        cout << "Элемент #" << i << " - " << array[i] << endl;
}

int* createIntArrayFromInput(unsigned length) {
    int *array = new int[length];

    for (unsigned i = 0; i < length; i++) {
        int el;
        cin >> el;
        array[i] = el;
    }
    return array;
}

float* createFloatArrayFromInput(unsigned length) {
    float *array = new float[length];

    for (unsigned i = 0; i < length; i++) {
        float el;
        cin >> el;
        array[i] = el;
    }
    return array;
}

void floatSelectionSort(float array[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        int min_index = i;
        for (unsigned j = i+1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            float buf = array[i];
            array[i] = array[min_index];
            array[min_index] = buf;
        }
    }
}

bool isFloatEven(float number) {
    return (int)number % 2 == 0;
}

void intFastSort(int array[], unsigned size) {
    helpIntFastSort(array, size, 0, size-1);
}

void helpIntFastSort(int array[], unsigned size, unsigned low, unsigned high) {
    if (low < high) {
        unsigned mid_index = partition(array, size, low, high);
        helpIntFastSort(array, size, low, mid_index);
        helpIntFastSort(array, size, mid_index+1, high);
    }
}

unsigned partition(int array[], unsigned size, unsigned low, unsigned high) {
        int pivot = array[(low + high)/2];
        unsigned i = low;
        unsigned j = high;
        while (1) {
            while (array[i] < pivot) i++;
            while (array[j] > pivot) j--;
            if (i >= j) return j;
            int buf = array[i];
            array[i] = array[j];
            array[j] = buf;
        }
}

int intBinarySearch(int array[], unsigned size, int key) {
    printArrayInt(array, size);
    return helpIntBinarySearch(array, size, key, 0, size-1);    
}

int helpIntBinarySearch(int array[], unsigned size, int key, unsigned first, unsigned last) {
    while (first <= last) {
        unsigned mid = (first + last)/2;
        int el = array[mid];
        if (key < el) last = mid-1;
        else if (key > el) first = mid+1;
        else return mid;
    }
    return -1;
}
