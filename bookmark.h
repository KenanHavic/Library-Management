#ifndef BOOKMARK_H
#define BOOKMARK_H
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;
class Bookmark {
        public:
        	Book books[10];
    		User users[10];
            void displayMainMenu();
            void addUser(int userCounter);
            void editUser(int userCounter);
            void viewAllUsers(int userCounter);
            void deleteUser(int userCounter);

            void addBook(int bookCounter);
            void deleteBook(int bookCounter);
            void editBook(int bookCounter);
            void searchBook(int bookCounter);
            void viewAllBooks(int bookCounter);
            void displayTopBooks();



    int bookCounter = 0;
    int userCounter = 0;


    void incrementBook(int counterBook) {
        bookCounter = ++counterBook;
    }

    void incrementUser(int counterUser) {
        userCounter= ++counterUser;
    }

    void decrementBook(int counterBook) {
        bookCounter = --counterBook;
    }

    void decrementUser(int counterUser){
        userCounter= --counterUser;
	}



    




};
#endif
