#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter information. Press Enter on an empty line to finish:" << endl;
	string userInformation;
	string line;

	while (getline(cin, line) && !line.empty())
	{
		userInformation += line + "\n";
	}

	ofstream outputFile("example.txt", ios::app);
	if (outputFile.is_open())
	{
		outputFile << userInformation;

		outputFile.close();
		cout << "File written successfully." << endl;
	}
	else
	{
		cerr << "Unable to open the file for writing." << endl;
		return 1;
	}

	ifstream inputFile("example.txt");
	if (inputFile.is_open())
	{
		cout << "Reading from the file:" << endl;

		string content;
		while (getline(inputFile, content))
		{
			cout << content << endl;
		}

		inputFile.close();
	}
	else
	{
		cerr << "Unable to open the file for reading." << endl;
		return 1;
	}
	return 0;
}
