#include "Book.h"
#include <iostream>

// Consturctors
Book::Book(std::string isbnb, std::string titleb, std::string authorb, Genre genreb, bool readb, bool inlibraryb)
	: isbn{ isbnb }, title{ titleb }, author{ authorb },
	genre{ genreb }, read{ readb }, inlibrary{ inlibraryb }
{
	if (!valid_book(isbnb)) throw std::exception("Invalid Book");
}

Book::Book() 
	:isbn{ "0 - 0 - 0 - X" }, title{ "" }, author{ "" },
	genre{Genre()} , read{false}, inlibrary{false}
{
}


void Book::add() {

	// Using getline instead of cin >> may have to also use cin.clear and cin.sync or cin.ignore

	char temp;

	std::cout << "ISBN: ";
	std::cin >> isbn;
	std::cin.ignore();
	if (!valid_book(isbn)) throw std::exception("Invalid Book");

	std::cout << "Title: ";
	std::getline(std::cin, title);
	
	std::cout << "Author: ";
	std::getline(std::cin, author);
	
	std::cout << "Read(y/n): ";
	std::cin >> temp;
	if (tolower(temp) == 'y') {
		read = true;
	}
	else {
		read = false;
	}

	std::cout << "In Library(y/n): ";
	std::cin >> temp;
	if (tolower(temp) == 'y') {
		inlibrary = true;
	}
	else {
		inlibrary = false;
	}
}

void Book::set_book_genre(Genre genren) {
	
	// Definitly need to revisit this
	genre.get_genre(genren);
}

void Book::display() {

	char temp = 'N';

	std::cout << "ISBN: " << isbn << "\n";
	std::cout << "Title: " << title << "\n";
	std::cout << "Author: " << author << "\n";
	genre.display();
	std::cout << "\n";
	std::cout << "Read: " << read << "\n";
	std::cout << "Available: " << inlibrary << "\n";
}

// Expand on this later or change to valid_isbn
bool valid_book(std::string workstr) {

	int found = -1;
	int delimctr = 0;
	std::string result;

	// Check ISBN number - Format (N-N-N-X) - Where N = integer and X = Alphanumeric
	for (int i = 0; i < 4; i++) {
		found = workstr.find("-");
		if (found != std::string::npos) {
			result = workstr.substr(0, found);
			workstr = workstr.substr(found + 1);
			// Found '-', now lets make sure it is an integer value
			for (int j = 0; j < result.size(); j++) {
				if (!int{ result[j] }) return false;
			}
			delimctr++;
		}
		else {
			// No more '-'
			result = workstr;
			// Assume 'X' and check if AlphaNumeric
			for (int j = 0; j < result.size(); j++) {
				if (!isalnum(result[j])) return false;
			}
		}
	}
	// Did we find three '-' ?
	if (delimctr != 3) return false;
	return true;
}
