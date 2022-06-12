#include "tarab.h"
#include "interface.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void Tarab() {
    string word = getString("Phrase: ", 8);
    int k = word.size();
    string stOut = "";
    for (int i = 0; i < k; i++) {
        if (word[i] <= 'a' && word[i] >= 'z' || word[i] <= 'A' && word[i] >= 'Z') {
            continue;
        }
        if (word[i] >= 'a' && word[i] <= 'z')
            switch (word[i]) {
                case 'b': word[i] = 'z'; break;
                case 'c': word[i] = 'x'; break;
                case 'd': word[i] = 'w'; break;
                case 'f': word[i] = 'v'; break;
                case 'g': word[i] = 't'; break;
                case 'h': word[i] = 's'; break;
                case 'j': word[i] = 'r'; break;
                case 'k': word[i] = 'q'; break;
                case 'l': word[i] = 'p'; break;
                case 'm': word[i] = 'n'; break;

                case 'n': word[i] = 'm'; break;
                case 'p': word[i] = 'l'; break;
                case 'q': word[i] = 'k'; break;
                case 'r': word[i] = 'j'; break;
                case 's': word[i] = 'h'; break;
                case 't': word[i] = 'g'; break;
                case 'v': word[i] = 'f'; break;
                case 'w': word[i] = 'd'; break;
                case 'x': word[i] = 'c'; break;
                case 'z': word[i] = 'b'; break;
            }
        else
            switch (word[i]) {
                case 'B': word[i] = 'Z'; break;
                case 'C': word[i] = 'X'; break;
                case 'D': word[i] = 'W'; break;
                case 'F': word[i] = 'V'; break;
                case 'G': word[i] = 'T'; break;
                case 'H': word[i] = 'S'; break;
                case 'J': word[i] = 'R'; break;
                case 'K': word[i] = 'Q'; break;
                case 'L': word[i] = 'P'; break;
                case 'M': word[i] = 'N'; break;

                case 'N': word[i] = 'M'; break;
                case 'P': word[i] = 'L'; break;
                case 'Q': word[i] = 'K'; break;
                case 'R': word[i] = 'J'; break;
                case 'S': word[i] = 'H'; break;
                case 'T': word[i] = 'G'; break;
                case 'V': word[i] = 'F'; break;
                case 'W': word[i] = 'D'; break;
                case 'X': word[i] = 'C'; break;
                case 'Z': word[i] = 'B'; break;
            }
        stOut += word[i];
    }
    inFile("Phrase: " + stOut);
}

void antiTarab() {
    string word = getString("Phrase: ", 8);
    int k = word.size();
    string stOut = "";
    for (int i = 0; i < k; i++) {
        if (word[i] <= 'a' && word[i] >= 'z' || word[i] <= 'A' && word[i] >= 'Z') {
            continue;
        }
        if (word[i] >= 'a' && word[i] <= 'z')
            switch (word[i]) {
                case 'b': word[i] = 'z'; break;
                case 'c': word[i] = 'x'; break;
                case 'd': word[i] = 'w'; break;
                case 'f': word[i] = 'v'; break;
                case 'g': word[i] = 't'; break;
                case 'h': word[i] = 's'; break;
                case 'j': word[i] = 'r'; break;
                case 'k': word[i] = 'q'; break;
                case 'l': word[i] = 'p'; break;
                case 'm': word[i] = 'n'; break;

                case 'n': word[i] = 'm'; break;
                case 'p': word[i] = 'l'; break;
                case 'q': word[i] = 'k'; break;
                case 'r': word[i] = 'j'; break;
                case 's': word[i] = 'h'; break;
                case 't': word[i] = 'g'; break;
                case 'v': word[i] = 'f'; break;
                case 'w': word[i] = 'd'; break;
                case 'x': word[i] = 'c'; break;
                case 'z': word[i] = 'b'; break;
            }
        else
            switch (word[i]) {
                case 'B': word[i] = 'Z'; break;
                case 'C': word[i] = 'X'; break;
                case 'D': word[i] = 'W'; break;
                case 'F': word[i] = 'V'; break;
                case 'G': word[i] = 'T'; break;
                case 'H': word[i] = 'S'; break;
                case 'J': word[i] = 'R'; break;
                case 'K': word[i] = 'Q'; break;
                case 'L': word[i] = 'P'; break;
                case 'M': word[i] = 'N'; break;

                case 'N': word[i] = 'M'; break;
                case 'P': word[i] = 'L'; break;
                case 'Q': word[i] = 'K'; break;
                case 'R': word[i] = 'J'; break;
                case 'S': word[i] = 'H'; break;
                case 'T': word[i] = 'G'; break;
                case 'V': word[i] = 'F'; break;
                case 'W': word[i] = 'D'; break;
                case 'X': word[i] = 'C'; break;
                case 'Z': word[i] = 'B'; break;
            }
        stOut += word[i];
    }
    inFile("Phrase: " + stOut);
}
