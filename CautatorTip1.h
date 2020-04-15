#pragma once
#include "Cautator.h"

class CautatorTip1 : public Cautator {		//clasa pentru cautatorii de tip 1
	static unsigned id;

public:
	CautatorTip1(Harta&);					//constructor
	void mutare();							//metoda prin care se misca pe tabla
};

