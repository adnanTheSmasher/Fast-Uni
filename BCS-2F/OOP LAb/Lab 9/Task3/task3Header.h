#ifndef TASK3HEADER
#define TASK3HEADER
#include<iostream>
#include <string>
using namespace std;


class Book
{
	private:
		string title;
		string author;
		string ISBN;
	public:
		Book(string t, string a , string I);
		string getTitle() const;
		string getAuthor() const;
		string getISBN() const;
};
#endif