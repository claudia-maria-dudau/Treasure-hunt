#pragma once
#include "Cautator.h"
#include "Comoara.h"
#include <vector>
using namespace std;

class Harta {									//clasa pentru gestionarea hartii
	const int nrLin, nrCol;
	bool** M;
	vector<Cautator*> cautatori;
	vector<Comoara*> comori;

public:
	Harta(const int);							//constructor
	~Harta();									//destructor
	void removeCautator(const Cautator& c);		//eliminare cautator din vectorul de cautatori
	void removeComoara(const Comoara& c);		//eliminare comoara din vectorul de comori
};

