#pragma once
#include "Cautator.h"

class CautatorTip2 : public Cautator {		//clasa pentru cautatorii de tip 2
	static unsigned id;

public:
	CautatorTip2(Harta&);					//constructor
	void mutare();							//metoda prin care se misca pe tabla
};

