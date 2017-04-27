#include "Amateur.h"

//Constructor
Amateur::Amateur(string name, string gender, int age, string city) : Competitor(name, gender, age)
{
	this->city = city;
}

//Destructor
Amateur::~Amateur()
{
}

//Set
void Amateur::setCity(string city)
{
	this->city = city;
}

//Get
string Amateur::getCity()const
{
	return this->city;
}

//Print
string Amateur::printSpec()const
{
	stringstream ss;

	ss << "Adress: " << this->city << endl;
	ss << "Amateur" << endl;

	return ss.str();
}