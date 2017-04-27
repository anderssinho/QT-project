#include "Professional.h"

//Överlagrad Konstruktor
Professional::Professional(string name, string gender, int age, string club, int nrOfSeasons) : Competitor(name, gender, age)
{
	this->club = club;
	this->nrOfSeasons = nrOfSeasons;
}

//Destructor
Professional::~Professional()
{
}

//Set
void Professional::setClub(string club)
{
	this->club = club;
}

void Professional::setNrOfSeasons(int nrOfSeasons)
{
	this->nrOfSeasons = nrOfSeasons;
}

//Get
string Professional::getClub()const
{
	return this->club;
}

int Professional::getNrOfSeasons()const
{
	return this->nrOfSeasons;
}

string Professional::printSpec()const
{
	stringstream ss;

	ss << "Klubb: " << this->club << endl;
	ss << "Antal säsonger: " << this->nrOfSeasons << endl;
	ss << "Professional" << endl;

	return ss.str();
}