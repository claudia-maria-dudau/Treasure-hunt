#pragma once
#include "Cautator.h"

class CautatorTip3 : public Cautator {		//clasa pentru cautatorii de tip 3
	static unsigned id;

public:
	CautatorTip3(Harta&);					//constructor
	void mutare();							//metoda prin care se misca pe tabla
};

