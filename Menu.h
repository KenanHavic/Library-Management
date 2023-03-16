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
		void userOptions() {
			cout << "USER\n";
            cout << "[1]ADD USER\n";
        	cout << "[2]DELETE USER\n";
            cout << "[3]EDIT USER\n";
            cout << "[4]VIEW ALL USERS\n";
            cout << "[5]EXIT\n";
		}	
		void bookOptions() {
			cout << "BOOK\n";
            cout << "[1]ADD BOOK\n";
            cout << "[2]DELETE BOOK\n";
            cout << "[3]EDIT BOOK\n";
            cout << "[4]SEARCH BOOK\n";
            cout << "[5]VIEW ALL BOOKS\n";
            cout << "[6]TOP 3 BOOKS OF THE WEEK\n";
            cout << "[7]EXIT\n";
		}
};
#endif
