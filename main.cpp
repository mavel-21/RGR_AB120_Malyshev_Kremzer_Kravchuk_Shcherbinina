#include <iostream>
#include <string>
#include "interface.h"
#include "gronsfeld.h"
#include "polybiusSquare.h"
#include "simpleTablePermutation.h"
#include "atbash.h"
#include "keywordABC.h"
#include "tableCypher.h"
#include "Caesar.h"
#include "doubleTable.h"
#include "tarab.h"

using namespace std;

int main() {
    ofstream file, outfile;
    file.open("input.txt"); // открыть файл
    outfile.open("info.txt");
    // file.open("info.txt", ofstream::app);


    string dialogStr; // диалоговая строка
    string pinAdmin = "1111"; // дефолтный пинкод
    cout << endl << "______________________________Hello______________________________" << endl <<
        "__________To display a list of all commands write: help__________" << endl <<
        "____Set a password, enter a passphrase, and choose encryption____" << endl << endl;

    while (true) {
        cout << "Enter a command: ";
        getline(cin, dialogStr); // ввод команды
        if (dialogStr == "input") { // команда ввода фразы в файл
            string str; // строка
            int isValid = 0;
            while (isValid == 0)
            {
                isValid = 1;
                try {
                    cout << "Enter a string: ";
                    getline(cin, str); // ввод строки (фразы)
                    for (char elem : str)
                    {
                        if ((elem < 0) || (elem > 255))
                        {
                            isValid = 0;
                            throw("INCORRECT_INPUT");
                        }
                    }
                }
                catch (...)
                {
                    cout << "    [ERROR] Line contains non-ASCII characters. Please try again.\n";
                }
            }
            inFile("Phrase: " + str); //запись этой строки (фразы) в файл
            cout << "    [THE FILE HAS BEEN UPDATED]" << endl << endl;
        }
        else if (dialogStr == "clear") { // команда очистки файла
            clearFile(); // обращение к функции очистки файла
            cout << "    [THE FILE HAS BEEN CLEARED]" << endl << endl;
        }
        else if (dialogStr == "get") { // команда получения содержимого файла
            cout << "    [FILE CONTENTS]" << endl;
            getFile(); // обращение к функции получения содержимого файла
            cout << endl;
        }
        else if (dialogStr == "random")
        {
            srand(time(NULL));
            vector<string> myABC = { "the", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "jackdaws", "love", "my", "big", "sphinx", "of", "quartz", "five", "boxing", "wizards", "jump", "quickly" };
            int ABClen = myABC.size(), ind;
            string randstr = "Phrase: ";
            for (int i = 0; i < 5; i++)
            {
                ind = rand() % ABClen;
                randstr = randstr + myABC[ind];
                randstr.push_back(' ');
            }
            inFile(randstr);
            cout << "    [SUCCESS]" << endl;
        }
        else if (dialogStr == "encrypt") {
            string encryption_str;
            int encryption;
            cout
                << "\t1. Gronsfeld cipher\n\t2. Encryption using the square of Polybius\n\t3. Simple table permutation\n\t4. Atbash cipher\n\t5. Keyword cipher\n\t6. Table cipher with a keyword\n\t7. Caesar cipher\n\t8. Double table permutation\n\t9. 'Tarabarskaya gramota'\n\tAny other character: go back\nChoose encryption (1-9): ";
            getline(cin, encryption_str);
            if (encryption_str == "1" || encryption_str == "2" || encryption_str == "3" || encryption_str == "4" ||
                encryption_str == "5" || encryption_str == "6" || encryption_str == "7" || encryption_str == "8" ||
                encryption_str == "9")
                encryption = encryption_str[0] - '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            string pinUser; // пинкод, вводимый пользователем
            switch (encryption) {
            case 1: {// шифровка Гронсфельда
                cout << endl << "    [Gronsfeld encryption]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    Gronsfeld();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                pinUser = "";
                break;
            }
            case 2: {
                cout << endl << "    [Polybius square]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    square();
                    PolybiusSquare();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                pinUser = "";
                break;
            }
            case 3: {
                cout << endl << "    [Simple table permutation]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    STP();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                pinUser = "";
                break;
            }
            case 4: {
                cout << endl << "    [Atbash cipher]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    atbash();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 5: {
                cout << endl << "    [Keyword cipher]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    keywordABC();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 6: {
                cout << endl << "    [Table cipher with a keyword]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    tableCypher();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 7: {
                cout << endl << "    [Caesar]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    Caesar();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 8: {
                cout << endl << "    [Double table permutation]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    DoubleTable();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 9: {
                cout << endl << "    ['Tarabarskaya gramota']" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    Tarab();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            default:
                break;
            }
            system("notepad.exe input.txt");
        }
        else if (dialogStr == "decrypt") {
            string decryption_str;
            int decryption;
            cout
                << "\t1. Gronsfeld cipher\n\t2. Decryption using the square of Polybius\n\t3. Simple table permutation\n\t4. Atbash cipher\n\t5. Keyword cipher\n\t6. Table cipher with a keyword\n\t7. Caesar cipher\n\t8. Double table permutation\n\t9. 'Tarabarskaya gramota'\n\tAny other character: go back\nChoose decryption (1-9): ";
            getline(cin, decryption_str);
            if (decryption_str == "1" || decryption_str == "2" || decryption_str == "3" || decryption_str == "4" ||
                decryption_str == "5" || decryption_str == "6" || decryption_str == "7" || decryption_str == "8" ||
                decryption_str == "9")
                decryption =
                decryption_str[0] -
                '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            string pinUser; // пинкод, вводимый пользователем
            switch (decryption) {
            case 1: {// расшифровка Гронсфельда
                cout << endl << "    [Gronsfeld decryption]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antiGronsfeld();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                pinUser = "";
                break;
            }
            case 2: {
                cout << endl << "    [Decryption by Polybius square]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antiPolybiusSquare();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                pinUser = "";
                break;
            }
            case 3: {
                cout << endl << "    [Simple table permutation]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antiSTP();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                pinUser = "";
                break;
            }
            case 4: {
                cout << endl << "    [Atbash decryption]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antiatbash();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                pinUser = "";
                break;
            }
            case 5: {
                cout << endl << "    [Keyword decryption]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antikeywordABC();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 6: {
                cout << endl << "    [Table cipher with a keyword]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antitableCypher();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 7: {
                cout << endl << "    [Caesar]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antiCaesar();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 8: {
                cout << endl << "    [Double table permutation]" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antiDoubleTable();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            case 9: {
                cout << endl << "    ['Tarabarskaya gramota']" << endl << endl;
                cout << "Please enter the pincode: ";
                getline(cin, pinUser); // ввод пинкода
                if (checkPincode(pinUser, pinAdmin)) { // проверка того, совпадает ли заданный пинкод с вводимым
                    cout << "    [Pincode validation passed successfully!]" << endl;
                    antiTarab();
                }
                else cout << "    [Pincode is not correct!]" << endl;
                break;
            }
            default:
                break;
            }
            system("notepad.exe input.txt");
        }
        else if (dialogStr == "help") { // команда вызова списка команд
            cout << "    [COMMANDS]" << endl;
            cout << "input -- Writing a line to a file;" << endl;
            cout << "get -- Displaying the contents of a file;" << endl;
            cout << "clear -- Cleaning up the contents of a file;" << endl;
            cout << "pin -- Pincode setting;" << endl;
            cout << "encrypt -- Choice of encryption" << endl;
            cout << "decrypt -- Choice of decryption" << endl;
            cout << "random -- Random text to encrypt/decrypt" << endl;
            cout << "stop -- Stop program;" << endl << endl;

        }
        else if (dialogStr == "stop") { // остановка программы
            cout << "    [The program has been stopped]" << endl;
            break;
        }
        else { // команды не существует
            cout << endl << "[ERROR_217][THIS COMMAND DOES NOT EXIST][ERROR_217]" << endl << endl;
        }
    }
    return 0;
}
