#ifndef AMATEUR_H
#define AMATEUR_H

#include "Competitor.h"

class Amateur : public Competitor
{
public:
	//Overloaded contructor
	Amateur(string name, string gender, int age, string city);

	//Destructor
	virtual ~Amateur();

	//Set
	void setCity(string city);

	//Get
	string getCity()const;

	//Print
	string printSpec()const;

private:
	//Private member variables
	string city;
};

#endif