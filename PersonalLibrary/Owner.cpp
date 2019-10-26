#include "Owner.h"
#include <iostream>

Owner::Owner(int ido, std::string nameo, double owedo) 
	:id {ido}, name{nameo}, owed{owedo}
{
	if (!valid_owner(ido, nameo)) throw std::exception("Invalid Owner");
}

Owner::Owner()
	: id{ 0 }, name{ "" }, owed{ 0.0 }
{

}

void Owner::display() {
	std::cout << "Id: " << id << "\n";
	std::cout << "Name: " << name << "\n";
}

bool valid_owner(int ido, std::string nameo) {
	if (ido <= 0 || nameo == "") return false;
}