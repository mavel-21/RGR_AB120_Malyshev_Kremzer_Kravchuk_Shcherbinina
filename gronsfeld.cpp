#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "gronsfeld.h"
#include "interface.h"

using namespace std;

void Gronsfeld() { // шифровка Гронсфельда
    string key; // ключ
    string strIn = getString("Phrase: ", 8); // входная строка
    int isValid = 1;
    do {
        isValid = 1;
        cout << "Enter key (digits only): ";
        try {
            getline(cin, key);
            key.erase(find(key.begin(), key.end(), ' '), key.end());
            for (auto elem: key) {
                if (!isdigit(elem)) {
                    isValid = 0;
                    throw ("KEY_NOT_VALID");
                }
            }
        }
        catch (...) {
            cout << "    [INCORRECT INPUT]" << endl;
        }
    } while (isValid == 0);
    outFile("Key: " + key);
    string strOut; // выходная строка
    vector<int> keyArr(key.length());
    for (int i = 0; i < key.length(); i++) {
        keyArr[i] = key[i] - '0';
    }

    for (int i = 0, count = 0; i < strIn.length(); i++, count++) {
        if (count == key.length()) count = 0; // сброс счётчика ключа
        if (strIn[i] == ' ') { // учёт пробелов в строке
            strOut.push_back(' ');
            count--;
            continue;
        } else {
            if (!isalpha(strIn[i])) {
                strOut.push_back(strIn[i]);
                continue;
            }
            char c;
            if (strIn[i] >= 'a' and strIn[i] <= 'z' and strIn[i] + keyArr[count] > 'z')
                c = strIn[i] + keyArr[count] - ('z' - 'a' +
                                                1); // устранение бага появления неподходящих символов (десятичный код которых больший 122)
            else if (strIn[i] >= 'A' and strIn[i] <= 'Z' and strIn[i] + keyArr[count] > 'Z')
                c = strIn[i] + keyArr[count] - ('Z' - 'A' +
                                                1); // устранение бага появления неподходящих символов (десятичный код которых больший 90 и меньший 97)
            else c = strIn[i] + keyArr[count];
            strOut.push_back(c); // добавление шифрованного символа в строку
        }
    }
    inFile("Phrase: " + strOut); // запись строки в файл
}

void antiGronsfeld() {
    string key_str = getKey("Key: ", 5);
    vector<int> keyArr(key_str.length());
    for (int i = 0; i < key_str.length(); i++) {
        keyArr[i] = key_str[i] - '0';
    }
    string strIn = getString("Phrase: ", 8); // входная строка
    string strOut; // выходная строка
    for (int i = 0, count = 0; i < strIn.length(); i++, count++) {
        if (count == key_str.length()) count = 0; // сброс счётчика ключа
        if (strIn[i] == ' ') { // учёт пробелов в строке
            strOut.push_back(' ');
            count--;
            continue;
        } else {
            if (!isalpha(strIn[i])) {
                strOut.push_back(strIn[i]);
                continue;
            }
            char c;
            if (strIn[i] >= 'a' and strIn[i] <= 'z' and strIn[i] - keyArr[count] < 'a')
                c = strIn[i] - keyArr[count] + ('z' - 'a' +
                                                1); // устранение бага появления неподходящих символов (десятичный код которых больший 122)
            else if (strIn[i] >= 'A' and strIn[i] <= 'Z' and strIn[i] + keyArr[count] < 'A')
                c = strIn[i] - keyArr[count] + ('Z' - 'A' +
                                                1); // устранение бага появления неподходящих символов (десятичный код которых больший 90 и меньший 97)
            else c = strIn[i] - keyArr[count];
            strOut.push_back(c); // добавление шифрованного символа в строку
        }
    }
    inFile("Phrase: " + strOut); // запись строки в файл
}