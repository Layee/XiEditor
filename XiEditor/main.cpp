#include <iostream>
#include <fstream>
#include <cctype>
#include<conio.h>
#include <string>
#include "XiEditor.h"
using namespace std;


void main(int argc,char *argv[]) {

	// while (true) forever
	

	XiEditor editor(argv[1]);
	
	for (;;) { // loop forever without crashing
		system("cls");
		editor.printLines();
		editor.navigate();
	}
	system("pause");
}