#pragma once
#include "Cautator.h"

class CautatorTip3 : public Cautator {		//clasa pentru cautatorii de tip 3
public:
	CautatorTip3(Harta&);	//constructor
	void mutare(Harta&);	//metoda prin care se misca pe tabla
};

