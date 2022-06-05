#include <iostream>
#include <fstream>
#include <string>
#include "interface.h"

using namespace std;

void inFile(const string& inStr) { // функция записи строки в файл
    ofstream file;
    file.open("input.txt"); // открыть файл
    file << inStr << endl; // запись строки в файл
    file.close(); // закрыть файл
}

void outFile(const string& inStr) { // функция записи строки в файл
    ofstream file;
    file.open("info.txt"); // открыть файл
    file << inStr << endl; // запись строки в файл
    file.close(); // закрыть файл
}

void clearFile() { // функция очистки файла
    ofstream file;
    file.open("input.txt"); // открыть файл (тем самым обнулить)
    file.close(); // закрыть файл
}

void getFile() { // функция получения содержимого файла
    ifstream file;
    string str;
    file.open("input.txt"); // открыть файл для чтения
    while (getline(file, str)) { // пока в файле есть строки: вывести строки
        cout << str << endl;
    }
    file.close(); // закрыть файл
}

string getString(const string& mark, int pos_n) { // функция получения фразы из файла
    ifstream file;
    string line, str_out;
    file.open("input.txt"); // открыть файл
    while (getline(file, line)) { // пока в файле есть строки
        int checkMark = line.find(mark);
        if (checkMark > -1) {
            str_out = line.substr(
                    pos_n); // если строка содержит метку, в переменную phrase записать содержимое строки из файла после этой метки
            break;
        }
    }
    file.close(); // закрыть файл
    return str_out; // вывести фразу
}

string getKey(const string& mark, int pos_n) { // функция получения фразы из файла
    ifstream file;
    string line, str_out;
    file.open("info.txt"); // открыть файл
    while (getline(file, line)) { // пока в файле есть строки
        int checkMark = line.find(mark);
        if (checkMark > -1) {
            str_out = line.substr(
                    pos_n); // если строка содержит метку, в переменную phrase записать содержимое строки из файла после этой метки
            break;
        }
    }
    file.close(); // закрыть файл
    return str_out; // вывести фразу
}

bool checkString(const string& mark) {
    ifstream file;
    string line;
    file.open("input.txt"); // открыть файл
    while (getline(file, line)) { // пока в файле есть строки
        if (line.find(mark) >= 0) {
            return true;
            break;
        }
    }
    return false;
}

bool checkPincode(const string& pinUser, const string& pinAdmin) { // функция проверки пинкода
    return (pinUser == pinAdmin);
}