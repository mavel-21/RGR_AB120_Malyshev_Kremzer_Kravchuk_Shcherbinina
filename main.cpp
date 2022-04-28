// Малышев Павел

// Группа: АБ-120

// Шифровки:
//     1. Шифр Гронсфельда (5.7)
//     2. Шифровка с помощью квадрата Полибия (5.8)
//     3. Простая табличная перестановка (5.16)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool checkPincode(string pinUser, string pinAdmin);

bool checkString(string mark);

void inFile(string inStr);

void clearFile();

void getFile();

string getString(string mark, int pos_n);

void Gronsfeld() { // шифровка Гронсфельда
    string key; // ключ
    string strIn = getString("Phrase: ", 8); // входная строка
    cout << "Enter key: ";
    getline(cin, key);
    inFile("Key: " + key); // получение и запись ключа в файл
    string strOut; // выходная строка
    int keyArr[key.length()];
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
    inFile("Gronsfeld: " + strOut); // запись строки в файл
}

void antiGronsfeld() {
        string key_str = getString("Key: ", 5);
        int keyArr[key_str.length()];
        for (int i = 0; i < key_str.length(); i++) {
            keyArr[i] = key_str[i] - '0';
        }
        string strIn = getString("Gronsfeld: ", 11); // входная строка
        string strOut; // выходная строка
        for (int i = 0, count = 0; i < strIn.length(); i++, count++) {
            if (count == key_str.length()) count = 0; // сброс счётчика ключа
            if (strIn[i] == ' ') { // учёт пробелов в строке
                strOut.push_back(' ');
                count--;
                continue;
            } else {
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
        inFile("Decryption: " + strOut); // запись строки в файл
}

int main() {
    string dialogStr; // диалоговая строка
    string pinAdmin = "0000"; // дефолтный пинкод
    cout << endl << "______________________________Hello______________________________" << endl <<
         "__________To display a list of all commands write: help__________" << endl <<
         "____Set a password, enter a passphrase, and choose encryption____" << endl << endl;
    while (true) {
        cout << "Enter a command: ";
        getline(cin, dialogStr); // ввод команды
        if (dialogStr == "input") { // команда ввода фразы в файл
            string str; // строка
            cout << "Enter a string: ";
            getline(cin, str); // ввод строки (фразы)
            inFile("Phrase: " + str); //запись этой строки (фразы) в файл
            cout << "    [THE FILE HAS BEEN UPDATED]" << endl << endl;
        } else if (dialogStr == "pin") { // команда ввода пинкода
            cout << "Enter pinAdmin: ";
            getline(cin, pinAdmin); // ввод пинкода
            cout << "    [PINCODE SET]" << endl << endl;
        } else if (dialogStr == "clear") { // команда очистки файла
            clearFile(); // обращение к функции очистки файла
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        } else if (dialogStr == "get") { // команда получения содержимого файла
            cout << "    [FILE CONTENTS]" << endl;
            getFile(); // обращение к функции получения содержимого файла
            cout << endl;
        } else if (dialogStr == "cipher") {
            string cipher_str;
            int cipher;
            cout
                    << "\t1. Gronsfeld cipher\n\t2. Encryption using the square of Polybius\n\t3. Simple table permutation\n\tAny other character: go back\nChoose encryption (1-3): ";
            getline(cin, cipher_str);
            if (cipher_str == "1" or cipher_str == "2" or cipher_str == "3") cipher = cipher_str[0] - '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            switch (cipher) {
                case 1: // шифровка Гронсфельда
                {
                    cout << endl << "    [Gronsfeld cipher]" << endl << endl;
                    if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                        cout << "    [Pincode not set!]" << endl;
                        break;
                    }
                    string pinUser; // пинкод
                    cout << "Please enter the pincode: ";
                    getline(cin, pinUser); // ввод пинкода
                    if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                        cout << "    [Pincode validation passed successfully!]" << endl;
                        Gronsfeld();
                    } else cout << "    [Pincode is not correct!]" << endl;
                    break;
                }
                case 2:
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        }
        else if (dialogStr == "decrypt") {
            if (checkString("Gronsfeld: ")) antiGronsfeld();
        }
        else if (dialogStr == "help") { // команда вызова списка команд
            cout << "    [COMMANDS]" << endl;
            cout << "input -- Writing a line to a file;" << endl;
            cout << "get -- Displaying the contents of a file;" << endl;
            cout << "clear -- Cleaning up the contents of a file;" << endl;
            cout << "pin -- Pincode setting;" << endl;
            cout << "cipher -- Choice of encryption" << endl;
            cout << "stop -- Stop program;" << endl << endl;

        } else if (dialogStr == "stop") { // остановка программы
            cout << "    [The program has been stopped]" << endl;
            break;
        } else { // команды не существует
            cout << endl << "[ERROR_217][THIS COMMAND DOES NOT EXIST][ERROR_217]" << endl << endl;
        }
    }
    return 0;
}

void inFile(string inStr) { // функция записи строки в файл
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt", ofstream::app); // открыть файл
    file << inStr << endl; // запись строки в файл
    file.close(); // закрыть файл
}

void clearFile() { // функция очистки файла
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt"); // открыть файл (тем самым обнулить)
    file.close(); // закрыть файл
}

void getFile() { // функция получения содержимого файла
    ifstream file;
    string str;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt"); // открыть файл для чтения
    while (getline(file, str)) { // пока в файле есть строки: вывести строки
        cout << str << endl;
    }
    file.close(); // закрыть файл
}

string getString(string mark, int pos_n) { // функция получения фразы из файла
    ifstream file;
    string line, str_out;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt"); // открыть файл
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

bool checkString(string mark) {
    ifstream file;
    string line;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt"); // открыть файл
    while (getline(file, line)) { // пока в файле есть строки
        if (line.find(mark) >= 0) {
            return true;
            break;
        }
    }
    return false;
}

bool checkPincode(string pinUser, string pinAdmin) { // функция проверки пинкода
    return (pinUser == pinAdmin);
}