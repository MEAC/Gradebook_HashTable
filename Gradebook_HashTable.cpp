#include "stdafx.h"
#include "HashMap.h"
#include "clearScreen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

int main(int argc, char * argv[]) {
	ofstream outputFile;
	string input;
	string fileName;
	char createNewFile;

	HashMap hash;
	int key, value;
	int choice;

	cout << endl << "Welcome to your gradebook" << endl;
	cout << "--------------------------" << endl;
	cout << "Do you wish to create a new gradebook file for a class (Y/N) ?" << endl << endl;
	cout << "*WARNING* - not creating a gradebook file will not save your progress when this program is terminated . . ." << endl << endl;
	cout << "Your Response : ";
	cin >> createNewFile;
	
	if (cin.fail()) {
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if (createNewFile == 'Y' || createNewFile == 'y') {
		cout << "Enter file name, with the type of file extension (example: Joe2018COMSC_Midterm1Gades.txt) : ";
		cin >> fileName;
		clearScreen();

		outputFile.open(fileName.c_str());
		cout << "The file you created is " << fileName << endl << endl;
		outputFile << "Student ID" << setw(15) << "Grade(s) %" << endl;
		outputFile << "--------------" << setw(19) << "--------------" << endl;

		if (!outputFile) {
			cerr << "An error has occured opening the file . . ." << endl;
			cerr << "Now shutting down . . . " << endl;
			exit(1);
		}
	}

	do {
		cout << endl << endl;
		cout << "Gradebook options" << endl;
		cout << "--------------------------" << endl;
		cout << "1. Insert a grade into the gradebook" << endl;
		cout << "2. Search a students grade with their student ID" << endl;
		cout << "3. Delete a students grade with their student ID" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice (1-4) : ";
		cin >> choice;

		if (cin.fail()) {
			//cerr << "ERROR -- You did not enter an integer";
			cin.clear();

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		switch (choice) {
		case 1:
			clearScreen();
			cout << "Enter the students grade (without percentage symbol) : ";
			cin >> value;
			cout << "Enter the ID of the student (numbers only) : ";
			cin >> key;

			outputFile << key << setw(19) << value << endl;
			hash.Insert(key, value);
			break;

		case 2:
			clearScreen();
			cout << "Enter the ID of the student to be searched: ";
			cin >> key;
			cout << "Grade(s) at student ID " << key << " : ";

			if (hash.Search(key) == -1) {
				cout << "No grade(s) found at " << key << " ID" << endl;
				continue;
			}
			break;

		case 3:
			clearScreen();
			cout << "Enter the student ID number to delete their grade: ";
			cin >> key;
			hash.Remove(key);
			break;

		case 4:
			clearScreen();
			cout << "Thank you for grading!" << endl;
			outputFile.close();
			exit(1);

		default:
			clearScreen();
			cout << "\nInvalid choice, please enter a valid choice . . . \n";
		}
	} while (choice != 4);
	outputFile.close();
	return 0;
}
