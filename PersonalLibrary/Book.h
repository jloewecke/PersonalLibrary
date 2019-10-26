// It seems like bad practice to have cout and cin in a class, check on that.
#pragma once
#include "Genre.h"

class Book
{
public:
	// Consturctors
	Book(std::string isbn, std::string title, std::string author, Genre genre, bool read, bool inlibrary);
	Book();

	// Member Functions
	void display();
	std::string display_title() { return title; }

	bool available() { return inlibrary; }
	void check_in() { inlibrary = true;}
	void check_out() { inlibrary = false; }

	void add();
	void set_book_genre(Genre genren);

private:
	std::string isbn;
	std::string title;
	std::string author;
	Genre genre;
	bool read;
	bool inlibrary;
};

bool valid_book(std::string isbn);


