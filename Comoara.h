#pragma once
#include "Pozitie.h"
#include "Harta.h"
#include <string>
#include <iostream>
using namespace std;

class Comoara {										//clasa pt comorile de pe harta
	const Pozitie* poz;
	static unsigned id;
	string ID = "";

public:
	Comoara(Harta& );								//constructor
	~Comoara();										//destructor
	void gasitComoara(const string, Harta&);		//gasire comoara
	Pozitie getPoz() const;							//obtinere pozitie
};
