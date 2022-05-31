#include <iostream>
#include <string>
#include <locale>
#include "keygen.h"

using namespace std;

int sameLetters(string word) // проверка повторяющихся символов в ключе
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

int isKeyValid(string word) // проверка ключа на наличие недопустимых символов (в т.ч. букв русского алфавита) и цифр
{
    for (char elem : word) if ((int(elem) < 0) || (int(elem) > 255) || (int(elem) > 47)  && (int(elem) < 58)) return 0;
    return 1;
}

string getKey()
{
    setlocale(LC_ALL,"Russian");
    string keyword, enter = "Введите ключевое слово без повторяющихся букв, цифр и русских символов: ",
                    err = "Некорректный ввод! Проверьте, чтобы ключ не содержал повторяющихся букв, цифр и русских символов.";
    do
        {
        try {
            cout << enter;
            cin >> keyword;
            if (sameLetters(keyword) != 0)
                throw("KEY_SAME_LETTERS");
            if (isKeyValid(keyword) == 0)
                throw("KEY_NOT_VALID");
        }
        catch (...)
        {
            cout << err << endl << endl;
        }
        } while ((sameLetters(keyword) != 0) || (isKeyValid(keyword) == 0));
    return keyword;
}
