#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <regex>

void task1();
void task2();
void task3();
void task4();

using namespace std;

void getFirstLetterFromStr(char str[], char buffer[3]) {
    buffer[0] = str[0];
    buffer[1] = '.';
    buffer[2] = '\0';
}

void scrapFIOFromStr(char str[], char init[]) {
    char nameBuffer[3];
    char thirdNameBuffer[3];

    char *token = strtok(str, " ");
    strcpy(init, token);
    strcat(init, " ");

    token = strtok(NULL, " ");
    getFirstLetterFromStr(token, nameBuffer);

    token = strtok(NULL, " ");
    getFirstLetterFromStr(token, thirdNameBuffer);

    strcat(init, nameBuffer);
    strcat(init, " ");
    strcat(init, thirdNameBuffer);
}

void removeSpacesInStr(char str[], char buffer[]) {
    char *token = strtok(str, " .,:;-'\"\n\t!@#$%^&?/\\\r*");
    strcpy(buffer, "\0");
    while (token != NULL) {
        strcat(buffer, token);
        token = strtok(NULL, " .,:;-'\"\n\t!@#$%^&?/\\\r*");
    }
}

bool isStrPalindrome(char str[]) {
    char newPalindrome[81];
    removeSpacesInStr(str, newPalindrome);
    strlwr(newPalindrome);

    size_t len = strlen(newPalindrome);
    bool isPalendrome = true;
    for (unsigned i = 0; i < len/2; i++) {
        if (newPalindrome[i] != newPalindrome[len-1-i]) {
            isPalendrome = false;
        }
    }
    return isPalendrome;
}

unsigned getAllWordsFromText(string &textPath, string words[10000]) {
    ifstream text(textPath);

    string word;
    unsigned size = 0;
    regex punctuation("[^a-zA-Z0-9]");
    while (text >> word) {
        word = regex_replace(word, punctuation, "");
        if (word != "") {
            for (unsigned i = 0; i < word.length(); i++) {
                word[i] = tolower(word[i]);
            }

            bool uniqueWord = true;
            for (unsigned i = 0; i < size; i++) {
                if (word == words[i]) {
                    uniqueWord = false;
                    break;
                }
            }

            if (uniqueWord) {
                words[size++] = word;
            }
        }
    }
    text.close();
    
    return size;
}

void outWordsToFile(string &dictionaryPath, string words[10000], unsigned size) {
    ofstream dictionary(dictionaryPath);

    for (unsigned i = 0; i < size; i++) {
        dictionary << words[i] << endl;
    }
}

void task4_regex(string &filePath) {
    ifstream file(filePath);
    regex even_number(R"(-?\d*[02468])");
    regex punctuation("[^a-zA-Z0-9]");

    string word;
    while (file >> word) {
        word = regex_replace(word, punctuation, "");
        if (regex_match(word, even_number))
            cout << word << endl;
    }
}

void task4_no_regex(string &filePath) {
    ifstream file(filePath);

    string word;
    string punctuation = ".,;:!?";
    while (file >> word) {
        for (unsigned i = 0; i < punctuation.length(); i++) {
            if (word[word.length()-1] == punctuation[i]) {
                word.pop_back();
                break;
            }
        }

        unsigned short number_start = 0;
        if (word[0] == '-')
            number_start = 1;
        bool isNumber = true;
        for (unsigned i = number_start; i < word.length(); i++) {
            if (!isdigit(word[i]))
                isNumber = false;
        }

        if (isNumber & (((unsigned short)word[word.length()-1]) % 2 == 0))
            cout << word << endl; 
    }
}

int main() {
    unsigned n;
    cout << "Введите номер задания: ";
    cin >> n;
    cin.ignore(256, '\n');
    switch (n) {
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
    }
}

void task1() {
    char fio[81];
    cin.getline(fio, 80);

    char initials[81];
    scrapFIOFromStr(fio, initials);

    cout << initials;
}

void task2() {
    char palindrome[81];
    cin.getline(palindrome, 80);

    bool isPalendrome = isStrPalindrome(palindrome);
    if (isPalendrome) {
        cout << "Слово является палендромом" << endl;
    } else {
        cout << "Слово не является палендромом" << endl;
    }
}

void task3() {
    string textPath = "text.txt";
    string dictionaryPath = "dictionary.txt";
    string words[10000];

    auto wordsSize = getAllWordsFromText(textPath, words);
    sort(words, words + wordsSize);
    outWordsToFile(dictionaryPath, words, wordsSize);
}

void task4() {
    string testFilePath = "test1.txt";

    cout << "=== С использованием regex ===" << endl;
    task4_regex(testFilePath);
    cout << "=== Без использования regex ===" << endl;
    task4_no_regex(testFilePath);
}