#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cctype>
#include "book.h"
#include "user.h"
#include "bookmark.h"
#include "Menu.h"
using namespace std;
Menu menu;
int main() {
    bool shouldLeaveApp = false;
    Bookmark *bookmark = new Bookmark();
    bookmark->addDefaultBooks();
    int choose;
    string username,password;
    cout << "Welcome to our program!\n";
    cout << "[1] Login\n";
    cout << "[2] Register\n";
    cout << "[3] Quit\n";
    cout << "Enter selection: ";
    cin >> choose;
    switch (choose) {
        case 1:
           bookmark->loginUser();
           break;
        case 2:
           bookmark->registerNewUser();
           break;
        case 3:
           cout << "\nThanks for using our library management\n" ;
           exit(0);
           break;
        default:
           cout << "Wrong selection" << endl;
           break;
    }
    const char PREMIUM_USER = 'p';
    const char REGULAR_USER = 'r';
    char enteredUserType;
    cout << "Select user type(P for premium, R for regular): ";
    cin >> enteredUserType;
    enteredUserType = tolower (enteredUserType);
    if (enteredUserType == PREMIUM_USER) {
        cout << "Welcome, "<< username << "!" << endl;
        cout << "You are a premium user." << endl;
        menu.displayMainMenu();
        cin >> choose;
        do {
            switch (choose) {
                case 1:
                    menu.userOptions();
                    int selection;
                    cout << "Enter selection: ";
                    cin >> selection;
                    switch (selection) {
                        case 1:
                            bookmark->addUser();
                            break;
                        case 2:
                            bookmark->deleteUser();
                            break;
                        case 3:
                            bookmark->editUser();
                            break;
                        case 4:
                            bookmark->viewAllUsers();
                            break;
                        case 5:
                            shouldLeaveApp = true;
                            break;
                        default:
                            cout << "Invalid input\n";
                            break;
                    }
                    break;
                case 2:
                    menu.bookOptions();
                    int choice;
                    cout << "Enter selection: ";
                    cin >> choice;
                    switch(choice) {
                        case 1:
                            bookmark->addBook();
                            break;
                        case 2:
                            bookmark->deleteBook();
                            break;
                        case 3:
                            bookmark->editBook();
                            break;
                        case 4:
                            bookmark->searchBook();
                            break;
                        case 5:
                            bookmark->viewAllBooks();
                        case 6:
                            bookmark->displayTopBooks();
                            menu.displayMainMenu();
                            break;
                        default:
                            cout<<"Invalid input\n";
                            break;
                    }
                case 3:
                    shouldLeaveApp = true;
                    break;
                default:
                    cout << "Invalid input";
            }
        } while (!shouldLeaveApp); {
            cout << "Thanks for using our library management";}
        
    } else if (enteredUserType == REGULAR_USER) {
        cout << "Welcome, " << username << "!" << endl;
        cout << "You are a regular user." << endl;
        cout << "[1]USER\n";
        cout << "[2]BOOK\n";
        cout << "[3]EXIT\n";
        cout << "Enter selection: ";
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "USER\n";
                cout << "[1]VIEW ALL USERS\n";
                cout << "[2]EXIT\n";
                int selection;
                cout << "Enter selection: ";
                cin >> selection;
                switch(selection) {
                    case 1:
                        bookmark->viewAllUsers();
                        break;
                    case 2:
                        shouldLeaveApp = true;
                        break;
                    default:
                        cout<<"Invalid input.\n";
                        break;
                    }
            case 2:
                cout << "Book.\n";
                cout << "[1]View All Books\n";
                cout << "[2]EXIT\n";
                int choice;
                cout << "Enter selection: ";
                cin >> choice;
                switch(choice) {
                    case 1:
                        bookmark->viewAllBooks();
                        break;
                    case 2:
                        shouldLeaveApp = true;
                        break;
                    default:
                        cout << "Invalid input.\n";
                        break;
                }
        }
    }
    else {
        cout << "Invalid input." << endl;
    }
return 0;
}
void Bookmark::registerNewUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (this->registerUser(username, password)) {
        cout << "You are successfully registered" << endl;
    } else {
        cout << "Error: username already exists." << endl;
        exit(0);
      }
}
void Bookmark::loginUser() {
    string username, password;
    do {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (this->isAlreadyRegistered(username, password)) {
            cout << "Login successful" << endl;
            break;
        } else {
            cout << "Incorrect username or password!" << endl;
            cout << "Press 'y' to try again: ";
            char tryAgain;
            cin >> tryAgain;
            tryAgain = tolower(tryAgain);
            if (tryAgain != 'y') {
                exit(0);
                break;
            }
          }
    } while (true);
}
void Bookmark::addUser() {
    string firstName, lastName, ID;
    if (userCounter > 20) { 
        cout << "Max users reached...\n";
        return;
    }
    cout << "ADD USER\n\n";
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    do {
        cout << "Enter ID: ";
        cin >> ID;
        if (this->isValidID(ID)) {
            cout << "ID must have 13 digits" << endl;
        }
    } while (this->isValidID(ID));
    this->users[userCounter].updateUser(firstName, lastName, ID);
    this->incrementUser();
    cout << "\nUser added successfully." << endl;
}
void Bookmark::editUser() {
    string editId, firstName, lastName, ID, choice;
    cout << "EDIT USER\n\n";
    if (userCounter == 0) {
        cout << "There are no users to edit!" << endl;
        menu.displayMainMenu();
        return;
    }
    cout << "Enter JMBG: ";
    cin >> editId;
    User* userToEdit = findUserByID(editId);
    if (userToEdit != nullptr) {
        cout << "User found!\n\n";
        cout << "ID: " << userToEdit->getID() << endl;
        cout << "First name: " << userToEdit->getFirstName() << endl;
        cout << "Last name: " << userToEdit->getLastName() << endl;
        cout << "\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
        cin >> choice;
        if (choice == "1") {
            cout << "- First name: ";
            cin >> firstName;
            cout << "- Prezime: ";
            cin >> lastName;
            while (this->isValidID(ID)) {
                cout << "- Enter ID: ";
                cin >> ID;
                if (this->isValidID(ID)) {
                    cout << "ID must have 13 digits" << endl;
                }
            }
            userToEdit->updateUser(firstName, lastName, ID);
            cout << "User edited successfully!" << endl;
            menu.displayMainMenu();
        } else {
            menu.displayMainMenu();
        }
    } else {
        cout << "\nUser not found." << endl;
        menu.displayMainMenu();
    }
}

void Bookmark::viewAllUsers() {
    cout << "VIEW ALL USERS\n\n";
    if (this->userCounter == 0) {
            cout << "There are currently no users added." << endl;
            main();
    }
    for (int i = 0; i < this->userCounter; i++) {
        cout << "User details\n\n";
        cout << "First name: " << this->users[i].getFirstName() << endl;
        cout << "Last name: " << this->users[i].getLastName() << endl;
        cout << "ID: " << this->users[i].getID() << endl;

    }
    main();
}
void Bookmark::deleteUser() {
    string ID;
    int choice;
    bool found = false;
    cout << "DELETE USER\n\n";
    if (userCounter == 0) {
        cout << "There are no users to delete!" << endl;
        return;
    }
    cout << "Enter ID: ";
    cin >> ID;
    for (int i = 0; i < userCounter; i++) {
        if (this->users[i].getID() == ID) {
            found = true;
            cout << "\nUser found\n\n";
            cout << "Do you want delete?\n[1]Yes\n[2]No\n\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                this->users[i].updateUser("", "", "");
                for (int j = i; j < userCounter - 1; j++) {
                    this->users[j] = this->users[j + 1];
                }
                this->users[userCounter - 1].updateUser("", "", "");
                this->decrementUser();
                cout << "User successfully deleted." << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "\nUser not found!" << endl;
    }
}
void Bookmark::addBook() {
    string ISBN, title, author, publisher, categories;
    cout << "ADD BOOK\n\n";
    if  (bookCounter > 20) {
        cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS THAT CAN BE ADDED!";
        return;
    }
    while (this->isValidISBN(ISBN)) {
        cout << "- Enter ISBN: ";
        cin >> ISBN;
        if (this->isValidISBN(ISBN)) {
            cout << "ISBN must be equal to 5 characters..\n";
        }
    }
    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter publisher: ";
    getline(cin, publisher);
    cout << "Enter categories: ";
    getline(cin, categories);
    this->books[bookCounter].updateBook(ISBN, title, author, publisher, categories);
    this->incrementBook();
    cout << "\nBook added successfully.";
    menu.displayMainMenu();
} 
void Bookmark::deleteBook() {
    string ISBN;
    int choice;
    cout << "DELETE BOOK\n\n";
    if (bookCounter == 0) {
        cout<<"NO BOOK TO DELETE!";
        menu.displayMainMenu();
    }
    cout << "Enter ISBN: ";
    cin >> ISBN;
    for (int i = 0; i < bookCounter; i++) {
        if (this->books[i].isEqualTo(ISBN)) {
            cout << "\nBook found\n\n";
            cout << "Do you want to delete?\n[1]Yes\n[2]No\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                this->books[i].clearBook();
                for(int a = i; a < bookCounter; a++) {
                    this->books[a] = this->books[a+1];
                }
    this->books[19].clearBook();
    this->decrementBook();
    cout << "The book was successfully deleted.";
    menu.displayMainMenu();
            } else {
                menu.displayMainMenu();
              }
        }
    }
        cout << "\nBook not found.";
        menu.displayMainMenu();
}
void Bookmark::editBook() {
    string ISBN, title, author, publisher, categories,editIsbn,choice;
    cout << "EDIT BOOK\n\n";
    if (bookCounter == 0) {
        cout<<"There is no book to edit.\n\n";
        menu.displayMainMenu();
    }
    cout << "Enter ISBN: ";
    cin >> editIsbn;
    for (int i = 0; i < bookCounter; i++) {
        if (this->books[i].getISBN() == editIsbn) {
            cout << "Book found!\n\n";
            cout << "ISBN: "<< this->books[i].getISBN() << endl;
            cout << "Title: "<< this->books[i].getTitle() << endl;
            cout << "Author: "<< this->books[i].getAuthor() << endl;
            cout << "Publisher: "<< this->books[i].getPublisher() << endl;
            cout << "Categories: "<< this->books[i].getCategories() << endl;
            cout << "\nDo you want to edit?\n[1]Yes\n[2]No\nEnter choice: ";
            cin >> choice;
            if (choice=="1") {
                while (this->isValidISBN(ISBN)) {
                    cout << "-Enter ISBN: ";
                    cin >> ISBN;
                    if (this->isValidISBN(ISBN)) {
                        cout << "ISBN must have 5 digits.\n" << endl;
                    }
                }
            cin.ignore();
            cout << "-Title: ";
            getline(cin, title);
            cout << "-Author: ";
            getline(cin, author);
            cout << "-Publisher: ";
            getline(cin, publisher);
            cout << "-Categories: ";
            getline(cin, publisher);
            this->books[i].updateBook(ISBN, title, author, publisher, categories);
            cout << "\nThe book has been successfully edited.";
            menu.displayMainMenu();
            } else {
                menu.displayMainMenu();
              }
    }
    }
        cout << "\nBook not found.";
        menu.displayMainMenu();
}
void Bookmark::searchBook() {
    string ISBN;
    int choice;
    bool print = false;
    cout << "SEARCH BOOK\n\n";
    if (bookCounter == 0) {
        cout<<"There is no book to search.";
        menu.displayMainMenu();
    }
    cout << "Enter ISBN: ";
    cin >> ISBN;
    for (int i = 0; i < bookCounter; i++) {
        if (this->books[i].isEqualTo(ISBN)) {
            cout << "Title: " << this->books[i].getTitle() << endl;
            cout << "Author: " << this->books[i].getAuthor() << endl;
            cout << "Publisher: " << this->books[i].getPublisher() << endl;
            cout << "Categories: " << this->books[i].getCategories() << endl;
            cout << endl;
            print = true;
        }
    }
    if (print) {
        menu.displayMainMenu();
    } else{
        cout<<"\nBook not found.";
        menu.displayMainMenu();
      }
}
void Bookmark::viewAllBooks() {
    if (bookCounter == 0) {
        cout << "There are currently no books added.";
        main();
    }
    for (int i = 0; i < bookCounter; i++) {
        cout << "VIEW ALL BOOKS\n\n";
        cout << "Book " << i + 1 << endl;
        cout << "ISBN: " << this->books[i].getISBN() << endl;
        cout << "Title: " << this->books[i].getTitle() << endl;
        cout << "Author: " << this->books[i].getAuthor() << endl;
        cout << "Publisher: " << this->books[i].getPublisher() << endl;
        cout << "Categories: " << this->books[i].getCategories() << endl;
        cout << endl;
    }
    main();
}
void Bookmark::displayTopBooks() {
    string book1 = "Anna Karenina";
    string book2 = "Madame Bovary";
    string book3 = "War and Peace";
    string book4 = "The Great Gatsby";
    string book5 = "Lolita";
    string book6 = "Middlemarch";
    string book7 = "The alchemist";
    string book8 = "The Adventures of Huckleberry Finn";
    string book9 = "The Stories of Anton Chekhov";
    string book10 = "Hamlet";
    string books[] = { book1, book2, book3, book4, book5, book6, book7, book8, book9, book10 };
    int defaultBooks = sizeof(books) / sizeof(books[0]);
    int index1 = rand() % defaultBooks;
    int index2 = rand() % defaultBooks;
    int index3 = rand() % defaultBooks;
    cout << "Top 3 books of the week" << endl;
    cout << "1. " << books[index1] << endl;
    cout << "2. " << books[index2] << endl;
    cout << "3. " << books[index3] << endl;
    menu.displayMainMenu();
}
void Bookmark::addDefaultBooks() {
    bookCounter = 10;
    books[0].updateBook("00000", "Anna Karenina", "Leo Tolstoy", "Little, Brown and Company", "Fiction");
    books[1].updateBook("11111", "Madame Bovary", "Harper Lee", "J.B. Lippincott & Co.", "Fiction");
    books[2].updateBook("22222", "War and Peace", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
    books[3].updateBook("33333", "The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
    books[4].updateBook("44444", "Lolita", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
    books[5].updateBook("55555", "Middlemarch", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
    books[6].updateBook("66666", "The alchemist", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
    books[7].updateBook("77777", "The Adventures of Huckleberry Finn", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
    books[8].updateBook("88888", "The Stories of Anton Chekhov", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
    books[9].updateBook("99999", "Hamlet", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction");
}


    
  






