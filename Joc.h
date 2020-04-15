#pragma once
#include "Harta.h"
#include "Cautator.h"
#include "Comoara.h"
#include <iostream>

using namespace std;

class Joc {								//clasa pentru gestionarea jocului
	Harta *h;
	static int idRunda;
	vector<Cautator*> cautatori;
	vector<Comoara*> comori;

public:
	Joc(const int, const int);			//constructor
	~Joc();								//destructor
	void runda();						//simulare runda
	void afisare();						//afisare harta dupa runda
};

