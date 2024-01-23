#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void displayCounts(int lc, int cc, int wc) {
    cout << "\n Number of Sentences: " << lc;
    cout << "\n Number of Characters: " << cc;
    cout << "\n Number of Words: " << wc << endl;
}

int main() {
    char data[80];
    int wc = 0;
    int cc = 0;
    int lc = 0;
    int choice;

    ofstream fout("poem.txt", ios::app);

    if (!fout.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter data\n";
        cout << "2. Display counts\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter data (enter a blank line to stop):\n";
                while (true) {
                    cin.getline(data, 80);

                    if (strlen(data) == 0) {
                        break;
                    }

                    fout << data << endl;

                    int n = strlen(data);
                    cc += n;
                    lc++;

                    // Counting words based on spaces
                    bool inWord = false;
                    for (int i = 0; i < n; i++) {
                        if (data[i] == ' ' || data[i] == '\t' || data[i] == '\n') {
                            inWord = false;
                        } else if (!inWord) {
                            inWord = true;
                            wc++;
                        }
                    }
                }
                break;
            case 2:
                displayCounts(lc, cc, wc);
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    fout.close();

    return 0;
}
