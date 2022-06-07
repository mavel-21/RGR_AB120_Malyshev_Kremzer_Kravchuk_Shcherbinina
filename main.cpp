#include <iostream>
#include <string>
#include <vector>
#include "interface.h"

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
            if (encryption_str.size() == 1 && isdigit(encryption_str[0]) && stoi(encryption_str) != 0)
                encryption = encryption_str[0] - '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            cipherExec(encryption, 1, pinAdmin);
        }
        else if (dialogStr == "decrypt") {
            string decryption_str;
            int decryption;
            cout
                << "\t1. Gronsfeld cipher\n\t2. Decryption using the square of Polybius\n\t3. Simple table permutation\n\t4. Atbash cipher\n\t5. Keyword cipher\n\t6. Table cipher with a keyword\n\t7. Caesar cipher\n\t8. Double table permutation\n\t9. 'Tarabarskaya gramota'\n\tAny other character: go back\nChoose decryption (1-9): ";
            getline(cin, decryption_str);
            if (decryption_str.size() == 1 && isdigit(decryption_str[0]) && stoi(decryption_str) != 0)
                decryption = decryption_str[0] - '0';
            else {
                cout << "   [GO BACK]" << endl << endl;
                continue;
            }
            cipherExec(decryption, 2, pinAdmin);
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
