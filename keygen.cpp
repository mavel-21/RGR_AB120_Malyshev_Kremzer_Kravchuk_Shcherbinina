#include <iostream>
#include <string>
#include <locale>
#include "keygen.h"

using namespace std;

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

string getKey()
{
    setlocale(LC_ALL,"Russian");
    string keyword;
    do
        {
            cout << "Enter a keyword without two same letters: ";
            cin >> keyword;
            if (sameLetters(keyword) != 0)
                cout << "There are two same letters in this keyword! ";
        } while (sameLetters(keyword) != 0);
    return keyword;
}