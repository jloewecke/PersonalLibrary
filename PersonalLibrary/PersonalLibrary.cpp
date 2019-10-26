// PersonalLibrary.cpp :
// TODO: 
//	- Rethink the menu flow
//	- COUT and CIN statements in classes seem wrong.
//	- Refactor classes, some logic needs to be moved from one class to another or just deleted
//	- "GENRE" logic needs to be rethought out, its a cluster because i cant make up mind on how i want to do it
//	- Write error logic and handeling - This version pretty much treats all errors as fatal
//	- Add input validation
//	- Add Reporting system/ and or comment/ review system
//	- Add Option to export to file or retool and use a database
//	- Apparently i broke Book::valid_book() somehow
//	- Write or more likely just delete the USER option, it seems a useless option for what im going for.
//	- If i ever make up my mind on how to handle the GENRE, write the add/delete/modify code for that

// MISC:
//	- Create a reusable MENU class, so i dont keep writing the same code over and over and over
//	- I like to learn by repetition, but i think i got that down.
//	- Figure out where to save reusable classes on windows, im sure its the same concept as Linux and OPENVMS, but
//	- for some i keep being indecisive and trying way to many things instead of just making one work.
//	- I.E - Stop reading, and just make it work.

// FUTURE:
//	- Add Postgres DB functionality
//	- Port to GUI - Winforms, UWP, WPF(no c++ support ?)
//	- Boot into linux and write the same project from scratch to see design differences.
//	- Write a QT version in Linux



#include <iostream>

// Class Includes
#include "Genre.h"
#include "Book.h"
#include "Owner.h"
#include "Library.h"


// Function Declarations
int main_menu();
void book_menu(Library& lib);
Book b;

void user_menu(Library& lib);

// Main Program
int main()
{
	std::cout << "\n\nPERSONAL LIBRARY ORGANIZER\n";
	try {
		bool running = true;
		int choice = -1;
		Library lib;
		lib.load_default_genres();

		while (running) {
			choice = main_menu();
			switch (choice) {
			case 1:
				book_menu(lib);
				break;
			case 2:
				user_menu(lib);
				break;
			case 3:
				break;
			case 4:
				running = false;
				break;
			default:
				std::cout << "\n***Invalid choice " << choice << std::endl;
				break;
			}
		}
	}
	catch (std::exception& e) {
		std::cout << "\n\nERROR ENCOUNTERED...\n";
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (...) {
		std::cout << "\n\nERROR ENCOUNTERED...\n";
		std::cerr << "Un-Handled Error: " << std::endl;
		return 2;
	}

	return 0;
}

// Function Definitions
int main_menu() {

	int choice = -1;
	std::cout << "\n\nLIBRARY MENU\n";
	std::cout << "1). Books\n";
	std::cout << "2). Users\n";
	std::cout << "3). Genres\n";
	std::cout << "4). Exit\n";
	std::cout << "Choice: ";
	std::cin >> choice;

	if (choice < 1 || choice > 4) return -1;
	return choice;
}

void user_menu(Library& lib) {

}

void book_menu(Library& lib) {

	int choice = -1;
	bool b_menu = true;
	Book b;

	while (b_menu) {
		std::cout << "\n\nBOOK MENU\n";
		std::cout << "1). Add Book\n";
		std::cout << "2). List Books\n";
		std::cout << "3). Check in/out\n";
		std::cout << "4). Exit\n";
		std::cout << "Choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			b.add();
			std::cout << "\nSelect Genre:\n";
			b.set_book_genre(lib.select_genre());
			lib.add_book(b);
			break;
		case 2:
			lib.display_books();
			break;
		case 3:
			lib.select_book();
			if (b.available()) {
				std::cout << "\n***Checking Book out of Library\n";
				b.check_out();
			}
			else {
				std::cout << "\n***Returning book to Library\n";
				b.check_in();
			}
		case 4:
			b_menu = false;
			break;
		default:
			std::cout << "\n***Invalid choice: " << std::endl;
			break;
		}
	}
}

