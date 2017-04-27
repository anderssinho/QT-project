#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include "Competitor.h"


class Professional : public Competitor
{
public:

	//Overloaded Constructor (M�ste skicka med parametrarna ifr�n den �rvda basklassen)
	Professional(string name, string gender, int age, string club, int nrOfSeasons);

	//Destructor
	virtual ~Professional();

	//Set
	void setClub(string club);
	void setNrOfSeasons(int nrOfSeasons);

	//Get
	string getClub()const;
	int getNrOfSeasons()const;

	//Print
	string printSpec()const;

	//TODO SPONSOR

private:
	//Private member variables
	string club;
	int nrOfSeasons;
};



#endif