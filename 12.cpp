#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 100;

void encryptFile(const char* inName, const char* outName) {
    ifstream inFile(inName);
    ofstream outFile(outName);

    if (!inFile) {
        cout << "Error opening " << inName << endl;
        return;
    }

    while (!inFile.eof()) {
        char input;
        inFile.get(input);
        input += 10;
        outFile.put(input);
    }

    cout << "The file has been Encrypted." << endl;

    inFile.close();
    outFile.close();
}

void decryptFile(const char* inName, const char* outName) {
    ifstream inFile(inName);
    ofstream outFile(outName);

    if (!inFile) {
        cout << "Error opening " << inName << endl;
        return;
    }

    while (!inFile.eof()) {
        char input;
        inFile.get(input);
        input -= 10;
        outFile.put(input);
    }

    cout << "The file has been Decrypted." << endl;

    inFile.close();
    outFile.close();
}

int main() {
    char inName[SIZE];
    char outName[SIZE];
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Encrypt a file" << endl;
        cout << "2. Decrypt a file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the input file name: ";
                cin.ignore();
                cin.getline(inName, SIZE);
                cout << "Enter the output file name: ";
                cin.getline(outName, SIZE);
                encryptFile(inName, outName);
                break;
            case 2:
                cout << "Enter the input file name: ";
                cin.ignore();
                cin.getline(inName, SIZE);
                cout << "Enter the output file name: ";
                cin.getline(outName, SIZE);
                decryptFile(inName, outName);
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
