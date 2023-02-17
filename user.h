#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class User {
        private:
            string firstName, lastName;
            string JMBG;

        public:
        //setter
        void setFirstName(string firstName) { this->firstName=firstName; }
        void setLastName(string lastName) { this->lastName=lastName; }
        void setJMBG(string JMBG) { this->JMBG=JMBG; }
        //getters

        string getFirstName() { return firstName; }
        string getLastName() { return lastName; }
        string getJMBG() { return JMBG; }
};
#endif
