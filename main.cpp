//Список 4 подгруппы:
//A) Кравчук Б.Д.
//B) Кремзер А.Д.
//C) Малышев П.А.
//D) Щербинина Д.В.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// АТБАШ 1.1. ДОБАВЛЕН ФАЙЛОВЫЙ ВВОД-ВЫВОД И ВЫБОР ШИФРОВКИ

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
ofstream outfile;
ifstream infile;

void atbash(string line, int choice)
{
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++)
    {
        if (isalpha(line[i]))
        {
            if (isupper(line[i]))
            {
                ind = int(line[i]) - 65;
                if (choice) line[i] = cab[ind];
                else line[i] = abc[ind];
            }
            else
            {
                ind = int(line[i]) - 97;
                if (choice) line[i] = tolower(cab[ind]);
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
    string line;
    int choice, algo;
    cout << "Выберите шифровку:\n1) Атбаш\t2) Шифр с использованием кодового слова\t       3) Табличная шифровка с ключевым словом" << endl;
    cin >> algo;
    cout << "Выберите, что требуется сделать с текстом:\n1) Зашифровать \t 2) Дешифровать" << endl;
    cin >> choice;
    while (getline(infile, line))
    {
        switch (algo)
        {
        case 1:
            atbash(line, choice);
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }
}
