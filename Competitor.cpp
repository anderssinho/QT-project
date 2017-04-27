#include "Competitor.h"

//Constructors
Competitor::Competitor()
{
	this->name = "Joe Doe";
	this->gender = "Man";
	this->age = 0;
}

Competitor::Competitor(string name, string gender, int age)
{
	this->name = name;
	this->gender = gender;
	this->age = age;
}

//Destructor
Competitor::~Competitor()
{

}

//Set
void Competitor::setGender(string gender)
{
	this->gender = gender;
}

void Competitor::setName(string name)
{
	this->name = name;
}

void Competitor::setAge(int age)
{
	this->age = age;
}

//Get
string Competitor::getGender()const
{
	return this->gender;
}

string Competitor::getName()const
{
	return this->name;
}

int Competitor::getAge()const
{
	return this->age;
}

//Print function which I use to go to sub-classes
string Competitor::print() const
{
	stringstream ss;

	ss << "Namn: " << this->name << endl;
	ss << "Kön: " << this->gender << endl;
	ss << "Ålder: " << this->age << endl;

	ss << this->printSpec();

	return ss.str();
}


