#pragma once
#include "Pozitie.h"
#include "Harta.h"
#include <iostream>
#include <string>
using namespace std;

class Cautator {							//clasa abstracta pe care o mostenesc celelate clase de cautatori
protected:
	Pozitie* poz;
	int arieVizibilitate;
	static unsigned id;
	string ID = "", stadiu = "";

public:
	Cautator();								//constructor
	virtual ~Cautator();					//destructor virtual
	string getID() const;					//obtinere ID
	virtual void mutare() = 0;				//metoda prin care fiecare cautator se muta cu o pozitie
};

