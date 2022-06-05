#include "keywordABC.h"
#include "interface.h"
#include "keygen.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void keywordABC() {
    string keyword; // ключ
    string line = getString("Phrase: ", 8); // входная строка
    keyword = getKey();
    inFile("Key: " + keyword);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char> newABC;
    int ind = 0;
    for (size_t i = 0; i < keyword.size(); i++) {
        newABC.push_back(toupper(keyword[i]));
    }
    for (char elem: abc) {
        if (find(newABC.begin(), newABC.end(), elem) != newABC.end())
            continue;
        else {
            newABC.push_back(elem);
        }
    }
    for (size_t i = 0; i < line.size(); i++) {
        if (isalpha(line[i])) {
            ind = int(toupper(line[i])) - 65;
            if (isupper(line[i])) line[i] = newABC[ind];
            else line[i] = tolower(newABC[ind]);
        }
    }
    inFile("Keyword cipher: " + line);
}

void antikeywordABC() {
    string keyword = getString("Key: ", 5);
    string line = getString("Keyword cipher: ", 16);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char> newABC;
    int ind = 0;
    for (size_t i = 0; i < keyword.size(); i++) {
        newABC.push_back(toupper(keyword[i]));
    }
    for (char elem: abc) {
        if (find(newABC.begin(), newABC.end(), elem) != newABC.end())
            continue;
        else {
            newABC.push_back(elem);
        }
    }
    for (size_t i = 0; i < line.size(); i++) {
        if (isalpha(line[i])) {
            auto indIt = find(newABC.begin(), newABC.end(), toupper(line[i]));
            ind = indIt - newABC.begin();
            if (isupper(line[i])) line[i] = abc[ind];
            else line[i] = tolower(abc[ind]);
        }
    }
    inFile("Decryption: " + line);
}