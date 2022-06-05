#include "doubleTable.h"
#include "interface.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void DoubleTable() {
    string st, kl, kk, kl2, kk2, stOut = "";
    char x;
    int n, m, k, flag = 0, isPrime = 1;
    k = 0;
    st = getString("Phrase: ", 8);
    if (st.size() <= 1) isPrime = 0;
    for (int i = 2; i < st.size(); i++)
        if (st.size() % i == 0)
            isPrime = 0;
    if (isPrime) {
        cout
                << "   [ERROR] Can't use Double table permutation with a text of length which is a prime number! Length of text is: "
                << st.size() << endl << endl;
        return;
    }
    while (flag == 0) {
        cout << "Enter first key: ";
        cin >> kl;
        cout << "Enter second key: ";
        cin >> kl2;
        kk = kl;
        kk2 = kl2;
        n = kl.size();
        m = kl2.size();
        try {
            flag = 1;
            if (m * n != st.size()) {
                flag = 0;
                throw 1;
            }
            for (char elem: kl) {
                if (!isdigit(elem)) {
                    flag = 0;
                    throw 1;
                }
                else {
                    int check = elem - '0';
                    if (check > kl.size()) {
                        flag = 0;
                        throw 1;
                    }
                }
            }
            for (char elem: kl2) {
                if (!isdigit(elem)) {
                    flag = 0;
                    throw 1;
                } else {
                    int check = elem - '0';
                    if (check > kl2.size()) {
                        flag = 0;
                        throw 1;
                    }
                }
            }
        }
        catch (...) {
            cout
                    << "Incorrect keys! Note the rules:\n1) Length of key 1 * length of key 2 should be equal to text length!\n2) Key must contain only numbers!\n3) Digits of key shouldn't be greater than length of key!"
                    << endl;
            cout << "Example: Text length = 12, Key 1 = 1324, Key 2 = 132" << endl;
            cout << "Text length: " << st.size() << endl << endl;
        }
    }
    inFile("Key 1: " + kl);
    inFile("Key 2: " + kl2);
    vector <vector<char>> v(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = st[k];
            k++;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (kk[i] > kk[j]) {
                x = kk[i];
                kk[i] = kk[j];
                kk[j] = x;
                for (int k = 0; k < m; k++) {
                    x = v[k][i];
                    v[k][i] = v[k][j];
                    v[k][j] = x;

                }
            }
        }
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (kk2[i] > kk2[j]) {
                x = kk2[i];
                kk2[i] = kk2[j];
                kk2[j] = x;
                for (int k = 0; k < n; k++) {
                    x = v[i][k];
                    v[i][k] = v[j][k];
                    v[j][k] = x;

                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            stOut += v[i][j];

        }

    }
    inFile("DoubleTable: " + stOut);
}

void antiDoubleTable() {
    char x;
    int n, m, k;
    string stOut = "";
    string st = getString("DoubleTable: ", 13);
    string kl = getString("Key 1: ", 7);
    string kl2 = getString("Key 2: ", 7);
    string kk = kl;
    string kk2 = kl2;
    n = kl.size();
    m = kl2.size();
    vector <vector<char>> v(m, vector<char>(n));
    vector <vector<char>> vt(m, vector<char>(n));
    vector <vector<char>> vtt(m, vector<char>(n));
    k = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = st[k];
            k++;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (kk[i] > kk[j]) {
                x = kk[i];
                kk[i] = kk[j];
                kk[j] = x;
            }
        }
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (kk2[i] > kk2[j]) {
                x = kk2[i];
                kk2[i] = kk2[j];
                kk2[j] = x;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (kk2[j] == kl2[i]) {
                for (int k = 0; k < n; k++) {
                    vt[i][k] = v[j][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (kk[j] == kl[i]) {
                for (int k = 0; k < m; k++) {
                    vtt[k][i] = vt[k][j];
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            stOut += vtt[i][j];
        }
    }
    inFile("DoubleTable decryption: " + stOut);
}