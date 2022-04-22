#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string setPincode();

bool checkPincode(string pinUser, string pinAdmin);

void inFile(string inStr);

void keyInFile(string inKey);

void clearFile();

void getFile();

string getString();

void Gronsfeld() {
    string key;
    string strIn = getString();
    cout << "Enter key: ";
    getline(cin, key);
    keyInFile(key);
    string strOut;
    int keyArr[10];
    for (int i = 0; i < key.length(); i ++) {
        keyArr[i] = key[i]-'0';
    }

    for (int i = 0, count = 0; i < strIn.length(); i++, count++) {
        if (count == key.length()) count = 0;
        if (strIn[i] == ' ') {
            strOut.push_back(' ');
            count--;
            continue;
        } else {
            char c = strIn[i] + keyArr[count];
            strOut.push_back(c);
        }
    }
    inFile(strOut);
}

int main() {
    string dialogStr;
    string pincode = "0000";
    cout << endl << "______________________________Hello______________________________" << endl <<
            "__________To display a list of all commands write: help__________" << endl <<
            "____Set a password, enter a passphrase, and choose encryption____" << endl << endl;
    while (true) {
        cout << "Enter a command: ";
        getline(cin, dialogStr);
        if (dialogStr == "input") {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);
            inFile(str);
            cout << "    [THE FILE HAS BEEN UPDATED]" << endl << endl;
        }
        else if (dialogStr == "pin") {
            pincode = setPincode();
        }
        else if (dialogStr == "clear") {
            clearFile();
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        } else if (dialogStr == "get") {
            cout << "    [FILE CONTENTS]" << endl;
            getFile();
            cout << endl;
        } else if (dialogStr == "gronsfeld") {
            string pinUser;
            cout << "Please enter the pincode: ";
            getline(cin, pinUser);
            if (pincode == "0000") cout << "    [Pincode not set!]" << endl;
            else if (checkPincode(pinUser, pincode)) {
                cout << "    [Pincode validation passed successfully!]" << endl;
                Gronsfeld();
            }
            else cout << "    [Pincode is not correct!]" << endl;
        } else if (dialogStr == "help") {
            cout << "    [COMMANDS]" << endl;
            cout << "input -- Writing a line to a file;" << endl;
            cout << "get -- Displaying the contents of a file;" << endl;
            cout << "clear -- Cleaning up the contents of a file;" << endl;
            cout << "pin -- Pincode setting;" << endl;
            cout << "gronsfeld -- Gronsfeld cipher" << endl;
            cout << "stop -- Stop program;" << endl << endl;

        } else if (dialogStr == "stop") {
            cout << "    [The program has been stopped]" << endl;
            break;
        } else {
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

void keyInFile(string inKey) {
    ofstream file;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt", ofstream::app);
    file << "Key:" << inKey << endl;
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
    while (getline(file, str)) {
        cout << str << endl;
    }
    file.close();
}

string getString() {
    ifstream file;
    string str;
    file.open("/home/pavel/Документы/Уник/Информатика/progRgr/encryptions.txt");
    getline(file, str, '\n');
    file.close();
    return str;
}

string setPincode() {
    string pincode;
    cout << "Enter pincode: ";
    getline(cin, pincode);
    return pincode;
}

bool checkPincode(string pinUser, string pinAdmin) {
    return (pinUser == pinAdmin);
}