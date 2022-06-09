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

bool isEmpty()
{
    ifstream file;
    file.open("info.txt");
    bool isEmpty = (file.peek() == std::ifstream::traits_type::eof());
    file.close();
    return isEmpty;
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
    int exceptionThrown = 0;
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
            try {
            switch (enc)
            {
            case 1:
                if (getKey("KeyD: ", 5) == "") throw ("EMPTY_INFO_FILE");
                antiGronsfeld();
                break;
            case 2:
                if ((!isEmpty()) && (getKey("Capital characters: ", 20) == "")) throw ("EMPTY_INFO_FILE");
                antiPolybiusSquare();
                break;
            case 3:
                if (getKey("Columns: ", 9) == "") throw ("EMPTY_INFO_FILE");
                antiSTP();
                break;
            case 4:
                antiatbash();
                break;
            case 5:
                if (getKey("Key: ", 5) == "") throw ("EMPTY_INFO_FILE");
                antikeywordABC();
                break;
            case 6:
                if (getKey("Key: ", 5) == "") throw ("EMPTY_INFO_FILE");
                antitableCypher();
                break;
            case 7:
                if (getKey("KeyD: ", 5) == "") throw ("EMPTY_INFO_FILE");
                antiCaesar();
                break;
            case 8:
                if (getKey("Key 1: ", 7) == "") throw ("EMPTY_INFO_FILE");
                antiDoubleTable();
                break;
            case 9:
                antiTarab();
                break;
            }
            }
            catch (...)
            {
                cout << "    [ERROR] Couldn't find keys for choosen decryption! Possible reasons are: " << endl <<
                    "1) You're trying to use decryption on an empty text file" << endl << 
                    "2) You're trying to use key-based decryption for a text that was encrypted without a key" << endl <<
                    "3) You're trying to decrypt message using wrong decryption" << endl <<
                    "Note that using wrong decryption on your encrypted text may cause unexpected results!" << endl << endl;
                exceptionThrown = 1;
            }
        }
        if (exceptionThrown == 0)
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
