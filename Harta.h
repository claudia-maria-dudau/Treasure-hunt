#pragma once
#include "Cautator.h"
#include "Comoara.h"
#include <vector>
#include <iostream>
using namespace std;

class Harta {											//clasa pentru gestionarea hartii
	const int nrLin, nrCol;
	int nrCasuteExplorate;
	char** M;
	vector<Cautator*> cautatori;
	vector<Comoara*> comori;

public:
	Harta(const int);									//constructor
	~Harta();											//destructor

	friend ostream& operator <<(ostream&, Harta&);		//operator << supraincarcat

	friend class Cautator;
	friend class Comoara;
};

