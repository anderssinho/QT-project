// File to test different classes in
#include <crtdbg.h>
#include <locale.h> 
#include "Competitor.h"
#include "Amateur.h"
#include "Professional.h"
#include "CompetitionHandler.h"


using namespace std;


int main()
{
	setlocale(LC_ALL, "swedish");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CompetitionHandler obj1, obj2;
	obj1.addAmateur("Viktor Andersson", "Man", 26, "Karlskrona");
	obj1.addProfessional("Daniel Lindgren", "Man", 30, "Borlänge SK", 5);
	obj2.addAmateur("John Bjenstam", "Man", 30, "Göteborg");


	cout << obj1.showAll();
	cout << obj2.showAll();

	obj1 = obj2;
	cout << obj1.showAll();

	system("Pause");

	return 0;
}