#pragma once
#include<vector>

#include "Genre.h"
#include "Book.h"
#include "Owner.h"

class Library
{
public:
	// Constructors
	Library(std::vector<Genre> genres, std::vector<Book> books, std::vector <Owner> owners);
	Library();

	void add_genre(Genre g);
	void add_book(Book b);
	void add_owner(Owner o);

	void load_default_genres();
	void display_genres();
	void display_books();
	void display_owners();

	Book select_book();
	Genre select_genre();

private:
	std::vector<Genre> genres;
	std::vector<Book> books;
	std::vector<Owner> owners;
};



