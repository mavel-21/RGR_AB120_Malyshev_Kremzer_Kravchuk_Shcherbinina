#include <iostream>
#include <fstream>
#include <string>
#include "interface.h"
#include "gronsfeld.h"
#include "polybiusSquare.h"
#include "simpleTablePermutation.h"
#include "atbash.h"
#include "keywordABC.h"
#include "tableCypher.h"
#include "Caesar.h"
#include "doubleTable.h"
#include "tarab.h"

using namespace std;

void inFile(const string& inStr) { // функция записи строки в файл
    ofstream file;
    file.open("input.txt"); // открыть файл
    file << inStr << endl; // запись строки в файл
    file.close(); // закрыть файл
}

void cipherExec(int enc, int mode, string pinAdmin)
{
    switch (enc)
    {
    case 1:
        cout << endl << "    [Gronsfeld]" << endl << endl;
        break;
    case 2:
        cout << endl << "    [Polybius square]" << endl << endl;
        break;
    case 3:
        cout << endl << "    [Simple table permutation]" << endl << endl;
        break;
    case 4:
        cout << endl << "    [Atbash cipher]" << endl << endl;
        break;
    case 5:
        cout << endl << "    [Keyword cipher]" << endl << endl;
        break;
    case 6:
        cout << endl << "    [Table cipher with a keyword]" << endl << endl;
        break;
    case 7:
        cout << endl << "    [Caesar]" << endl << endl;
        break;
    case 8:
        cout << endl << "    [Double table permutation]" << endl << endl;
        break;
    case 9:
        cout << endl << "    ['Tarabarskaya gramota']" << endl << endl;
        break;
    }
    string pinUser;
    cout << "Please enter the pincode: ";
    getline(cin, pinUser); // ввод пинкода
    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
        cout << "    [Pincode validation passed successfully!]" << endl;
        if (mode == 1)
        {
            switch (enc)
            {
            case 1:
                Gronsfeld();
                break;
            case 2:
                square();
                PolybiusSquare();
                break;
            case 3:
                STP();
                break;
            case 4:
                atbash();
                break;
            case 5:
                keywordABC();
                break;
            case 6:
                tableCypher();
                break;
            case 7:
                Caesar();
                break;
            case 8:
                DoubleTable();
                break;
            case 9:
                Tarab();
                break;
            }
        }
        else if (mode == 2)
        {
            switch (enc)
            {
            case 1:
                antiGronsfeld();
                break;
            case 2:
                antiPolybiusSquare();
                break;
            case 3:
                antiSTP();
                break;
            case 4:
                antiatbash();
                break;
            case 5:
                antikeywordABC();
                break;
            case 6:
                antitableCypher();
                break;
            case 7:
                antiCaesar();
                break;
            case 8:
                antiDoubleTable();
                break;
            case 9:
                antiTarab();
                break;
            }
        }
        system("notepad.exe input.txt");
    }
    else cout << "    [Pincode is not correct!]" << endl;
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
