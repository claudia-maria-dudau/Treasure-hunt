#pragma once
#include "Cautator.h"

class CautatorTip1 : public Cautator {		//clasa pentru cautatorii de tip 1
	Pozitie* pozAnt;

public:
	CautatorTip1(Harta&);					//constructor
	~CautatorTip1();						//destructor
	void mutare(Harta&);					//metoda prin care se misca pe tabla
};

