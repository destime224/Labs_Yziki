#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <ctime>
#include <map>
#include <set>

using namespace std;

/* Задание 1 */
class BaggageLocker {
    unsigned number;
    double length, width, height; 
    bool busy;
    string accessCode;
public:
    BaggageLocker() {
        number = 0;
        length = 1; width = 1; height = 1;
        busy = false;
        accessCode = "0000";
    }

    BaggageLocker(unsigned number, double length, double width, double height, string code) {
        this->number = number;
        if (length <= 0 || width <= 0 || height <= 0) throw invalid_argument("Any side cannot be negative");
        this->length = length; this->width = width; this->height = height;
        this->busy = false;
        if (!isAccessCodeValid(code)) throw invalid_argument("Access Code is not valid");
        accessCode = code;
    }

    BaggageLocker(BaggageLocker &locker) {
        BaggageLocker(locker.number, locker.length, locker.width, locker.height, locker.accessCode);
    }

    bool isAccessCodeValid(string code) {
        if (code.length() != 4) return false;
        bool r = true;
        for (auto s: code) {
            if (!isdigit(s)) r = false;
        }
        return r;
    }

    double getStorageSize() {
        return length * width * height;
    }

    bool getLockerBusy() {
        return busy;
    }

    void setLockerBusy() {
        busy = !busy;
    }

    void setLockerBusy(bool b) {
        busy = b;
    }

    bool canBaggageGetIntoLocker(double baggageLength, double baggageWidth, double baggageHeight) {
        double baggageSize[3] = {length, width, height};
        sort(baggageSize, baggageSize+3);
        double lockerSize[3] = {baggageLength, baggageWidth, baggageHeight};
        sort(lockerSize, lockerSize+3);

        if (
            baggageSize[0] <= lockerSize[0] && baggageSize[1] <= lockerSize[1] && baggageSize[2] <= lockerSize[2]
        ) return true;
        return false;
    }

    string toString() {
        ostringstream returnString;
        returnString << "Ящик №" << number << " (" << length << "x" << width << "x" << height << " " << (busy ? "Занят": "Не занят") << ")";
        return returnString.str();
    }
};

/* Задание 2 */
void createFile(const string fileName) {
    ofstream file(fileName);
    for (unsigned i = 0; i < 100; i++) {
        file << rand() % 101 - 50 << endl;
    }
    file.close();
}

vector<int> inputFile(const string fileName) {
    ifstream file(fileName);
    vector<int> returnVector;
    
    int i;
    while (file >> i) {
        returnVector.push_back(i);
    }
    file.close();
    return returnVector;
}

vector<int> modify(vector<int> &inputVector) {
    vector<int> returnVector;
    int minNumber = abs(*min_element(inputVector.begin(), inputVector.end()));
    int maxNumber = abs(*max_element(inputVector.begin(), inputVector.end()));
    for_each(inputVector.begin(), inputVector.end(), [&returnVector, &minNumber, &maxNumber](int i) {returnVector.push_back(i+(minNumber+maxNumber)/2);});
    return returnVector;
}

void addSumAndAverageValueIntoVector(vector<int> &vec) {
    int sum = 0;
    int absSum = 0;
    for_each(vec.begin(), vec.end(), [&sum, &absSum](int i) {sum += i; absSum += abs(i);});
    int average = absSum / vec.size();
    vec.push_back(sum);
    vec.push_back(average);
}

/* Задание 3 */
const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
void functionThatDoesShitOfTask3(const string &str) {
    map<char, unsigned> charCount;
    stringstream stream;
    for (char c: str) stream << static_cast<char>(tolower(c));
    string uniqueVowels;

    string word;
    while (stream >> word) {
        for (char c: word) {
            if (!isalpha(c)) continue;

            bool isVowel = false;
            for (const char &v: vowels) {
                if (v == c) {
                    isVowel = true;
                    break;
                }
            }

            if (isVowel) {
                bool isUnique = false;
                for (char &v: uniqueVowels) {
                    if (v == c) {
                        isUnique = true;
                        break;
                    }
                }
                if (!isUnique) uniqueVowels.append(1, c);
            } else
                charCount[c]++;
            
        }

        for (char c: uniqueVowels) charCount[c]++;
    }

    cout << "Согласные буквы, которые встречаются только один раз: ";
    for (const auto &pair: charCount) {
        bool isVowel = false;
        for (const char &v: vowels) 
            if (pair.first == v) {
                isVowel = true;
                break;
            }
        if (!isVowel && pair.second == 1)
            cout << pair.first << ", ";
    }

    cout << endl << "Гласные буквы, которые не входят только в одно слово: ";
    for (const char &v: vowels)
        if (charCount[v] != 1)
            cout << v << ", ";
    cout << endl;
}

/* Задание 4 */
void anotherFunctionThatUselessButNeededForCompletingTask4(
    const set<string> &allTrees,
    const set<string> &yard1,
    const set<string> &yard2,
    const set<string> &yard3
) {
    cout << "Деревья, которые культивируют хотя бы на одном участке: ";
    for (const string &tree: allTrees) {
        if (yard1.count(tree) || yard2.count(tree) || yard3.count(tree))
            cout << tree << ", ";
    }

    cout << endl << "Деревья, которые растут на каждом участке: ";
    for (const string &tree: allTrees) {
        if (yard1.count(tree) && yard2.count(tree) && yard3.count(tree))
            cout << tree << ", ";
    }

    cout << endl << "Деревья, которые не выращиваются ни на одном участке: ";
    for (const string &tree: allTrees) {
        if (!yard1.count(tree) && !yard2.count(tree) && !yard3.count(tree))
            cout << tree << ", ";
    }
}

int main() {
    /* Задание 2 */
    createFile("input.txt");
    auto v = inputFile("input.txt");
    auto rv = modify(v);
    addSumAndAverageValueIntoVector(rv);

    for (int &i: rv) {
        cout << i << endl;
    }

    /* Задание 3 */
    functionThatDoesShitOfTask3("one Two, Three ?Four");
    
    cout << endl;
    /* Задание 4 */
    const set<string> allTrees = {"Яблоня", "Груша", "Апельсиновое дерево", "Мандариновое дерево", "Финиковое дерево"};
    const set<string> yard1 = {"Яблоня", "Апельсиновое дерево"};
    const set<string> yard2 = {"Груша", "Апельсиновое дерево"};
    const set<string> yard3 = {"Финиковое дерево", "Апельсиновое дерево"};
    anotherFunctionThatUselessButNeededForCompletingTask4(allTrees, yard1, yard2, yard3);
}