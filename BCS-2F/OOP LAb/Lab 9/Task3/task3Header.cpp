#include "C:\Users\k240656\Desktop\LAb 9 oop\Task3\task3Header.h"
#include <iostream>
using namespace std;

Book::Book(string t, string a, string I): title(t), author(a), ISBN(I){};

string Book::getAuthor() const{
	return author;
}

string Book::getISBN() const{
	return ISBN;
}

string Book::getTitle() const{
	return title;
}