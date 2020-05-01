#pragma once
#include "Cautator.h"
class CautatorTip4 : public Cautator {		//clasa pentru cautatorii de tip 4
public:
	CautatorTip4(Harta&);		//constructor
	void mutare(Harta&);		//metoda prin care se misca pe tabla
};

