#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include "File.h"

using namespace std;

void open_inputFile(fstream& inputFile, char inFileName[]);
void open_outputFile(fstream& outputFile, char outFileName[]);
void printFile(fstream& outputFile);

const int SIZE = 81;

int main() {
	int filterType = 0;
	fstream inputFile, outputFile;

	char inFileName[SIZE];
	char outFileName[SIZE];

	open_inputFile(inputFile, inFileName);
	open_outputFile(outputFile, outFileName);

	cout << "\n Enter 1 for Upper case and 2 for Encryption: ";
	cin >> filterType;

	if (filterType == 1) {
		UpperCaseFilter upperFilter;
		upperFilter.doFilter(inputFile, outputFile);
	} else {
		EncryptionFilter encryptionfilter;
		encryptionfilter.doFilter(inputFile, outputFile);
	}

	inputFile.close();
	outputFile.close();

	outputFile.open(outFileName);

	cout << "\n Filter file is : " << endl;

	printFile(outputFile);

	outputFile.close();

	_getch();
	return 0;
}

void open_inputFile(fstream& inputFile, char inFileName[]) {
	cout << "\n This program modified a version of a text file";
	cout << "\n Enter name of input file (input.txt): ";
	cin >> inFileName;

	inputFile.open(inFileName, ios::in);

	if (!inputFile) {
		cout << "\n The file " << inFileName << " can't be opened." << endl;
		exit(1);
	}

	cout << "\n Original file contents is : " << endl;

	printFile(inputFile);
	cout << endl;
}

void open_outputFile(fstream& outputFile, char outFileName[]) {
	cout << "\n Enter name of output file (output.txt): ";
	cin >> outFileName;

	outputFile.open(outFileName, ios::out);

	if (!outputFile) {
		cout << "\n The file " << outFileName << " can't be opened." << endl;
		exit(1);
	}

}

void printFile(fstream& outputFile) {
	outputFile.clear();
	outputFile.seekg(0, ios::beg);

	char ch = outputFile.get();

	while (!outputFile.eof()) {
		cout << ch;
		ch = outputFile.get();
	}

	outputFile.clear();
	outputFile.seekg(0, ios::beg);

}