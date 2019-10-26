// Cant decide if i should delete this class and just use a enum in the book class
// Oh well, i already wrote this code, so will use it for the time being
// enum class Genre {fiction = 1, biography, horror, etc } - This seems better, but takes away
// the ability of the user to create a new Genre. 
// Maybe hard code some default Genres ?


#pragma once
#include<string>

class Genre
{
public:
	// Constuctors
	Genre(int id, std::string name);
	Genre();

	int set_id() { return id; }
	std::string set_name() { return name; }
	// Dont like these get functions
	void get_genre(Genre genren);
	void display();
	void add();


private:
	int id;
	std::string name;
	// We Should break this down further into sub categories
};

// Helper Functions
bool valid_genre(int id, std::string name);	// Validate the Genre
