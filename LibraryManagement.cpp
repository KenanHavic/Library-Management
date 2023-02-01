#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Book {
private:
string ISBN, title, author, publisher, categories;

public:
void setISBN(string a) { ISBN = a; }
void setTitle(string b) { title = b; }
void setAuthor(string c) { author = c; }
void setPublisher(string d) { publisher = d; }
void setCategories(string e) { categories = e; }
string getISBN() { return ISBN; }
string getTitle() { return title; }
string getAuthor() { return author; }
string getPublisher() { return publisher; }
string getCategories() { return categories; }
};
class User {
private:
string firstName, lastName;
string JMBG;

public:
//setter
void setFirstName(string name) { firstName = name; }
void setLastName(string surname) { lastName = surname; }
void setJMBG(string j) { JMBG = j; }
//getters

string getFirstName() { return firstName; }
string getLastName() { return lastName; }
string getJMBG() { return JMBG; }
};

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
void quit();

//counter for book array and user array
int bookCounter = 0;
int userCounter=0;

//function to increase counter
void increment(int a) {
a++;
bookCounter = a;
}
void increment1(int b) {
	b++;
	userCounter=b;
}
//function to decrease counter
void decrement(int a) {
a--;
bookCounter = a;
}
void decrement1(int b){
	b--;
	userCounter=b;
}


//limiting number of entered books
Book books[10];
User users[10];

int main() {
int choice;
system("CLS");
displayMainMenu();
cin >> choice;
system("CLS");
bool exit{false};

do {
    switch (choice) {
    case 1:
        system("CLS");
        cout << "USER\n\n";
        cout << "[1] ADD USER\n";
        cout << "[2] EDIT USER\n";
        cout << "[3] DELETE USER\n";
        cout << "[4] VIEW ALL USERS\n";
        cout << "[5] BACK TO MAIN\n";
        cout << "[6] EXIT\n";
        int selection;
        cout << "Enter selection: \n";
        cin >> selection;
        system("CLS");

        switch (selection) {
        case 1:
            addUser(userCounter);

            break;
        case 2:
            editUser(userCounter);
            break;
        case 3:
            deleteUser(userCounter);

            break;
        case 4:
            viewAllUsers(userCounter);
            break;
     case 5:
     	main();
     	break;
     	case 6:
     		quit();
     		break;
     		default:
     			cout<<"Invalid entry.\n\n Press any key to continue..."<<endl;
     			_getch();

     			main();
     			break;
     		}



case 2:

cout << "BOOK\n\n";
cout << "[1] ADD BOOK\n";
cout << "[2] DELETE BOOK\n";
cout << "[3] EDIT BOOK\n";
cout << "[4] SEARCH BOOK\n";
cout << "[5] VIEW ALL BOOKS\n";
cout << "[6] BACK TO MAIN\n";
cout << "[7] EXIT\n";
cout << "Enter selection: \n";
cin >> selection;
system("CLS");
        switch (selection) {
        case 1:
            addBook(bookCounter);

            break;
        case 2:
            deleteBook(bookCounter);

            break;
        case 3:
            editBook(bookCounter);
            break;
        case 4:
            searchBook(bookCounter);
            break;
        case 5:
            viewAllBooks(bookCounter);
            break;
        case 6:
            main();

            break;
        case 7:
            quit();

            break;
            default:
            	cout<<"Invalid entry.\n\n Press any key to continue..."<<endl;
            	_getch();
            	main();
            	break;
        }

    case 3:
        quit();
        break;
        default:
        	cout<<"Invalid entry!\n\n Press any key to continue..."<<endl;
        	_getch();
        	main();
    }
    break;
} while (!exit); {
cout<<"End."<<endl;}

_getch();
return 0;
}

void displayMainMenu() {
cout << "LIBRARY MANAGEMENT\n\n";
cout << "[1] USER\n";
cout << "[2] BOOK\n";
cout << "[3] EXIT\n\n";
cout << "ENTER SELECTION: ";
}
void addUser(int userCounter) {
string firstName, lastName, JMBG;
if(userCounter < 10) {

cout << "ADD USER\n\n";
cout << "Enter first name: ";
cin >> firstName;
cout << "Enter last name: ";
cin >> lastName;
while(JMBG.length() != 13) {
            cout<<"- Enter JMBG: ";
            cin>>JMBG;

            if(JMBG.length() != 13) {
                cout<<"JMBG must have 13 digits"<<endl;
                cout<<"Enter JMBG again: ";
                cin>>JMBG;
            }
		}

users[userCounter].setFirstName(firstName);
users[userCounter].setLastName(lastName);
users[userCounter].setJMBG(JMBG);
increment1(userCounter);
cout << "\nUser added successfully.\n\n Press any key to continue..."<<endl;
_getch();
main();

}
else {
	cout<<"You have reached the maximum number of users that can be added!\n\n Press any key to continue... "<<endl;
	_getch();
	main();
}
}

void editUser(int userCounter) {
string editjmbg, JMBG,firstName,lastName,choice;
cout << "EDIT USER\n\n";
if(userCounter==0){
		cout<<"There are no users to edit!\n\n Press any key to continue . . ."<<endl;
		_getch();
		main();
	}
	cout<<"Enter JMBG: ";
	cin>>editjmbg;

for (int i = 0; i < userCounter; i++) {
    if (users[i].getJMBG() == editjmbg) {
  cout<<"User found!\n\n";
  cout<<"JMBG: "<<users[i].getJMBG()<<endl;
			cout<<"First name: "<<users[i].getFirstName()<<endl;
			cout<<"Last name: "<<users[i].getLastName()<<endl;
			cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
			cin>>choice;
			if(choice=="1"){

				cout<<"- First name: ";
				cin>>firstName;
				cout<<"- Prezime: ";
				cin>>lastName;
				while(JMBG.length() != 13) {
            cout<<"- Enter JMBG: ";
            cin>>JMBG;

            if(JMBG.length() != 13) {
                cout<<"JMBG must have 13 digits"<<endl;
                cout<<"Enter JMBG again: ";
                cin>>JMBG;
            }
            users[i].setFirstName(firstName);
            users[i].setLastName(lastName);
            users[i].setJMBG(JMBG);
            cout<<"User edited successfully!\n\n Press any key to continue..."<<endl;
            _getch();
            main();
        }
    } else {
    	main();
	}

}
}
cout<<"\n User not found.\n\n Press any key to continue..."<<endl;
_getch();
main();
}
void viewAllUsers(int userCounter) {
cout << "VIEW ALL USERS\n\n";
if(userCounter==0) {
			cout<<"There are currently no users added.\n\n Press any key to continue... "<<endl;
			_getch();
			main();
		}
for (int i = 0; i < userCounter; i++) {
	cout<<"User details\n\n";
    cout << "First name: " << users[i].getFirstName() << endl;
    cout << "Last name: " << users[i].getLastName() << endl;
    cout << "JMBG: " << users[i].getJMBG() << endl;

}
cout<<"Press any key to continue...";
_getch();
main();
}
void deleteUser(int userCounter) {
string JMBG;
int choice;
cout << "DELETE USER\n\n";
if(userCounter==0){
		cout<<"There are no users to delete!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
cout << "Enter JMBG: ";
cin >> JMBG;


for (int i = 0; i < userCounter; i++) {
    if (users[i].getJMBG() == JMBG) {
        cout<<"\nUser found\n\n";
        cout<<"Do you want delete?\n[1]Yes\n[2]No\n\nEnter choice: ";
        cin>>choice;
        if(choice==1) {
        	users[i].setFirstName("");
        	users[i].setLastName("");
        	users[i].setJMBG("");
        	for(int j=i;j<userCounter;j++) {
        		users[j]=users[j+1];
			}
			users[9].setFirstName("");
			users[9].setLastName("");
			users[9].setJMBG("");
			decrement1(userCounter);
			cout<<"User successfully deleted.\n\nPress any key to continue...";
			_getch();
			main();
		}
		else {
			main();
		}
    }
}
cout<<"\nUser not found!\n\nPress any key to continue...";
_getch();
main();



}


void addBook(int bookCounter) {
string ISBN, title, author, publisher, categories;
cout << "ADD BOOK\n\n";
if(bookCounter<10) {
while(ISBN.length() != 5) {
            cout<<"- Enter ISBN: ";
            cin>>ISBN;

            if(ISBN.length() != 5) {
                cout<<"ISBN must be 5 digits "<<endl;
                cout<<"Enter ISBN again: ";
                cin>>ISBN;
            }
        }
cout << "Enter title: ";
cin >> title;
cout << "Enter author: ";
cin >> author;
cout << "Enter publisher: ";
cin >> publisher;
cout << "Enter categories: ";
cin >> categories;

books[bookCounter].setISBN(ISBN);
books[bookCounter].setTitle(title);
books[bookCounter].setAuthor(author);
books[bookCounter].setPublisher(publisher);
books[bookCounter].setCategories(categories);
increment(bookCounter);
cout << "\nBook added successfully.\n\n Press any key to continue...";
_getch();
main();
} else {
	cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS THAT CAN BE ADDED!\n\nPress any key to continue...";
	_getch();
	main();
}
}
void deleteBook(int bookCounter) {
string ISBN;
int choice;
cout << "DELETE BOOK\n\n";
if(bookCounter==0) {
	cout<<"NO BOOK TO DELETE!\n\nPress any key to continue...";
	_getch();
	main();
}
cout << "Enter ISBN: ";
cin >> ISBN;


for (int i = 0; i < bookCounter; i++) {
    if (books[i].getISBN() == ISBN) {
        cout<<"\nBook found\n\n";
        cout<<"Do you want to delete?\n[1]Yes\n[2]No\nEnter choice: ";
        cin>>choice;
        if(choice==1) {
        	books[i].setISBN("");
        	books[i].setTitle("");
        	books[i].setAuthor("");
        	books[i].setPublisher("");
        	books[i].setCategories("");
        	for(int a=i;a<bookCounter;a++) {
        		books[a]=books[a+1];
			}
			books[9].setISBN("");
			books[9].setTitle("");
			books[9].setAuthor("");
			books[9].setPublisher("");
			books[9].setCategories("");
			decrement(bookCounter);
			cout<<"The book was successfully deleted.\n\nPress any key to continue...";
			_getch();
			main();
		} else {
			main();
		}
    }
}
    cout<<"\nBook not found.\n\nPress any key to continue...";
    _getch();
    main();



}
void editBook(int bookCounter) {
	system("CLS");
string ISBN, title, author, publisher, categories;
string editIsbn,choice;
cout << "EDIT BOOK\n\n";
if(bookCounter==0) {
	cout<<"There is no book to edit.\n\nPress any key to continue...";
	_getch();
	main();
}
cout << "Enter ISBN: ";
cin >> editIsbn;

for (int i = 0; i < bookCounter; i++) {
    if (books[i].getISBN() == editIsbn) {
    	cout<<"Book found!\n\n";
    	cout<<"ISBN: "<<books[i].getISBN()<<endl;
    	cout<<"Title: "<<books[i].getTitle()<<endl;
    	cout<<"Author: "<<books[i].getAuthor()<<endl;
    	cout<<"Publisher: "<<books[i].getPublisher()<<endl;
    	cout<<"Categories: "<<books[i].getCategories()<<endl;
        cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\nEnter choice: ";
        cin>>choice;
        if(choice=="1") {
        	while(ISBN.length() != 5) {
        		cout<<"-Enter ISBN: ";
        		cin>>ISBN;

        		if(ISBN.length() != 5) {
        			cout<<"ISBN must have 5 digits."<<endl;
        			cout<<"Enter ISBN again: ";
        			cin>>ISBN;
				}
			}
			cout<<"-Title: ";
			cin>>title;
			cout<<"-Author: ";
			cin>>author;
			cout<<"-Publisher: ";
			cin>>publisher;
			cout<<"-Categories: ";
			cin>>categories;

			books[i].setISBN(ISBN);
			books[i].setTitle(title);
			books[i].setAuthor(author);
			books[i].setPublisher(publisher);
			books[i].setCategories(categories);
			cout<<"\nThe book has been successfully edited.\n\nPress any key to continue...";
			_getch();
			main();
		} else {
			main();
		}
    }
}
cout<<"\nBook not found.\n\nPress any key to continue...";
_getch();
main();

}
void searchBook(int bookCounter) {
string ISBN;
int choice;
bool print=false;

cout << "SEARCH BOOK\n\n";
if(bookCounter==0) {
	cout<<"There is no book to search.\n\nPress any key to continue...";
	_getch();
	main();
}
cout << "Enter ISBN: ";
cin >> ISBN;
for (int i = 0; i < bookCounter; i++) {
    if (books[i].getISBN() == ISBN) {
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Publisher: " << books[i].getPublisher() << endl;
        cout << "Categories: " << books[i].getCategories() << endl;
        cout << endl;
        print = true;
    }
}

if (print) {
    cout << "\nPress any key to continue..";
    _getch();
    main();
} else{
	cout<<"\nBook not found.\n\nPress any key to continue...";
	_getch();
	main();
}
}
void viewAllBooks(int bookCounter) {
	if(bookCounter==0) {
		cout<<"There are currently no books added.\n\nPress any key to continue...";
		_getch();
		main();
	}

for (int i = 0; i < bookCounter; i++) {
	cout << "VIEW ALL BOOKS\n\n";
    cout << "ISBN: " << books[i].getISBN() << endl;
    cout << "Title: " << books[i].getTitle() << endl;
    cout << "Author: " << books[i].getAuthor() << endl;
    cout << "Publisher: " << books[i].getPublisher() << endl;
    cout << "Categories: " << books[i].getCategories() << endl;
    cout << endl;
}
cout<<"Press any key to continue...";
_getch();
main();
}
void quit() {
cout << "Thank you for using the library management system.\n";
_exit(1);
}


