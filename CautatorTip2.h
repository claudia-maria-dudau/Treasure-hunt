#pragma once
#include "Cautator.h"

class CautatorTip2 : public Cautator {		//clasa pentru cautatorii de tip 2
	Pozitie* pozAnt;

public:
	CautatorTip2(Harta&);					//constructor
	~CautatorTip2();						//destructor
	void mutare(Harta&);					//metoda prin care se misca pe tabla
};

