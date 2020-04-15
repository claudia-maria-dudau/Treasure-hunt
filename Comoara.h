#pragma once
#include "Pozitie.h"
#include "Harta.h"
#include <string>
#include <iostream>
using namespace std;

class Comoara {										//clasa pt comorile de pe harta
	Pozitie poz;
	static unsigned id;
	string ID = "";

public:
	Comoara(const int);								//constructor
	~Comoara();										//destructor
	void gasitComoara(const string, Harta&);		//gasire comoara
};
