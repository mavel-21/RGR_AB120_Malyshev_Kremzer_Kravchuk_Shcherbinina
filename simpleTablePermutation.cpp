#include <string>
#include <vector>

#include "simpleTablePermutation.h"
#include "interface.h"

using namespace std;

pair<int, int> tableSize(int size) {
    int n, m;
    for (int m1 = 2; m1 < 10; m1++) {
        if (size % m1 == 0) {
            n = size / m1;
            m = m1;
        }
    }
    pair<int, int> tabSize{n, m};
    inFile("Columns: " + to_string(tabSize.first) + "\nLines: " + to_string(tabSize.second));
    return tabSize;
}

void STP() { // Simple Table Permutation
    string strIn = getString("Phrase: ", 8); // входная строка
    string strOut;
    int size = 0;
    for (char elem : strIn) if (elem != ' ') size++;
    pair<int, int> tabSize = tableSize(size);
    int n = tabSize.first, m = tabSize.second;
    char table[n][m];
    int n1 = 0, m1 = 0; // n - столбец и m - строка
    for (char letter: strIn) {
        if (letter != ' ') {
            if (m1 == m) {
                n1++;
                m1 = 0;
            }
            table[n1][m1] = letter;
            m1++;
        }
    }
    for (int m2 = 0; m2 < m; m2++) {
        string tab;
        for (int n2 = 0; n2 < n; n2++) {
            tab += table[n2][m2];
            tab += '\t';
        }
        inFile(tab);
    }

    int count = 0;
    for (int m3 = 0; m3 < m; m3++) {
        for (int n3 = 0; n3 < n; n3++) {
            if (count == m) {
                strOut.push_back(' ');
                count=0;
            }
            strOut.push_back(table[n3][m3]);
            count++;
        }
    }
    inFile("Simple table permutation: " + strOut); // запись строки в файл
}

void antiSTP() {
    string strIn = getString("Simple table permutation: ", 26); // входная строка
    string strOut;
    int n, m;
    string convert;
    convert = getString("Columns: ", 9);
    n = stoi(convert); // столбцов
    convert = getString("Lines: ", 7);
    m = stoi(convert); // строк
    char table[n][m];
    int n1 = 0, m1 = 0;
    for (char letter: strIn) {
        if (letter != ' ') {
            if (n1 == n) {
                m1++;
                n1 = 0;
            }
            table[n1][m1] = letter;
            n1++;
        }
    }
    for (int n3 = 0; n3 < n; n3++) {
        for (int m3 = 0; m3 < m; m3++) {
            strOut.push_back(table[n3][m3]);
        }
    }
    inFile("Simple table permutation decryption: " + strOut); // запись строки в файл
}