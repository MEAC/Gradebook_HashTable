#include "HashTable.h"
#include "clearScreen.h"
#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[]) {
	ofstream outputFile;
	string input;
	string fileName;
	char createNewFile;

	cout << endl << "Welcome to your gradebook" << endl;
	cout << "----------------------" << endl;
	cout << "Do you wish to create a new gradebook file for a class (Y/N) ?" << endl;
	cin >> createNewFile;
	if (createNewFile == 'Y' || createNewFile == 'y') {
		cout << "Enter file name: ";
		cin >> fileName;

		outputFile.open(fileName.c_str());
		cout << "The file you created is " << fileName << endl;
	}

	HashMap hash;
	int key, value;
	int choice;
	while (true) {
		cout << endl;
		cout << "1. Insert a grade into the gradebook" << endl;
		cout << "2. Search a students grade with their student ID" << endl;
		cout << "3. Delete a students grade with their student ID" << endl;
		cout << "Enter your choice (1-3): ";
		cout << "WARNING!! ANY CHARACTER OR NUMBER ENTERED OTHER THAN (1-3) WILL TERMINATE THIS PROGRAM!" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the students grade: ";
			cin >> value;
			cout << "Enter the ID of the student, numbers only: ";
			cin >> key;

			hash.Insert(key, value);
			break;

		case 2:
			cout << "Enter the ID of the student to be searched: ";
			cin >> key;
			if (hash.Search(key) == -1) {
				cout << "No grade found at " << key << " ID" << endl;
				//cout << "Press ENTER on the keyboard to continue . . ." << endl;
				//getchar();
				//clearScreen();
				continue;
			}
			else {
				cout << "Grade at students " << key << " : ";
				cout << hash.Search(key) << endl;
			}
			break;

		case 3:
			cout << "Enter the student ID number to delete their grade: ";
			cin >> key;
			hash.Remove(key);
			break;

		default:
			//cout << "Sorry, you inputed an invalid choice";
			exit(1);
		}
	}

	return 0;
}
