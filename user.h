#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class User {
        private:
            string firstName, lastName;
            string ID;

        public:
        	void setFirstName(string firstName) { this->firstName=firstName; }
        	void setLastName(string lastName) { this->lastName=lastName; }
        	void setID(string ID) { this->ID=ID; }

        	string getFirstName() { return firstName; }
        	string getLastName() { return lastName; }
        	string getID() { return ID; }
};
#endif
