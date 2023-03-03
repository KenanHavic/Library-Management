#include <iostream>
#include <string>
#include <conio.h>
#include "book.h"
#include "user.h"
#include "bookmark.h"
#include "Menu.h"

using namespace std;

Menu menu;
Bookmark bookMark;

int main() {
    bool quit{ false };
    int choose;
    string username, password;
    bool isPremium = false;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    char userType;
    cout << "Select user type (P for premium, R for regular): ";
    cin >> userType;

    if (userType == 'P' || userType == 'p') {
        isPremium = true;
        cout << "Welcome, " << username << "!" << endl;
        cout << "You are a premium user." << endl;
        menu.displayMainMenu();
        cin >> choose;

        do {
            switch (choose) {
            case 1:
                cout << "USER\n";
                cout << "[1]ADD USER\n";
                cout << "[2]DELETE USER\n";
                cout << "[3]EDIT USER\n";
                cout << "[4]VIEW ALL USERS\n";
                cout << "[5]EXIT\n";
                int selection;
                cout << "Enter selection: ";
                cin >> selection;
                switch (selection) {
                case 1:
                    bookMark.addUser();
                    break;
                case 2:
                    bookMark.deleteUser();
                    break;
                case 3:
                    bookMark.editUser();
                    break;
                case 4:
                    bookMark.viewAllUsers();
                    break;
                case 5:
                    quit = true;
                    break;
                default:
                    cout << "Invalid input\n";
                    break;
                }
                break;
            case 2:
                cout << "BOOK\n";
                cout << "[1]ADD BOOK\n";
                cout << "[2]DELETE BOOK\n";
                cout << "[3]EDIT BOOK\n";
                cout << "[4]SEARCH BOOK\n";
                cout << "[5]VIEW ALL BOOKS\n";
                cout << "[6]EXIT\n";
                int choice;
                cout << "Enter selection: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    bookMark.addBook();
                    break;
                case 2:
                    bookMark.deleteBook();
                    break;
                case 3:
                    bookMark.editBook();
                    break;
                case 4:
                    bookMark.searchBook();
                    break;
                case 5:
                    bookMark.viewAllBooks();
                    break;
                case 6:
                    quit = true;
                    break;
                default:
                    cout << "Invalid input\n";
                    break;
                }

            case 3:
                quit = true;
                break;
            default:
                cout << "Invalid input";
            }
        } while (!quit);
        cout << "Thanks for using our library management";
    }
    else if (userType == 'R' || userType == 'r') {
        cout << "Welcome, " << username << "!" << endl;
        cout << "You are a regular user." << endl;
        cout << "[1]USER\n";
        cout << "[2]BOOK\n";
        cout << "[3]EXIT\n";
        int choice;
        cout << "Enter selection: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "USER\n";
            cout << "[1]VIEW ALL USERS\n";
            cout << "[2]EXIT\n";
            int selection;
            cout << "Enter selection: ";
            cin >> selection;
            switch (selection) {
    			case 1:
    				bookMark.addUser();
    				break;
    			case 2:
        			bookMark.deleteUser();
        			break;
    			case 3:
        			bookMark.editUser();
        			break;
    			case 4:
        			bookMark.viewAllUsers();
        			break;
    			case 5:
        			quit=true;
        			break;
    			default:
        			cout<<"Invalid input\n";
        			break;
    		}
    		break;
    	case 2:
        	cout<<"BOOK\n";
        	cout<<"[1]ADD BOOK\n";
        	cout<<"[2]DELETE BOOK\n";
        	cout<<"[3]EDIT BOOK\n";
        	cout<<"[4]SEARCH BOOK\n";
        	cout<<"[5]VIEW ALL BOOKS\n";
        	cout<<"[6]EXIT\n";
        	int choice;
        	cout<<"Enter selection: ";
        	cin>>choice;
        	switch (choice) {
    			case 1:
        			bookMark.addBook();
        			break;
    			case 2:
        			bookMark.deleteBook();
        			break;
    			case 3:
        			bookMark.editBook();
        			break;
    			case 4:
        			bookMark.searchBook();
        			break;
    			case 5:
        			bookMark.viewAllBooks();
    			case 6:
        			quit=true;
        			break;
    			default:
        			cout<<"Invalid input\n";
        			break;
        	}
        	break;
    	case 3:
        	quit=true;
        	break;
    	default:
        	cout<<"Invalid input";
	}
} while (!quit);

cout<<"Thanks for using our library management";

return 0;

}

void Bookmark::addUser() {
    string firstName, lastName, ID;

    if(userCounter < 10) {
        cout << "ADD USER\n\n";
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;

        while(ID.length() != 13) {
            cout << "Enter ID: ";
            cin >> ID;
            if(ID.length() != 13) {
                cout << "ID must have 13 digits" << endl;
            }
        }

        bookMark.users[bookMark.userCounter].setFirstName(firstName);
        bookMark.users[bookMark.userCounter].setLastName(lastName);
        bookMark.users[bookMark.userCounter].setID(ID);
        bookMark.incrementUser();
        cout << "\nUser added successfully." << endl;
        main();
    }
    else {
        cout << "You have reached the maximum number of users that can be added!" << endl;
        main();
    }
}



void Bookmark::editUser() {
    string editId, ID, firstName, lastName, choice;

    cout << "EDIT USER\n\n";
    if(bookMark.userCounter == 0) {
        cout << "There are no users to edit!" << endl;
        main();
    }

    cout << "Enter ID: ";
    cin >> editId;

    for (int i = 0; i < bookMark.userCounter; i++) {
        if (bookMark.users[i].getID() == editId) {
            cout << "User found!\n\n";
            cout << "ID: " << bookMark.users[i].getID() << endl;
            cout << "First name: " << bookMark.users[i].getFirstName() << endl;
            cout << "Last name: " << bookMark.users[i].getLastName() << endl;
            cout << "\nDo you want to edit?\n[1] Yes\n[2] No\n\nEnter choice: ";
            cin >> choice;

            if(choice == "1") {
                cout << "- First name: ";
                cin >> firstName;
                cout << "- Last name: ";
                cin >> lastName;

                while(ID.length() != 13) {
                    cout << "- Enter ID: ";
                    cin >> ID;

                    if(ID.length() != 13) {
                        cout << "ID must have 13 digits" << endl;
                    }
                }

                bookMark.users[i].setFirstName(firstName);
                bookMark.users[i].setLastName(lastName);
                bookMark.users[i].setID(ID);
                cout << "User edited successfully!" << endl;
                main();
            }
            else {
                main();
            }
        }
    }
    cout << "\nUser not found." << endl;
    main();
}


void Bookmark::viewAllUsers() {
    cout << "VIEW ALL USERS\n\n";
    if(bookMark.userCounter == 0) {
        cout << "There are currently no users added." << endl;
        main();
    }

    for (int i = 0; i < userCounter; i++) {
        cout << "User details\n\n";
        cout << "First name: " << bookMark.users[i].getFirstName() << endl;
        cout << "Last name: " << bookMark.users[i].getLastName() << endl;
        cout << "ID: " << bookMark.users[i].getID() << endl;
    }
    main();
}

void Bookmark::deleteUser() {
    string ID;
    int choice;
    cout << "DELETE USER\n\n";
    if(userCounter == 0) {
        cout << "There are no users to delete!";
        main();
    }

    cout << "Enter ID: ";
    cin >> ID;

    for (int i = 0; i < userCounter; i++) {
        if (bookMark.users[i].getID() == ID) {
            cout << "\nUser found\n\n";
            cout << "Do you want delete?\n[1]Yes\n[2]No\n\nEnter choice: ";
            cin >> choice;
            if(choice == 1) {
                bookMark.users[i].setFirstName("");
                bookMark.users[i].setLastName("");
                bookMark.users[i].setID("");
                for(int j = i; j < userCounter; j++) {
                    bookMark.users[j] = bookMark.users[j+1];
                }
                bookMark.users[9].setFirstName("");
                bookMark.users[9].setLastName("");
                bookMark.users[9].setID("");
                bookMark.decrementUser();
                cout << "User successfully deleted.\n";
                main();
            }
            else {
                main();
            }
        }
    }
    cout << "\nUser not found!";
    main();
}



void Bookmark::addBook() {
    string ISBN, title, author, publisher, categories;
    cout << "ADD BOOK\n\n";
    if (bookCounter < 10) {
        while (ISBN.length() != 5) {
            cout << "- Enter ISBN: ";
            cin >> ISBN;
            if (ISBN.length() != 5) {
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

        bookMark.books[bookCounter].updateBook(ISBN, title, author, publisher, categories);
        bookMark.incrementBook();
        cout << "\nBook added successfully.";
        main();
    } else {
        cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS THAT CAN BE ADDED!";
        main();
    }
}

void Bookmark::deleteBook() {
    string ISBN;
    int choice;
    cout << "DELETE BOOK\n\n";
    if (bookCounter == 0) {
        cout << "NO BOOK TO DELETE!";
        main();
    }
    cout << "Enter ISBN: ";
    cin >> ISBN;

    for (int i = 0; i < bookCounter; i++) {
        if (bookMark.books[i].isEqualTo(ISBN)) {
            cout << "\nBook found\n\n";
            cout << "Do you want to delete?\n[1]Yes\n[2]No\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                bookMark.books[i].clearBook();
                for (int a = i; a < bookCounter; a++) {
                    bookMark.books[a] = bookMark.books[a + 1];
                }
                bookMark.books[9].clearBook();
                bookMark.decrementBook();
                cout << "The book was successfully deleted.";
                main();
            } else {
                main();
            }
        }
    }
    cout << "\nBook not found.";
    main();
}


void Bookmark::editBook() {
    string ISBN, title, author, publisher, categories;
    string editIsbn, choice;
    cout << "EDIT BOOK\n\n";
    if (bookCounter == 0) {
        cout << "There is no book to edit.\n\n";
        main();
    }
    cout << "Enter ISBN: ";
    cin >> editIsbn;

    for (int i = 0; i < bookCounter; i++) {
        if (bookMark.books[i].getISBN() == editIsbn) {
            cout << "Book found!\n\n";
            cout << "ISBN: " << bookMark.books[i].getISBN() << endl;
            cout << "Title: " << bookMark.books[i].getTitle() << endl;
            cout << "Author: " << bookMark.books[i].getAuthor() << endl;
            cout << "Publisher: " << bookMark.books[i].getPublisher() << endl;
            cout << "Categories: " << bookMark.books[i].getCategories() << endl;
            cout << "\nDo you want to edit?\n[1]Yes\n[2]No\nEnter choice: ";
            cin >> choice;
            if (choice == "1") {
                while (ISBN.length() != 5) {
                    cout << "-Enter ISBN: ";
                    cin >> ISBN;
                    if (ISBN.length() != 5) {
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
                getline(cin, categories);

                bookMark.books[i].updateBook(ISBN, title, author, publisher, categories);
                cout << "\nThe book has been successfully edited.";
                main();
            } else {
                main();
            }
        }
    }
    cout << "\nBook not found.";
    main();
}


void Bookmark::searchBook() {
    string ISBN;
    int choice;
    bool print=false;

    cout << "SEARCH BOOK\n\n";
    if(bookCounter==0) {
        cout<<"There is no book to search.";
        main();
    }

    cout << "Enter ISBN: ";
    cin >> ISBN;

    for (int i = 0; i < bookCounter; i++) {
        if (bookMark.books[i].isEqualTo(ISBN)) {
            cout << "Title: " << bookMark.books[i].getTitle() << endl;
            cout << "Author: " << bookMark.books[i].getAuthor() << endl;
            cout << "Publisher: " << bookMark.books[i].getPublisher() << endl;
            cout << "Categories: " << bookMark.books[i].getCategories() << endl;
            cout << endl;
            print = true;
        }
    }

    if (print) {
        main();
    } else{
        cout<<"\nBook not found.";
        main();
    }
}


void Bookmark::viewAllBooks() {
    if (bookCounter == 0) {
        cout << "There are currently no books added.";
        main();
    }

    for (int i = 0; i < bookCounter; i++) {
        cout << "VIEW ALL BOOKS\n\n";
        cout << "ISBN: " << bookMark.books[i].getISBN() << endl;
        cout << "Title: " << bookMark.books[i].getTitle() << endl;
        cout << "Author: " << bookMark.books[i].getAuthor() << endl;
        cout << "Publisher: " << bookMark.books[i].getPublisher() << endl;
        cout << "Categories: " << bookMark.books[i].getCategories() << endl;
        cout << endl;
    }

    main();
}





