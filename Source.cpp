#include <iostream>
#include <fstream>
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
	fout.open("text.txt");
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
	n = n % 26;
	fin.open("text.txt");
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
	fout.open("text.txt");
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
	ifstream fin("text.txt");
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
	fout.open("text.txt");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
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
			cout << vtt[i][j];
			fout << vtt[i][j];
		}
	}
	fout.close();

}
void Tarab() {          //tarabarskaya gramota   //dlya deshifrovki primenit 2 raz
	string word, buff;
	buff = "";
	int k;
	fin.open("text.txt");
	while (!fin.eof()) {
		if (buff != "") buff += " ";
		fin >> word;
		k = size(word);
		for (int i = 0; i < k; i++) {
			if (word[i] >= 'a' && word[i] <= 'z')
				switch (word[i]) {
					case 'b': word[i] = 'n'; break;
					case 'c': word[i] = 'p'; break;
					case 'd': word[i] = 'q'; break;
					case 'f': word[i] = 'r'; break;
					case 'g': word[i] = 's'; break;
					case 'h': word[i] = 't'; break;
					case 'j': word[i] = 'v'; break;
					case 'k': word[i] = 'w'; break;
					case 'l': word[i] = 'x'; break;
					case 'm': word[i] = 'z'; break;

					case 'n': word[i] = 'b'; break;
					case 'p': word[i] = 'c'; break;
					case 'q': word[i] = 'd'; break;
					case 'r': word[i] = 'f'; break;
					case 's': word[i] = 'g'; break;
					case 't': word[i] = 'h'; break;
					case 'v': word[i] = 'j'; break;
					case 'w': word[i] = 'k'; break;
					case 'x': word[i] = 'l'; break;
					case 'z': word[i] = 'm'; break;
				}
			else
				switch (word[i]) {
					case 'B': word[i] = 'N'; break;
					case 'C': word[i] = 'P'; break;
					case 'D': word[i] = 'Q'; break;
					case 'F': word[i] = 'R'; break;
					case 'G': word[i] = 'S'; break;
					case 'H': word[i] = 'T'; break;
					case 'J': word[i] = 'V'; break;
					case 'K': word[i] = 'W'; break;
					case 'L': word[i] = 'X'; break;
					case 'M': word[i] = 'Z'; break;

					case 'N': word[i] = 'B'; break;
					case 'P': word[i] = 'C'; break;
					case 'Q': word[i] = 'D'; break;
					case 'R': word[i] = 'F'; break;
					case 'S': word[i] = 'G'; break;
					case 'T': word[i] = 'H'; break;
					case 'V': word[i] = 'J'; break;
					case 'W': word[i] = 'K'; break;
					case 'X': word[i] = 'L'; break;
					case 'Z': word[i] = 'M'; break;
				}

			buff += word[i];

		}
	}
	cout << buff;
	fin.close();
	fout.open("text.txt");
	fout << buff;
	fout.close();

}