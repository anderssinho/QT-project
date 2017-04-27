#ifndef COMPETITONHANDLER_H
#define COMPETITONHANDLER_H

#include <iostream>
#include "Competitor.h"
#include "Professional.h"
#include "Amateur.h"

using namespace std;

class CompetitionHandler
{
public:
	//Constructors
	CompetitionHandler();
	CompetitionHandler(const CompetitionHandler& original);

	//Destructor
	~CompetitionHandler();

	//Allocation operator
	CompetitionHandler& operator=(const CompetitionHandler& original);

	//Add-functions
	void addAmateur(string name, string gender, int age, string city);
	void addProfessional(string name, string gender, int age, string club, int nrOfSeasons);

	//Show-functions
	string showAll()const;
	string showAmatuer()const;
	string showPro()const;
	void setNrOfSeasonsPro(string name, int nrOfSeasons)const;

	//Remove
	void removeGivenName(string name);

private:
	//Medlemsvariabler
	void expand();
	void free();
	void initiate(int start = 0);


	Competitor** Handler;
	int capacity;
	int nrOfElement = 0;

};
#endif