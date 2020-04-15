#pragma once
#include "Harta.h"
#include "Cautator.h"
#include "CautatorTip1.h"
#include "CautatorTip2.h"
#include "CautatorTip3.h"
#include "CautatorTip4.h"
#include "Comoara.h"
#include <exception>

class exceptieJoc : public exception {	//clasa pt exceptie ce apare atunci cand nu se mai poate genera o runda
};


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

