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

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // латинский алфавит
string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; // латинский алфавит (зеркальная версия для шифра Атбаш)
ofstream outfile; // файл вывода
ifstream infile; // файл ввода

void atbash(string line, int mode) // шифр Атбаш
{
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++)
    {
        if (isalpha(line[i])) // проверка, является ли символ буквой
        {
            if (isupper(line[i]))
            {
                ind = int(line[i]) - 65; // получение номера буквы в алфавите (ее индекса в строке abc или cab)
                if (mode == 1) line[i] = cab[ind]; // замена буквы на нужную букву из алфавита шифрования или дешифрования в зависимости от метода работы
                else line[i] = abc[ind];
            }
            else
            {
                ind = int(line[i]) - 97; // аналогичный алгоритм для строчных букв
                if (mode == 1) line[i] = tolower(cab[ind]);
                else line[i] = tolower(abc[ind]);
            }
        }
    }
    for (char elem : line)
    {
        outfile << elem; // вывод в файл
    }
    outfile << " " << endl;
}

void keywordABC(string line, string keyword, int mode) // шифр с использованием кодового слова
{
    vector <char> newABC;
    int ind = 0;
    for (size_t i = 0; i < keyword.size(); i++)
    {
        newABC.push_back(toupper(keyword[i])); // запись кодового слова в алфавит шифрования
    }
    for (char elem : abc)
    {
        if (find(newABC.begin(), newABC.end(), elem) != newABC.end()) // проверка, является ли буква алфавита буквой кодового слова
            continue;
        else
        {
            newABC.push_back(elem); // запись остального алфавита в алфавит шифрования
        }
    }
    for (size_t i = 0; i < line.size(); i++)
    {
        if (isalpha(line[i])) // проверка, является ли символ буквой
        {
            if (mode == 1)
            {
                ind = int(line[i]) - 65; // получение номера буквы в алфавите (ее индекса в алфавите шифрования)
                if (isupper(line[i])) line[i] = newABC[ind]; // замена буквы на букву с таким же индексом в алфавите шифрования
                else line[i] = tolower(newABC[ind]);
            }
            else
            {
                auto indIt = find(newABC.begin(), newABC.end(), line[i]); // поиск индекса зашифрованного символа в словаре шифрования
                ind = indIt - newABC.begin();
                if (isupper(line[i])) line[i] = abc[ind]; // замена буквы на букву с найденным индексом в латинском алфавите
                else line[i] = tolower(abc[ind]);
            }
        }
    }
    for (char elem : line)
    {
        outfile << elem; // вывод в файл
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
    cin >> algo; // выбор алгоритма шифрования
    if ((algo == 2) || (algo == 3)) // введение кодового слова для некоторых алгоритмов
    {
        cout << "Введите кодовое слово: ";
        cin >> keyword; // НЕ ЗАБЫТЬ: проверка на то, что в кодовом слове нет одинаковых букв
    }
    cout << "Выберите, что требуется сделать с текстом:\n1) Зашифровать \t 2) Дешифровать" << endl;
    cin >> mode; // выбор режима работы (шифрование/дешифрование)
    while (getline(infile, line)) // считывание текста построчно
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
