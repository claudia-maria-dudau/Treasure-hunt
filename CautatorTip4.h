#pragma once
#include "Cautator.h"
class CautatorTip4 : public Cautator {		//clasa pentru cautatorii de tip 3
	static unsigned id;

public:
	CautatorTip4(Harta&);					//constructor
	void mutare();							//metoda prin care se misca pe tabla
};

