#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <regex>
#include <cstring>
#include <algorithm>

using namespace std;

void task1();
void task2();

static char timeString[] = "%Y %d %B";

struct money {
    unsigned rub, kop;

    bool Init(unsigned rub, unsigned kop) {
        if (kop > 99) {
            return false;
        }
        return true;
    }

    void Read() {
        unsigned r, k;
        do {
            cin >> r >> k;
        } while(!Init(r, k));
        rub = r; kop = k;
    }

    void Display() {
        cout << rub << ' ';

        unsigned short rubLast2Digits = rub % 100;
        unsigned short rubLastSecondDigit = rubLast2Digits / 10;
        unsigned short rubLastDigit = rubLast2Digits % 10;
        if (rubLastSecondDigit != 1) {
            switch (rubLastDigit) {
                case 1:
                    cout << "рубль";
                    break;
                case 2:
                case 3:
                case 4:
                    cout << "рубля";
                    break;
                default:
                    cout << "рублей";
                    break;
            }
        } else {
            cout << "рублей";
        }
        cout << ", " << kop << ' ';

        unsigned short kopLast2Digits = kop % 100;
        unsigned short kopLastSecondDigit = kopLast2Digits / 10;
        unsigned short kopLastDigit = kopLast2Digits % 10;
        if (kopLastSecondDigit != 1) {
            switch (kopLastDigit) {
                case 1:
                    cout << "копейка";
                    break;
                case 2:
                case 3:
                case 4:
                    cout << "копейки";
                    break;
                default:
                    cout << "копеек";
                    break;
            }
        } else {
            cout << "копеек";
        }
        cout << endl;
    }
};

unsigned long moneyToKop(money M) {
    return M.rub * 100 + M.kop;
}

struct PublicService {
    enum ServiceType {Rent, Gas, Water, Electricity};

    unsigned houseNumber, apartmentNumber;
    string ownerSecondName;
    ServiceType serviceType;
    time_t paymentDate;
    double paymentAmount;
    float percentageOfPenalty;
    int paymentOverdue;

    void display() {
        char date[256];
        strftime(date, sizeof(date), timeString, localtime(&paymentDate));
        cout << "\tНомер дома: " << houseNumber << "\n\tНомер квартиры: " \
            << apartmentNumber << "\n\tФамилия жильца: " << ownerSecondName \
            << "\n\tТип платежа: " << getServiceTypeAsString() << "\n\tДата платежа: " \
            << date << "\n\tПени: " << percentageOfPenalty << "\n\tПросрочено дней: " << paymentOverdue << endl;
    }

    string getServiceTypeAsString() {
        switch (serviceType) {
            case ServiceType::Rent:
                return "Аренда";
            case ServiceType::Gas:
                return "Газ";
            case ServiceType::Water:
                return "Вода";
            case ServiceType::Electricity:
                return "Электричество";
        }
        return "";
    }
};

unsigned getInteredNumber() {
    unsigned i;
    cout << "Введите число: ";
    cin >> i;
    return i;
}

size_t getPublicServicesFromTextFile(string &path, PublicService *&dynamicArray) {
    ifstream file(path);
    size_t lines;
    file >> lines;

    dynamicArray = new PublicService[lines];
    for (size_t i = 0; i < lines; i++) {
        PublicService s;
        unsigned short e;
        string date;
        file >> s.houseNumber >> s.apartmentNumber >> s.ownerSecondName >> e >> date >> s.paymentAmount >> s.percentageOfPenalty >> s.paymentOverdue;
        s.serviceType = PublicService::ServiceType(e);

        unsigned year = stoi(date.substr(0, 4));
        unsigned day = stoi(date.substr(5, 2));
        unsigned month = stoi(date.substr(8, 2));
        tm timeStruct;
        timeStruct.tm_sec = 0;
        timeStruct.tm_min = 0;
        timeStruct.tm_hour = 0;
        timeStruct.tm_mday = day;
        timeStruct.tm_mon = month-1;
        timeStruct.tm_year = year-1900;
        s.paymentDate = mktime(&timeStruct);
        dynamicArray[i] = s;
    }
    file.close();
    return lines;
}

void printPublicServices(PublicService array[], size_t arraySize) {
    for (size_t i = 0; i < arraySize; i++) {
        cout << "Запись №" << i+1 << endl;
        array[i].display();
    }
}

void printPublicServicesWithGivenHouseNumber(PublicService array[], size_t arraySize, unsigned houseNumber) {
    for (size_t i = 0; i < arraySize; i++) {
        PublicService *ps = &array[i];
        if (ps->houseNumber == houseNumber) {
            cout << "Запись №" << i+1 << endl;
            array[i].display();
        }
    }
}

void printPublicServicesWithGivenServiceType(PublicService array[], size_t arraySize, PublicService::ServiceType st) {
    for (size_t i = 0; i < arraySize; i++) {
        PublicService *ps = &array[i];
        if (ps->serviceType == st) {
            cout << "Запись №" << i+1 << endl;
            array[i].display();
        }
    }
}

void printPublicServicesWithGivenDate(PublicService array[], size_t arraySize, unsigned year, unsigned day, unsigned month) {
    for (size_t i = 0; i < arraySize; i++) {
        PublicService *ps = &array[i];
        auto t = ps->paymentDate;
        tm *tm_ = localtime(&t);
        if (tm_->tm_year + 1900 == year && tm_->tm_mon+1 == month && tm_->tm_mday == day) {
            cout << "Запись №" << i+1 << endl;
            array[i].display();
        }
    }
}

void printSortedPublicServicesArray(PublicService array[], size_t arraySize, bool (*sortFunc)(PublicService*, PublicService*)) {
    PublicService **sortedArray = new PublicService*[arraySize];
    for (size_t i = 0; i < arraySize; i++)
        sortedArray[i] = &array[i];

    sort(sortedArray, sortedArray+arraySize, sortFunc);
    for (size_t i = 0; i < arraySize; i++) {
        cout << "Запись №" << i+1 << endl;
        sortedArray[i]->display();
    }

    delete[] sortedArray;
}

void printInteredNumberIsWrong() {
    cout << "Неверно введено число.\n" << endl;
}

int main() {
    unsigned n;
    cout << "Введите номер задания: ";
    cin >> n;
    switch (n) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
    }
}

void task1() {
    money M;
    M.Read();
    M.Display();
    cout << "В копейках это будет " << moneyToKop(M) << endl;
}

void task2() {
    enum MenuStatus {Exit, Root, PrintAll, Sort, Find};
    cout << "Импорт данных из файла..." << endl;
    string psPath = "public-services.txt";
    PublicService *psArray = nullptr;
    auto psArraySize = getPublicServicesFromTextFile(psPath, psArray);
    cout << "Импорт завершён." << endl;

    MenuStatus menu = Root;
    while (menu != MenuStatus::Exit) {
        switch (menu) {
            case MenuStatus::Root: {
                cout << "Возможные действия:\n\t1. Печать записей\n\t2. Поиск записей\n\t3. Сортировка записей\n\t4. Выход\n" << endl;
                auto i = getInteredNumber();

                switch(i) {
                    case 1:
                        menu = PrintAll;
                        break;
                    case 2:
                        menu = Find;
                        break;
                    case 3:
                        menu = Sort;
                        break;
                    case 4:
                        menu = Exit;
                        break;
                    default:
                        printInteredNumberIsWrong();
                        break; 
                }
            }break;
            case MenuStatus::PrintAll: {
                cout << endl;
                printPublicServices(psArray, psArraySize);
                menu = Root;

                cin.ignore(100, '\n');
                cin.get();
            }break;
            case MenuStatus::Find: {
                cout << "Типы поиска:\n\t1. Номер дома\n\t2. Вид платежа\n\t3. Дата\n" << endl;
                auto i = getInteredNumber();

                menu = Root;
                switch (i) {
                    case 1: {
                        unsigned j;
                        cout << "Введите номер дома: ";
                        cin >> j;
                        cout << endl;
                        printPublicServicesWithGivenHouseNumber(psArray, psArraySize, j);
                    }break;
                    case 2: {
                        unsigned j;
                        cout << "Введите вид платежа(0 - Аренда, 1 - Газ, 2 - Вода, 3 - Электричество): ";
                        cin >> j;
                        auto st = PublicService::ServiceType(j);
                        printPublicServicesWithGivenServiceType(psArray, psArraySize, st);
                    }break;
                    case 3: {
                        string date;
                        cout << "Введите дату (YYYY/DD/MM): ";
                        cin >> date;
                        unsigned year = stoi(date.substr(0, 4));
                        unsigned day = stoi(date.substr(5, 2));
                        unsigned month = stoi(date.substr(8, 2));
                        printPublicServicesWithGivenDate(psArray, psArraySize, year, day, month);
                    }break;
                    default:
                        cout << "Неверное значение. Введите любое значение для возрата..." << endl;
                        break;
                }

                cin.ignore(100, '\n');
                cin.get();
            }break;
            case MenuStatus::Sort: {
                cout << "Типы сортировки:\n\t1. Номер дома\n\t2. Вид платежа\n\t3. Дата\n" << endl;
                auto i = getInteredNumber();

                menu = Root;
                switch (i) {
                    case 1: {
                        cout << endl;
                        printSortedPublicServicesArray(psArray, psArraySize, [](PublicService *a, PublicService *b){return a->houseNumber < b->houseNumber;});
                    }break;
                    case 2: {
                        cout << endl;
                        printSortedPublicServicesArray(psArray, psArraySize, [](PublicService *a, PublicService *b){return a->serviceType < b->serviceType;});
                    }break;
                    case 3: {
                        cout << endl;
                        printSortedPublicServicesArray(psArray, psArraySize, [](PublicService *a, PublicService *b){return a->paymentDate < b->paymentDate;});
                    }break;
                    default:
                        cout << "Неверное значение. Введите любое значение для возрата..." << endl;
                        break;
                }

                cin.ignore(100, '\n');
                cin.get();
            }break;
        }
    }
    delete[] psArray;
}