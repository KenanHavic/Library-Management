#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class User {
        private:
            string firstName, lastName,ID;
        public:
        	void setfirstName(string firstName) { this->firstName=firstName; }
        	void setlastName(string lastName) { this->lastName=lastName; }
        	void setID(string ID) { this->ID=ID; }
        	string getFirstName() { return firstName; }
        	string getLastName() { return lastName; }
        	string getID() { return ID; }
        	
        	void updateUser(string firstName, string lastName, string ID) {
        		setfirstName(firstName);
                setlastName(lastName);
                setID(ID);
            }
};
#endif
