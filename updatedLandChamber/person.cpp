#include "person.h"
#include <string>

Person::Person()
{
}

Person::Person(std::string newName) : name { newName }
{
	
}

std::string Person::getName()
{
	return name;
}

int Holder::idGen{0};

void Holder::addLand(const Plane& land)
{
	m_land.push_back(land);
}

Holder::Holder(std::string name)
{
	id = idGen++;
	baseInfo = name ;
}