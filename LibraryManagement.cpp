#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


//FORMATIRAJ KOD

class Book {
        private:
            string ISBN, title, author, publisher, categories;

        public:
            void setISBN(string ISBN) { this->ISBN = ISBN; }
            void setTitle(string title) { this->title = title; }
            void setAuthor(string author) { this->author=author; }
            void setPublisher(string publisher) { this->publisher=publisher; }
            void setCategories(string categories) { this->categories=categories; }
            string getISBN() { return ISBN; }
            string getTitle() { return title; }
            string getAuthor() { return author; }
            string getPublisher() { return publisher; }
            string getCategories() { return categories; }

            bool isEqualTo(string ISBN) {
                this->ISBN == ISBN;
                }

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
        void setFirstName(string firstName) { this->firstName=firstName; }
        void setLastName(string lastName) { this->lastName=lastName; }
        void setJMBG(string JMBG) { this->JMBG=JMBG; }
        //getters

        string getFirstName() { return firstName; }
        string getLastName() { return lastName; }
        string getJMBG() { return JMBG; }
};

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

Bookmark bookMark;

int main() {
    char choice;
    bookMark.displayMainMenu();
    cin>>choice;
    bool quit{false};

do {

    int selection;

    switch (choice) {
    case '1':
        cout << "USER\n\n";
        cout << "[1] ADD USER\n";
        cout << "[2] EDIT USER\n";
        cout << "[3] DELETE USER\n";
        cout << "[4] VIEW ALL USERS\n";
        cout << "[5] BACK TO MAIN\n";
        cout << "[6] EXIT\n";
        cout << "Enter selection: \n";
        cin >> selection;

        switch (selection) {
        case 1:
            bookMark.addUser(bookMark.userCounter);
            break;
        case 2:
            bookMark.editUser(bookMark.userCounter);
            break;
        case 3:
            bookMark.deleteUser(bookMark.userCounter);
            break;
        case 4:
            bookMark.viewAllUsers(bookMark.userCounter);
            break;
        case 5:
            main();
            break;
        case 6:
            quit=true;
            break;
        default:
            cout<<"Invalid entry."<<endl;
            break;
        }
        break;

    case '2':
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
                bookMark.addBook(bookMark.bookCounter);
                break;
            case 2:
                bookMark.deleteBook(bookMark.bookCounter);
                break;
            case 3:
                bookMark.editBook(bookMark.bookCounter);
                break;
            case 4:
                bookMark.searchBook(bookMark.bookCounter);
                break;
            case 5:
                bookMark.viewAllBooks(bookMark.bookCounter);
                break;
            case 6:
                main();
                break;
            case 7:
                quit=true;
                break;
            default:
                cout<<"Invalid entry."<<endl;
                break;
        }
        break;

    case '3':
        quit=true;
        break;
    default:
        cout<<"Invalid entry."<<endl;
        break;
    }
    break;
} while (!quit); {
cout<<"Thanks for using our library management."<<endl;
}

return 0;
}




void Bookmark::displayMainMenu() {
    cout << "LIBRARY MANAGEMENT\n\n";
    cout << "[1] USER\n";
    cout << "[2] BOOK\n";
    cout << "[3] EXIT\n\n";
    cout << "ENTER SELECTION: ";
}
void Bookmark::addUser(int userCounter) {
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
        }
		}

    bookMark.users[bookMark.userCounter].setFirstName(firstName);
    bookMark.users[bookMark.userCounter].setLastName(lastName);
    bookMark.users[bookMark.userCounter].setJMBG(JMBG);
    bookMark.increment1(bookMark.userCounter);
        cout << "\nUser added successfully."<<endl;
        main();

}
else {
	cout<<"You have reached the maximum number of users that can be added!"<<endl;
	main();
}
}

void Bookmark::editUser(int userCounter) {
    string editjmbg, JMBG,firstName,lastName,choice;
    cout << "EDIT USER\n\n";
    if(bookMark.userCounter==0){
		cout<<"There are no users to edit!"<<endl;
		main();
	}
	cout<<"Enter JMBG: ";
	cin>>editjmbg;

    for (int i = 0; i < bookMark.userCounter; i++) {
        if (bookMark.users[i].getJMBG() == editjmbg) {
            cout<<"User found!\n\n";
            cout<<"JMBG: "<<bookMark.users[i].getJMBG()<<endl;
			cout<<"First name: "<<bookMark.users[i].getFirstName()<<endl;
			cout<<"Last name: "<<bookMark.users[i].getLastName()<<endl;
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

            }
            bookMark.users[i].setFirstName(firstName);
            bookMark.users[i].setLastName(lastName);
            bookMark.users[i].setJMBG(JMBG);
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
void Bookmark::viewAllUsers(int userCounter) {
    cout << "VIEW ALL USERS\n\n";
    if(bookMark.userCounter==0) {
			cout<<"There are currently no users added."<<endl;
			main();
		}
    for (int i = 0; i < userCounter; i++) {
        cout<<"User details\n\n";
        cout << "First name: " << bookMark.users[i].getFirstName() << endl;
        cout << "Last name: " << bookMark.users[i].getLastName() << endl;
        cout << "JMBG: " << bookMark.users[i].getJMBG() << endl;

}
main();
}
void Bookmark::deleteUser(int userCounter) {
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
    if (bookMark.users[i].getJMBG() == JMBG) {
        cout<<"\nUser found\n\n";
        cout<<"Do you want delete?\n[1]Yes\n[2]No\n\nEnter choice: ";
        cin>>choice;
        if(choice==1) {
        	bookMark.users[i].setFirstName("");
        	bookMark.users[i].setLastName("");
        	bookMark.users[i].setJMBG("");
        	for(int j=i;j<userCounter;j++) {
        		bookMark.users[j]=bookMark.users[j+1];
			}
		    bookMark.users[9].setFirstName("");
			bookMark.users[9].setLastName("");
			bookMark.users[9].setJMBG("");
			bookMark.decrement1(bookMark.userCounter);
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


void Bookmark::addBook(int bookCounter) {
    string ISBN, title, author, publisher, categories;
    cout << "ADD BOOK\n\n";
if(bookCounter<10) {
while(ISBN.length() != 5) {
            cout<<"- Enter ISBN: ";
            cin>>ISBN;
            if(ISBN.length() != 5) {
                cout<< "ISBN must be equal to 5 characters..\n";
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
    bookMark.increment(bookMark.bookCounter);
    cout << "\nBook added successfully.";

main();
} else {
	cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS THAT CAN BE ADDED!";
	main();
}
}
void Bookmark::deleteBook(int bookCounter) {
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
    if (bookMark.books[i].isEqualTo(ISBN)) {
        cout<<"\nBook found\n\n";
        cout<<"Do you want to delete?\n[1]Yes\n[2]No\nEnter choice: ";
        cin>>choice;
        if(choice==1) {
            bookMark.books[i].clearBook();
        	for(int a=i;a<bookCounter;a++) {
        		bookMark.books[a]=bookMark.books[a+1];
			}
			bookMark.books[9].clearBook();
			bookMark.decrement(bookMark.bookCounter);
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
void Bookmark::editBook(int bookCounter) {

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
    if (bookMark.books[i].getISBN() == editIsbn) {
    	cout<<"Book found!\n\n";
    	cout<<"ISBN: "<<bookMark.books[i].getISBN()<<endl;
    	cout<<"Title: "<<bookMark.books[i].getTitle()<<endl;
    	cout<<"Author: "<<bookMark.books[i].getAuthor()<<endl;
    	cout<<"Publisher: "<<bookMark.books[i].getPublisher()<<endl;
    	cout<<"Categories: "<<bookMark.books[i].getCategories()<<endl;
        cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\nEnter choice: ";
        cin>>choice;
        if(choice=="1") {
        	while(ISBN.length() != 5) {
        		cout<<"-Enter ISBN: ";
        		cin>>ISBN;

        		if(ISBN.length() != 5) {
        			cout<<"ISBN must have 5 digits.\n"<<endl;

				}
			}
			cin.ignore();
			cout<<"-Title: ";
			getline(cin, title);
			cout<<"-Author: ";
			getline(cin, author);
			cout<<"-Publisher: ";
			getline(cin, publisher);
			cout<<"-Categories: ";
			getline(cin, publisher);

			bookMark.books[i].updateBook(ISBN, title, author, publisher, categories);
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
void Bookmark::searchBook(int bookCounter) {
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
void Bookmark::viewAllBooks(int bookCounter) {
	if(bookCounter==0) {
		cout<<"There are currently no books added.";
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




