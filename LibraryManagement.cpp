#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Book {
private:
string ISBN, title, author, publisher, categories;

public:
void setISBN(string ISBN) { this->ISBN = ISBN; }
void setTitle(string title) { this->title = title; }
void setAuthor(string writer) { author = writer; }
void setPublisher(string creator) { publisher = creator; }
void setCategories(string category) { categories = category; }
string getISBN() { return ISBN; }
string getTitle() { return title; }
string getAuthor() { return author; }
string getPublisher() { return publisher; }
string getCategories() { return categories; }

void clearBook() {
    updateBook("", "", "", "", "");

}

void updateBook(string isbn, string title, string author, string publisher, string categories) {
    setISBN(isbn);
    setTitle(title);
    setAuthor(author);
    setPublisher(publisher);
    setCategories(categories);
}


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

displayMainMenu();
cin >> choice;

bool quit{false};

do {
    switch (choice) {
    case 1:
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
     		quit=true;
     		break;
     		default:
     			cout<<"Invalid entry."<<endl;
     			main();
     			break;
     		}

break;

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
            quit=true;

            break;
            default:
            	cout<<"Invalid entry."<<endl;
            	main();
            	break;
        }

    case 3:
        quit=true;
        break;
        default:
        	cout<<"Invalid entry!"<<endl;
        	main();
    }
    break;
} while (!quit); {
cout<<"Thanks for using our library management."<<endl;}


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
cout << "\nUser added successfully."<<endl;
main();

}
else {
	cout<<"You have reached the maximum number of users that can be added!"<<endl;
	main();
}
}

void editUser(int userCounter) {
string editjmbg, JMBG,firstName,lastName,choice;
cout << "EDIT USER\n\n";
if(userCounter==0){
		cout<<"There are no users to edit!"<<endl;
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
            cout<<"User edited successfully!"<<endl;
            main();
        }
    } else {
    	main();
	}

}
}
cout<<"\n User not found."<<endl;
main();
}
void viewAllUsers(int userCounter) {
cout << "VIEW ALL USERS\n\n";
if(userCounter==0) {
			cout<<"There are currently no users added."<<endl;
			main();
		}
for (int i = 0; i < userCounter; i++) {
	cout<<"User details\n\n";
    cout << "First name: " << users[i].getFirstName() << endl;
    cout << "Last name: " << users[i].getLastName() << endl;
    cout << "JMBG: " << users[i].getJMBG() << endl;

}
main();
}
void deleteUser(int userCounter) {
string JMBG;
int choice;
cout << "DELETE USER\n\n";
if(userCounter==0){
		cout<<"There are no users to delete!";
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
			cout<<"User successfully deleted.";
			main();
		}
		else {
			main();
		}
    }
}
cout<<"\nUser not found!";
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
                cout<< "Isbn mora biti jednak 5 karaktera..";
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

books[bookCounter].setISBN(ISBN);
books[bookCounter].setTitle(title);
books[bookCounter].setAuthor(author);
books[bookCounter].setPublisher(publisher);
books[bookCounter].setCategories(categories);
increment(bookCounter);
cout << "\nBook added successfully.";

main();
} else {
	cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS THAT CAN BE ADDED!";
	main();
}
}
void deleteBook(int bookCounter) {
string ISBN;
int choice;
cout << "DELETE BOOK\n\n";
if(bookCounter==0) {
	cout<<"NO BOOK TO DELETE!";
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
            books[i].clearBook();
        	for(int a=i;a<bookCounter;a++) {
        		books[a]=books[a+1];
			}
			books[9].clearBook();
			decrement(bookCounter);
			cout<<"The book was successfully deleted.";

			main();
		} else {
			main();
		}
    }
}
    cout<<"\nBook not found.";
    main();



}
void editBook(int bookCounter) {

string ISBN, title, author, publisher, categories;
string editIsbn,choice;
cout << "EDIT BOOK\n\n";
if(bookCounter==0) {
	cout<<"There is no book to edit.\n\n";
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
			cout<<"\nThe book has been successfully edited.";
			main();
		} else {
			main();
		}
    }
}
cout<<"\nBook not found.";
main();

}
void searchBook(int bookCounter) {
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

    main();
} else{
	cout<<"\nBook not found.";

	main();
}
}
void viewAllBooks(int bookCounter) {
	if(bookCounter==0) {
		cout<<"There are currently no books added.";
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

main();
}




