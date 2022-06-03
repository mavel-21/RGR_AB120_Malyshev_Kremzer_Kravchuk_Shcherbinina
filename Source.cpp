#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
ofstream fout;
ifstream fin;
void Caesar() {               //цезарь
	string word, buff;
	buff = "";
	int n;

	fin.open("key.txt");
	fin >> n;
	fin.close(); 
	n = 3;
	n = n % 26;
	fin.open("text.txt");
	while (!fin.eof()) {
		if (buff != "") buff += " ";
		fin >> word;

		for (auto& c : word)
		{
			if (c >= 'a' && c <= 'z')
				c = ((c - 'a' + n) % 26) + 'a';
			else if (c >= 'A' && c <= 'Z')
				c = ((c - 'A' + n) % 26) + 'A';
		}


		cout << word << " ";
		buff += word;
		word.clear();
	}
	fin.close();
	fout.open("text1.txt");
	fout << buff;
	fout.close();
}

void UnCaesar() {

	string word, buff;
	buff = "";
	int n;
	fin.open("key.txt");
	fin >> n;
	fin.close();
	n = 3;
	n = n % 26;
	fin.open("text1.txt");
	while (!fin.eof()) {
		if (buff != "") buff += " ";
		fin >> word;
		for (auto& c : word)
		{
			if (c >= 'a' && c <= 'z') {
				if (c - n < 'a') {
					c = c - n + 'z' - 'a' + 1;
				}
				else
					c = ((c - 'a' - n) % 26) + 'a';
			}
			else if (c >= 'A' && c <= 'Z') {
				if (c - n < 'A') {
					c = c - n + 'Z' - 'A' + 1;
				}
				else
					c = ((c - 'A' - n) % 26) + 'A';
			}


		}
		cout << word << " ";
		buff += word;
		word.clear();
	}

	fin.close();
	fout.open("text1.txt");
	fout << buff;
	fout.close();
}
void DoubleTable() {             //двойная табличная
	string st, kl, kk, kl2, kk2;
	char x;
	int n, m, k;
	fin.open("key.txt");
	while (!fin.eof()) {
		if (kl == "") {
			fin >> kl;
		}
		else {
			fin >> kl2;
		}
	}
	kk = kl;
	kk2 = kl2;
	n = size(kl);
	m = size(kl2);
	vector <vector <char>> v(m, vector <char>(n));
	k = 0;
	ifstream fin("ttext.txt");


	while (getline(fin, st)) {
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
	}
	fin.close();
	fout.open("ttext.txt");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << v[i][j];
		}
	}
	fout.close();
}
void UnDoubleTable() {
	string st, kl, kk, kl2, kk2;
	char x;
	int n, m, k;
	vector <vector <char>> v(m, vector <char>(n));
	vector <vector <char>> vt(m, vector <char>(n));
	vector <vector <char>> vtt(m, vector <char>(n));
	k = 0;
	ifstream fin("text.txt");
	while (getline(fin, st)) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = st[k];
				k++;
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
	}
	fin.close();
	fout.open("text.txt");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << vtt[i][j];
		}
	}
	fout.close();
}