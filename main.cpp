//Список 4 подгруппы:
//A) Кравчук Б.Д.
//B) Кремзер А.Д.
//C) Малышев П.А.
//D) Щербинина Д.В.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// ДОБАВЛЕН ШИФР С КОДОВЫМ СЛОВОМ

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
ofstream outfile;
ifstream infile;

void atbash(string line, int mode)
{
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++)
    {
        if (isalpha(line[i]))
        {
            if (isupper(line[i]))
            {
                ind = int(line[i]) - 65;
                if (mode == 1) line[i] = cab[ind];
                else line[i] = abc[ind];
            }
            else
            {
                ind = int(line[i]) - 97;
                if (mode == 1) line[i] = tolower(cab[ind]);
                else line[i] = tolower(abc[ind]);
            }
        }
    }
    for (char elem : line)
    {
        outfile << elem;
    }
    outfile << " " << endl;
}

void keywordABC(string line, string keyword, int mode) 
{
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
            if (mode == 1)
            {
                ind = int(line[i]) - 65;
                if (isupper(line[i])) line[i] = newABC[ind];
                else line[i] = tolower(newABC[ind]);
            }
            else
            {
                auto indIt = find(newABC.begin(), newABC.end(), line[i]);
                ind = indIt - newABC.begin();
                if (isupper(line[i])) line[i] = abc[ind];
                else line[i] = tolower(abc[ind]);
            }
        }
    }
    for (char elem : line)
    {
        outfile << elem;
    }
    outfile << " " << endl;
}
int main()
{
    outfile.open("output.txt");
    infile.open("input.txt");
    setlocale(LC_ALL, "Russian");
    string line, keyword;
    int mode, algo;
    cout << "Выберите шифровку:\n1) Атбаш\t2) Шифр с использованием кодового слова\t       3) Табличная шифровка с ключевым словом" << endl;
    cin >> algo;
    if ((algo == 2) || (algo == 3))
    {
        cout << "Введите кодовое слово: ";
        cin >> keyword; // НЕ ЗАБЫТЬ: проверка на то, что в кодовом слове нет одинаковых букв
    }
    cout << "Выберите, что требуется сделать с текстом:\n1) Зашифровать \t 2) Дешифровать" << endl;
    cin >> mode;
    while (getline(infile, line))
    {
        switch (algo)
        {
        case 1:
            atbash(line, mode);
            break;
        case 2:
            keywordABC(line, keyword, mode);
            break;
        case 3:
            break;
        }
    }
}
