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

    void addUser();
    void editUser();
    void viewAllUsers();
    void deleteUser();

    void addBook();
    void deleteBook();
    void editBook();
    void searchBook();
    void viewAllBooks();
    void displayTopBooks();

    int bookCounter = 0;
    int userCounter = 0;

    void incrementBook() {
        bookCounter++;
    }

    void incrementUser() {
        userCounter++;
    }

    void decrementBook() {
        bookCounter--;
    }

    void decrementUser() {
        userCounter--;
    }
};

#endif

