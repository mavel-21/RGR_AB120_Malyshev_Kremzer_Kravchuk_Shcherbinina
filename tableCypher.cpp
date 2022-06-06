#include "tableCypher.h"
#include "interface.h"
#include "keygen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> mtrxTransp(vector<vector<char>> &a) {
    vector<vector<char>> result(a[0].size(), vector<char>(a.size()));
    for (size_t i = 0; i < a[0].size(); i++) {
        for (size_t j = 0; j < a.size(); j++) {
            result[i][j] = a[j][i];
        }
    }
    return result;
}

void sortByKey(vector<vector<char>> &text, string key) {
    size_t j = 0, counter = 0;
    for (size_t i = 0; i < key.size(); i++) {
        for (j = counter; j < key.size(); j++) {
            if ((text[i][0] != key[i]) && (text[j][0] == key[i])) {
                swap(text[i], text[j]);
                counter++;
                break;
            }
        }
    }
}

void tableCypher() {
    string keyword; // ключ
    string line = getString("Phrase: ", 8); // входная строка
    keyword = getKey();
    outFile("Key: " + keyword);
    int counter = 0, stSize;
    for (auto c: keyword) c = toupper(c);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    if ((line.size() + keyword.size()) % keyword.size() == 0)
        stSize = ((line.size() + keyword.size()) / keyword.size());
    else stSize = ((line.size() + keyword.size()) / keyword.size()) + 1;
    vector<vector<char>> cyphertext(keyword.size(), vector<char>(stSize));
    for (size_t i = 0; i < keyword.size(); i++) {
        for (size_t j = 0; j < stSize; j++)
            cyphertext[i][j] = ' ';
    }
    for (size_t i = 0; i < keyword.size(); i++) {
        cyphertext[i][0] = keyword[i];
        for (size_t j = 1; j < stSize; j++) {
            if (counter == line.size())
                break;
            cyphertext[i][j] = line[counter];
            counter++;
        }
    }
    sort(keyword.begin(), keyword.end());
    sortByKey(cyphertext, keyword);
    cyphertext = mtrxTransp(cyphertext);
    ofstream file;
    file.open("input.txt"); // открыть файл
    file << "Phrase: ";
    for (size_t i = 1; i < cyphertext.size(); i++) {
        for (size_t j = 0; j < cyphertext[i].size(); j++) {
            if (cyphertext[i][j] == ' ') {
                file << '_';
                continue;
            }
            file << cyphertext[i][j];
        }
    }
    file << endl;
    file.close(); // закрыть файл
}

void antitableCypher() {
    string keyword = getKey("Key: ", 5);
    string line = getString("Phrase: ", 8);
    for (auto &c : keyword) c = toupper(c);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    int stSize = line.size() / keyword.size() + 1, counter = 0;
    vector <vector<char>> cyphertext(keyword.size(), vector<char>(stSize));
    for (size_t i = 0; i < keyword.size(); i++)
    {
        for (size_t j = 0; j < stSize; j++)
            cyphertext[i][j] = ' ';
    }
    string unsortedkey = keyword;
    sort(keyword.begin(), keyword.end());
    for (size_t i = 0; i < keyword.size(); i++)
        cyphertext[i][0] = keyword[i];
    for (size_t j = 1; j < stSize; j++)
    {
        for (size_t i = 0; i < keyword.size(); i++)
        {
            if (counter == line.size())
                break;
            cyphertext[i][j] = line[counter];
            counter++;
        }
    }
    sortByKey(cyphertext, unsortedkey);
    ofstream file;
    string phrase;
    for (size_t i = 0; i < cyphertext.size(); i++)
    {
        for (size_t j = 1; j < cyphertext[i].size(); j++)
        {
            phrase.push_back(cyphertext[i][j]);
        }
    }
    phrase.erase(remove(phrase.begin(), phrase.end(), '_'), phrase.end());
    inFile("Phrase: " + phrase);
}
