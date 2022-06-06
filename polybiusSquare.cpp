#include <string>
#include <vector>
#include "polybiusSquare.h"
#include "interface.h"

using namespace std;

void square() {
    string line;
    line = "\t1\t2\t3\t4\t5";
    line = "";
    line = '1';
    for (char c = 'A'; c <= 'E'; c++) {
        line += '\t';
        line += c;
    }
    line = "";
    line = '2';
    for (char c = 'F'; c <= 'K'; c++) {
        if (c != 'J') {
            line += '\t';
            line += c;
        }
        else line += c;
    }
    line = "";
    line = '3';
    for (char c = 'L'; c <= 'P'; c++) {
        line += '\t';
        line += c;
    }
    line = "";
    line = '4';
    for (char c = 'Q'; c <= 'U'; c++) {
        line += '\t';
        line += c;
    }
    line = "";
    line = '5';
    for (char c = 'V'; c <= 'Z'; c++) {
        line += '\t';
        line += c;
    }
}

int charToPolybius(char c, const vector<pair<char, pair<int, int>>>& vec) {
    int pos;
    for (pair<char, pair<int, int>> pair : vec) {
        if (c == pair.first) {
            pos = pair.second.first*10 + pair.second.second;
            return pos;
        }
    }
}

void PolybiusSquare() {
    pair<int, int> pos;
    pair<char, pair<int, int>> sqPol;
    vector<pair<char, pair<int, int>>> polybius;
    int n1 = 1, n2 = 1;
    char c = 'a';
    for (int i = 0; i <= 25; i++) {
        if (n2 == 6) {
            n1++;
            n2 = 1;
        }
        if (c == 'j') n2--;
        pos.first = n1;
        pos.second = n2;
        n2++;

        sqPol.first = c;
        sqPol.second = pos;
        c++;
        polybius.push_back(sqPol);
    }

    string strIn = getString("Phrase: ", 8); // входная строка
    string strOut;
    string upperSymbol;
    for (int i = 0; i < strIn.length(); i++) {
        if (strIn[i] >= 'A' and strIn[i] <= 'Z') upperSymbol+= to_string(i);
    }
    outFile("Capital characters: " + upperSymbol);
    for (char elem : strIn) {
        elem = tolower(elem);
        int numPol = charToPolybius(elem, polybius);
        if (elem != ' ' and elem != ',', and elem != '.' and elem != '!', and elem != '?') strOut+=to_string(numPol);
        else strOut.push_back(' ');
    }
    inFile("Phrase: " +strOut);
}

char PolybiusToChar(char first, char second, const vector<pair<char, pair<int, int>>>& vec) {
    char c;
    for (pair<char, pair<int, int>> pair : vec) {
        if (first - '0' == pair.second.first and second - '0' == pair.second.second) {
            c = pair.first;
            return c;
        }
    }
}

void antiPolybiusSquare() {
    pair<int, int> pos;
    pair<char, pair<int, int>> sqPol;
    vector<pair<char, pair<int, int>>> polybius;
    int n1 = 1, n2 = 1;
    char c = 'a';
    for (int i = 0; i <= 25; i++) {
        if (n2 == 6) {
            n1++;
            n2 = 1;
        }
        if (c == 'j') n2--;
        pos.first = n1;
        pos.second = n2;
        n2++;

        sqPol.first = c;
        sqPol.second = pos;
        c++;
        polybius.push_back(sqPol);
    }

    string strIn = getString("Phrase: ", 8); // входная строка
    string strOut;
    char letter;
    string upperSymbol = getKey("Capital characters: ", 20);
    vector<int> symUp;
    for (char i : upperSymbol) {
        symUp.push_back(i - '0');
    }
    for (int i = 0; i < strIn.length(); i++) {
        if (strIn[i]!=' ') {
            char numFirst = strIn[i];
            char numSecond = strIn[i+1];
            i++;
            letter = PolybiusToChar(numFirst, numSecond, polybius);
            if (letter != 'i' and letter != 'j') {
                strOut.push_back(PolybiusToChar(numFirst, numSecond, polybius));
            }
            else {
                strOut.push_back('i'); strOut.push_back('('); strOut.push_back('j'); strOut.push_back(')');
            }

        }
        else strOut.push_back(' ');
    }
    for (int i = 0; i < symUp.size(); i++) {
        if (strOut[symUp[i]] != 'i') {
            strOut[symUp[i]] = toupper(strOut[symUp[i]]);
        }
        else {
            strOut[symUp[i]] = toupper(strOut[symUp[i]]);
            strOut[symUp[i]+2] = toupper(strOut[symUp[i]+2]);
            for (int j = i + 1; j < symUp.size(); j++) {
                symUp[j]+=3;
            }
        }
    }
    inFile("Phrase: " + strOut);
}
