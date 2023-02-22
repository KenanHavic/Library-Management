#ifndef MENU_H
#define MENU_H
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class Menu {
	public:
		void displayMainMenu() {
   			cout << "LIBRARY MANAGEMENT\n\n";
   			cout << "[1] USER\n";
    		cout << "[2] BOOK\n";
    		cout << "[3] EXIT\n\n";
    		cout << "ENTER SELECTION: ";
		}
};
#endif
