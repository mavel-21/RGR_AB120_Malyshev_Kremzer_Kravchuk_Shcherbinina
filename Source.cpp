#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void inFile(string inStr) { // функция записи строки в файл
	ofstream file;
	file.open("text.txt", ofstream::app); 
	file << inStr << endl; 
	file.close(); 
}
bool checkPincode(string pinUser, string pinAdmin) { // функция проверки пинкода
	return (pinUser == pinAdmin);
}
bool checkString(string mark) {
	ifstream file;
	string line;
	file.open("text.txt"); // открыть файл
	while (getline(file, line)) { // пока в файле есть строки
		if (line.find(mark) >= 0) {
			return true;
			break;
		}
	}
	return false;
}
string getString(string mark, int pos_n) { // функция получения фразы из файла
	ifstream file;
	string line, str_out;
	file.open("text.txt"); 
	while (getline(file, line)) { 
		int checkMark = line.find(mark);
		if (checkMark > -1) {
			str_out = line.substr(
				pos_n); 
			break;
		}
	}
	file.close(); 
	return str_out; 
}
void clearFile() { // функция очистки файла
	ofstream file;
	file.open("text.txt"); 
	file.close(); 
}
void getFile() { // функция получения содержимого файла
	ifstream file;
	string str;
	file.open("text.txt"); // открыть файл для чтения
	while (getline(file, str)) { // пока в файле есть строки: вывести строки
		cout << str << endl;
	}
	file.close(); // закрыть файл
}
void Caesar() {               //цезарь
	int n;
	while (true) {
		cout << "Enter key: ";
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "The key must be integer " << endl;
		}
		else if (n > 0) {

			cin.ignore(INT_MAX, '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "The key must be natural " << endl;
		}
	}
	string str = getString("Phrase: ", 8);
	inFile("Key: " + to_string(n));
	n = n % 26;
	for (auto& c : str)
	{
		if (c <= 'a' && c >= 'z' || c <= 'A' && c >= 'Z') {
			continue;
		}
		if (c >= 'a' && c <= 'z')
			c = ((c - 'a' + n) % 26) + 'a';
		else if (c >= 'A' && c <= 'Z')
			c = ((c - 'A' + n) % 26) + 'A';
	}
	cout << str << endl;
	inFile("Caesar: " + str);

}
void UnCaesar() {
	int n = stoi(getString("Key: ", 5));
	string str = getString("Caesar: ", 8);
	n = n % 26;
	for (auto& c : str)
	{
		if (c <= 'a' && c >= 'z' || c <= 'A' && c >= 'Z') {
			continue;
		}
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
	cout << str << endl;
	inFile("Caesar decryption: " + str);
}
void DoubleTable() {             //двойная табличная
	string st, kl, kk, kl2, kk2, stOut = "";
	char x;
	int n, m, k;
	k = 0;
	st = getString("Phrase: ", 8);
	
	for (int i = 0; i < 3; i++) {
		cout << "Enter first key: ";
		cin >> kl;
		cout << "Enter second key: ";
		cin >> kl2;
		kk = kl;
		kk2 = kl2;
		n = size(kl);
		m = size(kl2);
		try {
			if (m * n != size(st))
				throw 1;
			break;
		}
		catch (...) {
			cout << "Keys must match text size!" << endl;
			cout << "Text size: " << size(st) << endl;;
		}
		if (i == 2)
			exit(0);
	}
	inFile("Key 1: " + kl);
	inFile("Key 2: " + kl2);
	vector <vector <char>> v(m, vector <char>(n));
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
	cout << stOut << endl;
	inFile("DoubleTable: " + stOut);
}
void UnDoubleTable() {
	char x;
	int n, m, k;
	string stOut = "";
	string st = getString("DoubleTable: ", 13);
	string kl = getString("Key 1: ", 7);
	string kl2 = getString("Key 2: ", 7);
	string kk = kl;
	string kk2 = kl2;
	n = size(kl);
	m = size(kl2);
	vector <vector <char>> v(m, vector <char>(n));
	vector <vector <char>> vt(m, vector <char>(n));
	vector <vector <char>> vtt(m, vector <char>(n));
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
	cout << stOut << endl;
	inFile("DoubleTable decryption: " + stOut);
}
void Tarab() {          //tarabarskaya gramota 
	string word = getString("Phrase: ", 8);
	int k = size(word);
	string stOut = "";
	for (int i = 0; i < k; i++) {
		if (word[i] <= 'a' && word[i] >= 'z' || word[i] <= 'A' && word[i] >= 'Z') {
			continue;
		}
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
		stOut += word[i];
	}
	cout << stOut << endl;
	inFile("Tarabarskaya: " + stOut);
}
void UnTarab() {          //tarabarskaya gramota decryption 
	string word = getString("Tarabarskaya: ", 14);
	int k = size(word);
	string stOut = "";
	for (int i = 0; i < k; i++) {
		if (word[i] <= 'a' && word[i] >= 'z' || word[i] <= 'A' && word[i] >= 'Z') {
			continue;
		}
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
		stOut += word[i];
	}
	cout << stOut << endl;
	inFile("Tarabarskaya decryption: " + stOut);
}

