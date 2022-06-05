﻿#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

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
    int isValid = 1;
    do
    {
        isValid = 1;
        cout << "Enter key (digits only): ";
        try {
            getline(cin, key);
            key.erase(find(key.begin(), key.end(), ' '), key.end());
            for (auto elem : key)
            {
                if (!isdigit(elem))
                {
                    isValid = 0;
                    throw("KEY_NOT_VALID");
                }
            }
        }
        catch (...)
        {
            cout << "    [INCORRECT INPUT]" << endl;
        }
    } while (isValid == 0);
    inFile("Key: " + key); // получение и запись ключа в файл
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
        }
        else {
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
    vector<int> keyArr(key_str.length());
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
        }
        else {
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

int sameLetters(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        for (int j = 0; j < word.length(); j++)
        {
            if (i != j && word[i] == word[j])
                return 1;
        }
    }
    return 0;
}

int isKeyValid(string word)
{
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (char elem : word)
    {
        if (find(abc.begin(), abc.end(), elem) == abc.end())
            return 0;
        return 1;
    }
}

string getKey()
{
    setlocale(LC_ALL, "Russian");
    string keyword;
    do
    {
        try {
            cout << "Enter a key (non-repetative latin letters only): ";
            getline(cin, keyword);
            keyword.erase(find(keyword.begin(), keyword.end(), ' '), keyword.end());
            if (sameLetters(keyword) != 0)
                throw("KEY_SAME_LETTERS");
            if (isKeyValid(keyword) == 0)
                throw("KEY_NOT_VALID");
        }
        catch (...)
        {
            cout << "    [INCORRECT INPUT]" << endl;
        }
    } while ((sameLetters(keyword) != 0) || (isKeyValid(keyword) == 0));
    return keyword;
}

void atbash()
{
    string line = getString("Phrase: ", 8);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++)
    {
        if (isalpha(line[i]))
        {
            if (isupper(line[i]))
            {
                ind = int(line[i]) - 65;
                line[i] = cab[ind];
            }
            else
            {
                ind = int(line[i]) - 97;
                line[i] = tolower(cab[ind]);
            }
        }
    }
    inFile("Atbash cipher: " + line);
}

void antiatbash()
{
    string line = getString("Atbash cipher: ", 15);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++)
    {
        if (isalpha(line[i]))
        {
            if (isupper(line[i]))
            {
                ind = int(line[i]) - 65;
                line[i] = cab[ind];
            }
            else
            {
                ind = int(line[i]) - 97;
                line[i] = tolower(cab[ind]);
            }
        }
    }
    inFile("Decryption: " + line);
}

void keywordABC()
{
    string keyword; // ключ
    string line = getString("Phrase: ", 8); // входная строка
    keyword = getKey();
    inFile("Key: " + keyword);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector <char> newABC;
    int ind = 0;
    for (size_t i = 0; i < keyword.size(); i++)
    {
        newABC.push_back(toupper(keyword[i]));
    }
    for (char elem : abc)
    {
        if (find(newABC.begin(), newABC.end(), elem) != newABC.end())
            continue;
        else
        {
            newABC.push_back(elem);
        }
    }
    for (size_t i = 0; i < line.size(); i++)
    {
        if (isalpha(line[i]))
        {
            ind = int(toupper(line[i])) - 65;
            if (isupper(line[i])) line[i] = newABC[ind];
            else line[i] = tolower(newABC[ind]);
        }
    }
    inFile("Keyword cipher: " + line);
}

void antikeywordABC()
{
    string keyword = getString("Key: ", 5);
    string line = getString("Keyword cipher: ", 16);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector <char> newABC;
    int ind = 0;
    for (size_t i = 0; i < keyword.size(); i++)
    {
        newABC.push_back(toupper(keyword[i]));
    }
    for (char elem : abc)
    {
        if (find(newABC.begin(), newABC.end(), elem) != newABC.end())
            continue;
        else
        {
            newABC.push_back(elem);
        }
    }
    for (size_t i = 0; i < line.size(); i++)
    {
        if (isalpha(line[i]))
        {
            auto indIt = find(newABC.begin(), newABC.end(), toupper(line[i]));
            ind = indIt - newABC.begin();
            if (isupper(line[i])) line[i] = abc[ind];
            else line[i] = tolower(abc[ind]);
        }
    }
    inFile("Decryption: " + line);
}

vector<vector<char>> mtrxTransp(vector<vector<char>>& a)
{
    vector<vector<char>> result(a[0].size(), vector <char>(a.size()));
    for (size_t i = 0; i < a[0].size(); i++)
    {
        for (size_t j = 0; j < a.size(); j++)
        {
            result[i][j] = a[j][i];
        }
    }
    return result;
}

void sortByKey(vector <vector<char>>& text, string key)
{
    size_t j = 0, counter = 0;
    for (size_t i = 0; i < key.size(); i++)
    {
        for (j = counter; j < key.size(); j++)
        {
            if ((text[i][0] != key[i]) && (text[j][0] == key[i]))
            {
                swap(text[i], text[j]);
                counter++;
                break;
            }
        }
    }
}

void tableCypher()
{
    string keyword; // ключ
    string line = getString("Phrase: ", 8); // входная строка
    keyword = getKey();
    inFile("Key: " + keyword);
    int counter = 0, stSize;
    for (auto c : keyword) c = toupper(c);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    if ((line.size() + keyword.size()) % keyword.size() == 0)
        stSize = ((line.size() + keyword.size()) / keyword.size());
    else stSize = ((line.size() + keyword.size()) / keyword.size()) + 1;
    vector <vector<char>> cyphertext(keyword.size(), vector<char>(stSize));
    for (size_t i = 0; i < keyword.size(); i++)
    {
        for (size_t j = 0; j < stSize; j++)
            cyphertext[i][j] = ' ';
    }
    for (size_t i = 0; i < keyword.size(); i++)
    {
        cyphertext[i][0] = keyword[i];
        for (size_t j = 1; j < stSize; j++)
        {
            if (counter == line.size())
                break;
            cyphertext[i][j] = line[counter];
            counter++;
        }
    }
    sort(keyword.begin(), keyword.end());
    sortByKey(cyphertext, keyword);
    cyphertext = mtrxTransp(cyphertext);
    ofstream file;
    file.open("encryptions.txt", ofstream::app); // открыть файл
    file << "Table cipher with a keyword: ";
    for (size_t i = 1; i < cyphertext.size(); i++)
    {
        for (size_t j = 0; j < cyphertext[i].size(); j++)
        {
            if (cyphertext[i][j] == ' ')
            {
                file << '_';
                continue;
            }
            file << cyphertext[i][j];
        }
    }
    file << endl;
    file.close(); // закрыть файл
}

void antitableCypher()
{
    string keyword = getString("Key: ", 5);
    string line = getString("Table cipher with a keyword: ", 29);
    for (auto c : keyword) c = toupper(c);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    int stSize = line.size() / keyword.size() + 1, counter = 0;
    vector <vector<char>> cyphertext(keyword.size(), vector<char>(stSize));
    for (size_t i = 0; i < keyword.size(); i++)
    {
        for (size_t j = 0; j < stSize; j++)
            cyphertext[i][j] = ' ';
    }
    string unsortedkey = keyword;
    sort(keyword.begin(), keyword.end());
    for (size_t i = 0; i < keyword.size(); i++)
        cyphertext[i][0] = keyword[i];
    for (size_t j = 1; j < keyword.size(); j++)
    {
        for (size_t i = 0; i < keyword.size(); i++)
        {
            if (counter == line.size())
                break;
            cyphertext[i][j] = line[counter];
            counter++;
        }
    }
    sortByKey(cyphertext, unsortedkey);
    ofstream file;
    file.open("encryptions.txt", ofstream::app);
    file << "Decrypt: ";
    for (size_t i = 0; i < cyphertext.size(); i++)
    {
        for (size_t j = 1; j < cyphertext[i].size(); j++)
        {
            if (cyphertext[i][j] == '_')
                continue;
            file << cyphertext[i][j];
        }
    }
    file << endl;
    file.close();
}

int main() {
    string dialogStr; // диалоговая строка
    string pinAdmin = "1111"; // дефолтный пинкод
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
        }
        else if (dialogStr == "pin") { // команда ввода пинкода
            cout << "Enter pinAdmin: ";
            getline(cin, pinAdmin); // ввод пинкода
            cout << "    [PINCODE SET]" << endl << endl;
        }
        else if (dialogStr == "clear") { // команда очистки файла
            clearFile(); // обращение к функции очистки файла
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        }
        else if (dialogStr == "get") { // команда получения содержимого файла
            cout << "    [FILE CONTENTS]" << endl;
            getFile(); // обращение к функции получения содержимого файла
            cout << endl;
        }
        else if (dialogStr == "cipher") {
            string cipher_str;
            int cipher;
            cout
                << "\t1. Gronsfeld cipher\n\t2. Encryption using the square of Polybius\n\t3. Simple table permutation\n\t4. Atbash cipher\n\t5. Keyword cipher\n\t6. Table cipher with a keyword\n\tAny other character: go back\nChoose encryption (1-6): ";
            getline(cin, cipher_str);
            if (cipher_str == "1" or cipher_str == "2" or cipher_str == "3" or cipher_str == "4" or cipher_str == "5" or cipher_str == "6") cipher = cipher_str[0] - '0';
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
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 2:
                break;
            case 3:
                break;
            case 4:
            {
                cout << endl << "    [Atbash cipher]" << endl << endl;
                if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                    cout << "    [Pincode not set!]" << endl;
                    break;
                }
                string pinUser; // пинкод
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    atbash();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }               
            case 5:
            {
                cout << endl << "    [Keyword cipher]" << endl << endl;
                if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                    cout << "    [Pincode not set!]" << endl;
                    break;
                }
                string pinUser; // пинкод
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    keywordABC();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 6:
            {
                cout << endl << "    [Table cipher with a keyword]" << endl << endl;
                if (pinAdmin == "0000") { // проверка того, задан ли пинкод
                    cout << "    [Pincode not set!]" << endl;
                    break;
                }
                string pinUser; // пинкод
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    tableCypher();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            default:
                break;
            }
        }
        else if (dialogStr == "decrypt") {
        if (checkString("Gronsfeld: ")) antiGronsfeld();
        else if (checkString("Atbash cipher: ")) antiatbash();
        else if (checkString("Keyword cipher: ")) antikeywordABC();
        else if (checkString("Table cipher with a keyword: ")) antitableCypher();
        }
        else if (dialogStr == "help") { // команда вызова списка команд
            cout << "    [COMMANDS]" << endl;
            cout << "input -- Writing a line to a file;" << endl;
            cout << "get -- Displaying the contents of a file;" << endl;
            cout << "clear -- Cleaning up the contents of a file;" << endl;
            cout << "pin -- Pincode setting;" << endl;
            cout << "cipher -- Choice of encryption" << endl;
            cout << "stop -- Stop program;" << endl << endl;

        }
        else if (dialogStr == "stop") { // остановка программы
            cout << "    [The program has been stopped]" << endl;
            break;
        }
        else { // команды не существует
            cout << endl << "[ERROR_217][THIS COMMAND DOES NOT EXIST][ERROR_217]" << endl << endl;
        }
    }
    return 0;
}

void inFile(string inStr) { // функция записи строки в файл
    ofstream file;
    file.open("encryptions.txt", ofstream::app); // открыть файл
    file << inStr << endl; // запись строки в файл
    file.close(); // закрыть файл
}

void clearFile() { // функция очистки файла
    ofstream file;
    file.open("encryptions.txt"); // открыть файл (тем самым обнулить)
    file.close(); // закрыть файл
}

void getFile() { // функция получения содержимого файла
    ifstream file;
    string str;
    file.open("encryptions.txt"); // открыть файл для чтения
    while (getline(file, str)) { // пока в файле есть строки: вывести строки
        cout << str << endl;
    }
    file.close(); // закрыть файл
}

string getString(string mark, int pos_n) { // функция получения фразы из файла
    ifstream file;
    string line, str_out;
    file.open("encryptions.txt"); // открыть файл
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
    file.open("encryptions.txt"); // открыть файл
    while (getline(file, line)) { // пока в файле есть строки
        if (line.find(mark) != line.npos) {
            return true;
        }
    }
    return false;
}

bool checkPincode(string pinUser, string pinAdmin) { // функция проверки пинкода
    return (pinUser == pinAdmin);
}