// Future: Add Sub-Genres ?
#include "Genre.h"
#include <iostream>

// Consturctors
Genre::Genre(int idg, std::string nameg)
	:id{ idg }, name{ nameg }
{
	if (!valid_genre(idg, nameg)) throw std::exception("Invalid Genre");
}

Genre::Genre()
	: id{ 0 }, name{ "Default" }
{

}

void Genre::get_genre(Genre genren) {
	
	id = genren.set_id();
	name = genren.set_name();
}

void Genre::add() {
	
	std::cout << "Genre Id: ";
	std::cin >> id;
	std::cout << "Name: ";
	std::cin >> name;
}

void Genre::display() {
	if (id > -1) {
		std::cout << id << " - " << name;
	}
}

// Use this function to test if valid, only checking ID - Keep open for future checks
bool valid_genre(int idg, std::string nameg) {

	if (idg <= 0 || nameg == "") return false;

}