#pragma once
#include "Harta.h"
#include "Cautator.h"
#include "CautatorTip1.h"
#include "CautatorTip2.h"
#include "CautatorTip3.h"
#include "CautatorTip4.h"
#include "Comoara.h"
#include "ComoaraTip1.h"
#include "ComoaraTip2.h"
#include "ComoaraTip3.h"
#include <exception>

//clasa pt exceptie ce apare atunci cand nu se mai poate genera o runda
class exceptieJoc : public exception {	
public:
	const char* what() const noexcept { 
		return "Nu se mai poate genera o runda deoarece jocul s-a terminat\n";
	}
};


class Joc {		//clasa pentru gestionarea jocului
	Harta *h;
	static int idRunda;
	vector<Cautator*> cautatori;
	vector<Cautator*> Clasament;		//vector auxiliar pentru clasament
	vector<Comoara*> comori;

public:
	Joc(const int, const int);			//constructor
	~Joc();								//destructor
	void runda();						//simulare runda
	void afisare() const;				//afisare harta dupa runda
	void clasament() const;				//afisare clasament final
	void adaugClasament(Cautator*);		//adaugare in vectorul Clasament
	bool terminat() const;				//verificare daca s-a terminat jocul sau a fost oprit
	void afisareComoriRamase() const;	//afisez comorileramase pe tabla
};

