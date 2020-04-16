#pragma once
#include "Pozitie.h"
#include "Harta.h"
#include <string>
#include <iostream>
#include <set>

using namespace std;

class Comoara {											//clasa abstracta de baza pentru comorile de pe harta
protected:
	const Pozitie* poz;
	static unsigned id;
	string ID = "";
	set<string> compatibil;

public:
	Comoara(Harta& );									//constructor
	~Comoara();											//destructor
	virtual void gasitComoara(const string) = 0;		//gasire comoara
	Pozitie getPoz() const;								//obtinere pozitie
	set<string> getCompatibil() const;					//obtinere lista de cautatoti compatibili cu comoara
};
