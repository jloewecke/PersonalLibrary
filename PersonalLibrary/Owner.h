#pragma once
#include<string>

class Owner
{
public:
	// Constructors
	Owner(int id, std::string name, double owed);
	Owner();

	void display();

private:
	int id;
	std::string name;
	double owed;
	
};

bool valid_owner(int id, std::string name);


