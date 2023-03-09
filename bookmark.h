#ifndef BOOKMARK_H
#define BOOKMARK_H

#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
#include "book.h"

using namespace std;

class Bookmark {
public:
	Book books[20];
	User users[20];
    void addUser();
    void editUser();
    void viewAllUsers();
    void deleteUser();
    void addBook();
    void deleteBook();
    void editBook();
    void searchBook();
    void viewAllBooks();
    void addDefaultBooks();
    void borrowBook();
    void displayTopBooks();
    
    bool canAddBook() {
        return bookCounter < 20;
    }
    
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
    
    void decrementUser(){
        userCounter--;
    }
    
    bool isAlreadyRegistered(const string& enteredUsername, const string& enteredPassword) {
        ifstream file("users.txt");
        if (file.is_open()) {
            string username, password;
            while (file >> username >> password) {
                if (username == enteredUsername && password == enteredPassword) {
                    file.close();
                    return true;
                }
            }
            file.close();
        }
        return false;
    }
    
    bool registerUser(const string& username, const string& password) {
        ifstream file("users.txt");
        if (file.is_open()) {
            string existingUsername, existingPassword;
            while (file >> existingUsername >> existingPassword) {
                if (existingUsername == username) {
                    file.close();
                    return false;
                }
            }
            file.close();
        }
    }
};
#endif

