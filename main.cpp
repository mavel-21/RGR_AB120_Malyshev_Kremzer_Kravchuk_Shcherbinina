//Список 4 подгруппы:
//A) Кравчук Б.Д.
//B) Кремзер А.Д.
//C) Малышев П.А.
//D) Щербинина Д.В.

#include <iostream>
#include <string>
using namespace std;

// АТБАШ 1.0. ФАЙЛОВЫЙ ВВОД/ВЫВОД БУДЕТ ДОБАВЛЕН ПОЗЖЕ

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

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
        cout << elem;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string line;
    int choice;
    cout << "Введите строку: ";
    getline(cin, line);
    cout << "Выберите, что требуется сделать со строкой:\n1) Зашифровать \t 2) Дешифровать" << endl;
    cin >> choice;
    atbash(line, choice);
}

