#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "keygen.h"

using namespace std;

int sameLetters(string word) {
    for (int i = 0; i < word.length(); i++) {
        for (int j = 0; j < word.length(); j++) {
            if (i != j && word[i] == word[j])
                return 1;
        }
    }
    return 0;
}

int isKeyValid(string word) {
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (char elem: word) {
        if (find(abc.begin(), abc.end(), elem) == abc.end())
            return 0;
        return 1;
    }
}

string getKey() {
    setlocale(LC_ALL, "Russian");
    string keyword, enter = "Введите ключевое слово, состоящее только из неповторяющихся символов латинского алфавита:",
            err = "Некорректный ввод!";
    do {
        try {
            cout << enter << endl;
            getline(cin, keyword);
            keyword.erase(find(keyword.begin(), keyword.end(), ' '), keyword.end());
            if (sameLetters(keyword) != 0)
                throw ("KEY_SAME_LETTERS");
            if (isKeyValid(keyword) == 0)
                throw ("KEY_NOT_VALID");
        }
        catch (...) {
            cout << err << endl << endl;
        }
    } while ((sameLetters(keyword) != 0) || (isKeyValid(keyword) == 0));
    return keyword;
}