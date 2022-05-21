// Кремзер Алёна

// Группа: АБ-120

// Шифровки:
//      Шифр Атбаш (5.10) ✓
//      Шифр с использованием кодового слова (5.14) ✓
//      Табличная шифровка с ключевым словом (5.17) ✓

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
    int mode, algo;
    cout << "Выберите шифровку:\n1) Атбаш\t2) Шифр с использованием кодового слова\t\t3) Табличная шифровка с ключевым словом" << endl;
    cin >> algo;
    if ((algo == 2) || (algo == 3)) keyword = getKey();
    cout << "Выберите, что требуется сделать с текстом:\n1) Зашифровать \t 2) Дешифровать" << endl;
    cin >> mode;
    while (getline(infile, line))
    {
        switch (algo)
        {
        case 1:
            atbash(line, mode, outfile);
            break;
        case 2:
            keywordABC(line, keyword, mode, outfile);
            break;
        case 3:
            if (mode == 1) tableCypherEncode(line, keyword, outfile);
            else tableCypherDecode(line, keyword, outfile);
            break;
        }
    }
}
