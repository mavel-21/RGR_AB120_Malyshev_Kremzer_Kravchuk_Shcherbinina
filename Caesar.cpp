#include "interface.h"
#include "Caesar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

void Caesar() {
    int n;
    while (true) {
        cout << "Enter key: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "The key must be integer " << endl;
        } else if (n > 0) {

            cin.ignore(INT_MAX, '\n');
            break;
        } else {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "The key must be natural " << endl;
        }
    }
    string str = getString("Phrase: ", 8);
    n = n % 26;
    outFile("KeyD: " + to_string(n));
    for (auto &c: str) {
        if (c < 'a' && c > 'z' || c < 'A' && c > 'Z') {
            continue;
        }
        if (c >= 'a' && c <= 'z')
            c = ((c - 'a' + n) % 26) + 'a';
        else if (c >= 'A' && c <= 'Z')
            c = ((c - 'A' + n) % 26) + 'A';
    }
    inFile("Phrase: " + str);
}

void antiCaesar() {
    int n = stoi(getKey("KeyD: ", 6));
    string str = getString("Phrase: ", 8);
    n = n % 26;
    for (auto &c: str) {
        if (c < 'a' && c > 'z' || c < 'A' && c > 'Z') {
            continue;
        }
        if (c >= 'a' && c <= 'z') {
            if (c - n < 'a') {
                c = c - n + 'z' - 'a' + 1;
            } else
                c = ((c - 'a' - n) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            if (c - n < 'A') {
                c = c - n + 'Z' - 'A' + 1;
            } else
                c = ((c - 'A' - n) % 26) + 'A';
        }
    }
    inFile("Phrase: " + str);
}
