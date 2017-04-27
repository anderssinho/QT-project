//Baseclass for participants
#ifndef COMPETITOR_H
#define COMPETITOR_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Competitor
{
public:
	//Constructors
	Competitor();
	Competitor(string name, string gender, int age);

	//Destructor
	virtual ~Competitor();

	//Set
	void setName(string name);
	void setGender(string gender);
	void setAge(int age);

	//Get
	string getName()const;
	string getGender()const;
	int getAge()const;

	//Print
	string print()const;

	//Pure virtual
	virtual string printSpec() const = 0;

	//Private member variables
private:
	string name;
	string gender;
	int age;

};
#endif