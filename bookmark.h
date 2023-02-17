#ifndef BOOKMARK_H
#define BOOKMARK_H
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;
class Bookmark {
        public:
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


//counter for book array and user array
    int bookCounter = 0;
    int userCounter=0;

//function to increase counter
    void increment(int a) {
        bookCounter = ++a;
    }

    void increment1(int b) {
        userCounter= ++b;
    }
//function to decrease counter
    void decrement(int a) {
        bookCounter = --a;
    }

    void decrement1(int b){
        userCounter= --b;


    }


//limiting number of entered books, sve premjesti u bookmark klasu
    Book books[10];
    User users[10];




};
#endif
