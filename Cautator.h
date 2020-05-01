#pragma once
#include "Pozitie.h"
#include "Harta.h"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Cautator {	//clasa abstracta pe care o mostenesc celelate clase de cautatori
protected:
	Pozitie* poz;
	int arieVizibilitate;
	static unsigned id;
	string ID = "", stadiu = "", nume = "";

public:
	Cautator();								//constructor
	virtual ~Cautator();					//destructor virtual
	string getID() const;					//obtinere ID
	Pozitie getPoz() const;					//obtinere pozitie
	void setStadiu(const string);			//setarea stdiu
	string getStadiu() const;				//obtinere stadiu
	string getNume() const;					//obtinere nume cautator;
	virtual void mutare(Harta&) = 0;		//metoda prin care fiecare cautator se muta cu o pozitie
};

