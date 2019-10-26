#include "Library.h"
#include <iostream>

Library::Library(std::vector<Genre> genrev, std::vector<Book> bookv, std::vector<Owner> ownerv)
	:genres{ genrev }, books{ bookv }, owners{ ownerv }
{
}

Library::Library()
{

}

Genre Library::select_genre() {	

	int choice = -1;

	for (int i = 0; i < genres.size(); i++) {
		genres[i].display();
		std::cout << "\n";
	}

	std::cout << "Select Genre: ";
	std::cin >> choice;
	if (choice < 1 || choice > genres.size()) throw std::exception("Invalid Genre Selection");
	return genres[choice - 1];
}


void Library::load_default_genres() {

	// We need to come back to this and make a decision
	// Just gonna hacky put it together so i can move on
	Genre g1(1,"Fiction");
	genres.push_back(g1);
	Genre g2(2, "Non-Fiction");
	genres.push_back(g2);
	Genre g3(3, "Educational");
	genres.push_back(g3);
	Genre g4(4, "Poetry");
	genres.push_back(g4);
	Genre g5(5, "Other");
	genres.push_back(g5);
}


Book Library::select_book() {

	int choice = -1;
	int max = 1;
	for (int i = 0; i < books.size(); i++) {
		std::cout << max << ") - " << books[i].display_title() << "\n";
		max++;
	}
	std::cout << "Select book: ";
	std::cin >> choice;
	if (choice < 0 || choice > max) throw std::exception("Invalid book selection");
	return books[choice - 1];
}

void Library::display_books() {
	for (Book b : books) {
		b.display();
	}
}

void Library::display_genres() {
	for (Genre g : genres) {
		g.display();
		std::cout << "\n";
	}
}

void Library::display_owners() {
	for (Owner o : owners) {
		o.display();
	}
}

void Library::add_book(Book b) {
	books.push_back(b);
}

void Library::add_genre(Genre g) {
	genres.push_back(g);
}

void Library::add_owner(Owner o) {
	owners.push_back(o);
}
