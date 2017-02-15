#pragma once
#include <string>
using namespace std;
class XiEditor
{
public:
	XiEditor();
	XiEditor(char *);
	void printLines();
	void navigate();
	void  outerBound();
	//~XiEditor();


private:
	string * _arrayBuffer;
	int _capacity;
	int _numOfElement;
	int _currentLine;
	int _currentPosition;


};

