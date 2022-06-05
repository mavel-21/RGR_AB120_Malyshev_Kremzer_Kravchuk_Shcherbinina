#include <string>
#include "atbash.h"
#include "interface.h"

using namespace std;

void atbash() {
    string line = getString("Phrase: ", 8);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++) {
        if (isalpha(line[i])) {
            if (isupper(line[i])) {
                ind = int(line[i]) - 65;
                line[i] = cab[ind];
            } else {
                ind = int(line[i]) - 97;
                line[i] = tolower(cab[ind]);
            }
        }
    }
    inFile("Phrase: " + line);
}

void antiatbash() {
    string line = getString("Phrase: ", 8);
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cab = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    int strSize = line.size(), ind = 0;
    for (int i = 0; i < strSize; i++) {
        if (isalpha(line[i])) {
            if (isupper(line[i])) {
                ind = int(line[i]) - 65;
                line[i] = cab[ind];
            } else {
                ind = int(line[i]) - 97;
                line[i] = tolower(cab[ind]);
            }
        }
    }
    inFile("Phrase:" + line);
}