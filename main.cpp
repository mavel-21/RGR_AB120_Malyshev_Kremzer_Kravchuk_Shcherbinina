// Кремзер Алёна

// Группа: АБ-120

// Шифровки:
//      Шифр Атбаш (5.10)
//      Шифр с использованием кодового слова (5.14)
//      Табличная шифровка с ключевым словом (5.17)

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
ofstream outfile;
ifstream infile;
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

vector<vector<string>> mtrxTransp(vector<vector<string>> a) // транспонирование матрицы
{
    vector<vector<string>> result(a[0].size(), vector <string>(a.size()));
    for (size_t i = 0; i < a[0].size(); i++)
    {
        for (size_t j = 0; j < a.size(); j++)
        {
            result[i][j] = a[j][i];
        }
    }
    return result;
}

void tableCypher(string line, string keyword, int mode)
{
    int counter = 0, stSize = (line.size() + keyword.size() * 2) / keyword.size() + 1;
    string keywordunsorted = keyword;
    sort(keyword.begin(), keyword.end());
    vector <vector<char>> cyphertext(keyword.size(), vector<char>(stSize));
    for (size_t i = 0; i < keyword.size(); i++)
    {
        cyphertext[i][0] = keywordunsorted[i]; // здесь добавить номер буквы в слове 
        for (int j = 2; j < stSize; j++)
        {
            if (counter == line.size())
                break;
            cyphertext[i][j] = line[counter];
            counter++;
        }
    }
    for (size_t i = 0; i < cyphertext.size(); i++)
    {
        for (size_t j = 0; j < cyphertext[i].size(); j++)
            outfile << cyphertext[i][j] << " ";
        outfile << endl;
    }
}

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
        do
        {
            cout << "Введите кодовое слово без повторяющихся букв: ";
            cin >> keyword;
            if (sameLetters(keyword) != 0)
                cout << "В слове есть повторяющиеся буквы. ";
        } while (sameLetters(keyword) != 0);
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
