#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;
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
#endif








