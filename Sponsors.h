#ifndef SPONSORS_H
#define SPONSORS_H

#include "Professional.h"

using namespace std;

class Sponsors : public Professional
{
public:
	Sponsors(string name, string gender, int age, string club, int nrOfSeasons);


private:
	string initiate(int start = 0);
	string expand();
};

#endif