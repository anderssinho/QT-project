#include "CompetitionHandler.h"

//Initiate
void CompetitionHandler::initiate(int start)
{
	for (int i = start; i<this->capacity; i++)
	{
		this->Handler[i] = nullptr;
	}
}

//Expand
void CompetitionHandler::expand()
{
	this->capacity += 10;
	Competitor** temp = new Competitor*[this->capacity];

	for (int i = 0; i < this->nrOfElement; i++)
	{
		temp[i] = this->Handler[i];
	}

	delete[] this->Handler;

	this->Handler = temp;

	this->initiate(this->nrOfElement);
}

//Clean memory
void CompetitionHandler::free()
{
	//iterate through all elements
	for (int i = 0; i<this->nrOfElement; i++)
	{
		delete this->Handler[i];
	}

	delete[] this->Handler;
}

//Constructor
CompetitionHandler::CompetitionHandler()
{
	this->capacity = 10;
	this->Handler = new Competitor*[this->capacity];
	this->initiate();
}

//Destructor
CompetitionHandler::~CompetitionHandler()
{
	this->free();
}

//Copy-constructor
CompetitionHandler::CompetitionHandler(const CompetitionHandler& original)
{
	Competitor* temp;

	this->nrOfElement = original.nrOfElement;
	this->capacity = original.capacity;

	this->Handler = new Competitor*[this->capacity];

	for (int i = 0; i < this->nrOfElement; i++)
	{
		temp = original.Handler[i];

		//Dynmic-cast to check if it's pro or amateur 
		Professional* Pro = dynamic_cast<Professional*>(original.Handler[i]);
		Amateur* Ama = dynamic_cast<Amateur*>(original.Handler[i]);

		if (Pro != nullptr)
		{
			Handler[i] = new Professional(*Pro);
		}
		else
		{
			Handler[i] = new Amateur(*Ama);
		}
	}

	this->initiate(this->nrOfElement);
}

//Assignment operator
CompetitionHandler& CompetitionHandler::operator=(const CompetitionHandler& original)
{
	// Self assignment check
	if (this == &original)
	{
		return *this;
	}

	else
	{
		this->free();
		Competitor* temp;

		this->nrOfElement = original.nrOfElement;
		this->capacity = original.capacity;

		this->Handler = new Competitor*[this->capacity];

		for (int i = 0; i < this->nrOfElement; i++)
		{
			temp = original.Handler[i];

			//Dynmic-cast to check if it's pro or amateur 
			Professional* Pro = dynamic_cast<Professional*>(original.Handler[i]);
			Amateur* Ama = dynamic_cast<Amateur*>(original.Handler[i]);

			if (Pro != nullptr)
			{
				Handler[i] = new Professional(*Pro);
			}
			else
			{
				Handler[i] = new Amateur(*Ama);
			}
		}

		this->initiate(this->nrOfElement);
		return *this;
	}

}

//Add
void CompetitionHandler::addAmateur(string name, string gender, int age, string city)
{
	if (this->nrOfElement == this->capacity)
	{
		this->expand();
	}

	this->Handler[this->nrOfElement++] = new Amateur(name, gender, age, city);
}

void CompetitionHandler::addProfessional(string name, string gender, int age, string club, int nrOfSeasons)
{
	if (this->nrOfElement == this->capacity)
	{
		this->expand();
	}

	this->Handler[this->nrOfElement++] = new Professional(name, gender, age, club, nrOfSeasons);
}

//Show
string CompetitionHandler::showAll()const
{
	stringstream ss;

	for (int i = 0; i < this->nrOfElement; i++)
	{
		ss << Handler[i]->print();
	}
	return ss.str();
}

string CompetitionHandler::showAmatuer()const
{
	stringstream ss;

	for (int i = 0; i < this->nrOfElement; i++)
	{

		//Dynmic cast för att ta reda vilken typ
		Amateur* Ama = dynamic_cast<Amateur*>(Handler[i]);


		if (Ama != nullptr)
		{
			ss << Handler[i]->print();
		}
	}

	return ss.str();
}

string CompetitionHandler::showPro()const
{
	stringstream ss;
	for (int i = 0; i < this->nrOfElement; i++)
	{
		//Dynmic cast för att ta reda vilken typ
		Professional* Pro = dynamic_cast<Professional*>(Handler[i]);

		if (Pro != nullptr)
		{

			ss << Handler[i]->print();
		}

	}

	return ss.str();
}

//Set
void CompetitionHandler::setNrOfSeasonsPro(string name, int nrOfSeasons)const
{
	for (int i = 0; i < this->nrOfElement; i++)
	{
		if (name == Handler[i]->getName())
		{
			//Dynmic cast för att ta reda vilken typ
			Professional* Pro = dynamic_cast<Professional*>(this->Handler[i]);

			if (Pro != nullptr)
			{
				Pro->setNrOfSeasons(nrOfSeasons);
			}
		}
	}
}

//Remove given name
void CompetitionHandler::removeGivenName(string name)
{
	for (int i = 0; i < this->nrOfElement; i++)
	{
		if (name == Handler[i]->getName())
		{
			delete this->Handler[i];
			this->Handler[i] = NULL;
			this->nrOfElement--;

			if (i != nrOfElement)
			{
				this->Handler[i] = this->Handler[this->nrOfElement];
				this->Handler[this->nrOfElement] = NULL;
			}
		}
	}
}