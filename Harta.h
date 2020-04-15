#pragma once
#include "Cautator.h"
#include "Comoara.h"
#include <vector>
#include <iostream>
using namespace std;

class Harta {											//clasa pentru gestionarea hartii
	int nrLin, nrCol;
	int nrCasuteExplorate;
	char** M;

public:
	Harta(const int, const int);						//constructor
	~Harta();											//destructor
	int getNrCasuteNeexplorate() const;					//obtinere nr de casute neexplorate

	friend ostream& operator <<(ostream&, Harta&);		//operator << supraincarcat

	friend class Cautator;
	friend class Comoara;
};

