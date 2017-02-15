#include "XiEditor.h"
#include <iostream>
#include <cctype>
#include<conio.h>
using namespace std;
#include <fstream>


XiEditor::XiEditor() {
	_arrayBuffer = new string[10]; // dynamic  allocate memory
	_numOfElement = 0;
	
}

XiEditor::XiEditor(char * fileName)
{
	ifstream userFile;
	userFile.open(fileName); // open the file

	_currentLine = 0;
	_numOfElement = 0;

	string skipLine;

	// check if the file exit
	if (!userFile.is_open()) {
		cout << "This file does exist " << endl;
		exit(EXIT_SUCCESS); // close file when file is not located
	}

	
	while(!userFile.eof()) {
		getline(userFile, skipLine);
		_numOfElement++;
	}
	
	userFile.close();
	userFile.open(fileName);
	_arrayBuffer = new string[_numOfElement]; // dynamic  allocate memory

	

	
	//reading the file
	for (int i = 0; !userFile.eof(); i++)
	{
		getline(userFile, _arrayBuffer[i]);
	}
	
	
	userFile.close(); // close the file after reading it

	
	
}




void XiEditor::printLines() {
	for (int j = 0; j < _numOfElement; j++) {
		if (j == _currentLine) {
			cout << "*";
			cout << _arrayBuffer[j] << endl;
			cout << " ";
			for (int i = 0; i < _currentPosition; i++) {
				cout << " ";
			}
			cout << "^" << endl;

		}
		else {
			cout << " ";
			cout << _arrayBuffer[j] << endl;
			
		}

		
	}

}



void XiEditor::navigate() {

	char command;
	command = _getch();

	switch (command)
	{
	case 'j':
	case 'J':
		_currentLine += 1;
		break;

	case 'K':
	case 'k':
		_currentLine -= 1;
		break;

	case 'l':
	case 'L':
		_currentPosition += 1;
		break;

	case 'h':
	case 'H':
		_currentPosition -= 1;
		break;
	}
	outerBound();
}


void XiEditor::outerBound() {
	if (_currentLine < 0) { // outer  bound reset current = 0;
		_currentLine = 0;
	}
	
	else if (_currentLine > _numOfElement - 1) {
		_currentLine = _numOfElement - 1;
	}

	else if (_currentPosition < 0 ) {
		  
		_currentPosition = 0;

	}

	else if (_currentPosition >= _arrayBuffer[_currentLine].length()) { // get the end of the string
		_currentPosition = _arrayBuffer[_currentLine].length() - 1; // reset the buffer back to the end of the string

	}


	
}