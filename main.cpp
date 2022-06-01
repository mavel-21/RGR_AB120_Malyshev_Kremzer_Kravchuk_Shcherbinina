// Кремзер Алёна

// Группа: АБ-120

// Шифровки:
//      Шифр Атбаш (5.10) ✓
//      Шифр с использованием кодового слова (5.14) ✓
//      Табличная шифровка с ключевым словом (5.17) ✓

// ВНИМАНИЕ: шифровки используют только латинский алфавит и символы ASCII. 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "atbash.h"
#include "keywordABC.h"
#include "tableCypher.h"
#include "keygen.h"

using namespace std;

void atbash(string line, int mode, ofstream& outfile);

void tableCypherEncode(string line, string keyword, ofstream& outfile);

void tableCypherDecode(string line, string keyword, ofstream& outfile);

void keywordABC(string line, string keyword, int mode, ofstream& outfile);

string getKey();

int main()
{
    ofstream outfile;
    ifstream infile;
    outfile.open("output.txt");
    infile.open("input.txt");
    setlocale(LC_ALL, "Russian");
    string line, keyword;
    string mode, algo;
    int isOk = 0;
    while (isOk == 0)
    {
        try {
            cout << "Выберите шифровку:\n1) Атбаш\t2) Шифр с использованием кодового слова\t\t3) Табличная шифровка с ключевым словом" << endl;
            getline(cin, algo);
            if ((algo.length() > 1) || ((isdigit(algo[0])) && (algo.length() == 1) && ((stoi(algo) > 3) || (stoi(algo) < 1))))
            {
                throw("INPUT_INCORRECT");
                isOk = 0;
            }
            else isOk = 1;
        }
        catch (...) {
            cout << "Некорректный ввод!" << endl << endl;
        }
    }
    isOk = 0;
    if ((stoi(algo) == 2) || (stoi(algo) == 3)) keyword = getKey();
    while (isOk == 0)
    {
        try {
            cout << "Выберите, что требуется сделать с текстом:\n1) Зашифровать \t 2) Дешифровать" << endl;
            getline(cin, mode);
            if ((mode.length() > 1) || ((isdigit(mode[0])) && (mode.length() == 1) && ((stoi(mode) > 2) || (stoi(mode) < 1))))
            {
                throw("INPUT_INCORRECT");
                isOk = 0;
            }
            else isOk = 1;
        }
        catch (...) {
            cout << "Некорректный ввод!" << endl << endl;
        }
    }
    while (getline(infile, line))
    {
        try {
            for (char elem : line) if ((int(elem) < 0) || (int(elem) > 255)) throw("INPUT_INCORRECT");
        }
        catch (...) {
            cout << "Произошла ошибка. Проверьте, нет ли в вашем файле букв русского алфавита или символов вне таблицы ASCII." << endl;
            outfile << "INPUT_INCORRECT";
            return 0;
        }
    }
    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, line))
    {
        switch (stoi(algo))
        {
        case 1:
            atbash(line, stoi(mode), outfile);
            break;
        case 2:
            keywordABC(line, keyword, stoi(mode), outfile);
            break;
        case 3:
            if (stoi(mode) == 1) tableCypherEncode(line, keyword, outfile);
            else tableCypherDecode(line, keyword, outfile);
            break;
        }
    }
    cout << "Успешно!" << endl;
}
