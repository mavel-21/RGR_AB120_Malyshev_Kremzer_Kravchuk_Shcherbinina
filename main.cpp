//Список 4 подгруппы:
//A) Кравчук Б.Д.
//B) Кремзер А.Д.
//C) Малышев П.А.
//D) Щербинина Д.В.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void inFile(string inStr);
void inFile(int inNum);
void clearFile();
void getFile();
string getString ();

void reverseArray(int arr[], int n);

void Gronsfeld() {
    int key;
    string strIn = getString();
    cout << "Enter key: ";
    cin >> key;
    inFile(key);
    string strOut;
    int keyArr[10];
    int lenOfKey = 0;
    while (key > 0) {
        keyArr[lenOfKey] = key%10;
        key/=10;
        lenOfKey++;
    }
    reverseArray(keyArr, lenOfKey);

    for (int i = 0, count = 0; i < strIn.length(); i++, count++) {
        char c = strIn[i] + keyArr[count];
        strOut.push_back(c);
        if (count == lenOfKey) count = 0;
        if (strIn[i] == ' ') {
            strOut.push_back(' ');
            count--;
            continue;
        }
    }
    inFile(strOut);
}

int main() {
    string dialogStr;
    while (true) {
        cout << "Enter a command: ";
        getline(cin, dialogStr, '\n');
        if (dialogStr == "input") {
            string str;
            cout << "Enter a string: ";
            cin.ignore();
            getline(cin, str, '\n');
            inFile(str);
            cout << "    [THE FILE HAS BEEN UPDATED]" << endl << endl;
        }
        else if (dialogStr == "clear") {
            clearFile();
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        }
        else if (dialogStr == "get") {
            cout << "    [FILE CONTENTS]" << endl;
            getFile();
            cout << endl;
        }

        else if (dialogStr == "gronsfeld") {
            Gronsfeld();
        }
        else if (dialogStr == "help") {
            cout << "    [COMMANDS]" << endl;
            cout << "input -- Writing a line to a file;" << endl;
            cout << "get -- Displaying the contents of a file;" << endl;
            cout << "clear -- Cleaning up the contents of a file;" << endl;
            cout << "gronsfeld -- Gronsfeld cipher" << endl;
            cout << "stop -- Stop program;" << endl << endl;

        }
        else if (dialogStr == "stop") {
            cout << "    [The program has been stopped]" << endl;
            break;
        }
        else {
            cout << endl << "[ERROR_217][THIS COMMAND DOES NOT EXIST][ERROR_217]" << endl << endl;
        }
    }
    return 0;
}

void inFile(string inStr) {
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt", ofstream::app);
    file << inStr << endl;
    file.close();
}

void inFile(int inNum) {
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt", ofstream::app);
    file << "Key:" << inNum << endl;
    file.close();
}

void clearFile() {
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt");
    file.close();
}

void getFile() {
    ifstream file;
    string str;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt");
    while (getline (file,str))
    {
        cout<< str << endl;
    }
    file.close();
}

string getString () {
    ifstream file;
    string str;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt");
    getline (file,str, '\n');
    file.close();
    return str;
}

void reverseArray(int arr[], int n) {
    for (int low = 0, high = n - 1; low < high; low++, high--){
        swap(arr[low], arr[high]);
    }
}