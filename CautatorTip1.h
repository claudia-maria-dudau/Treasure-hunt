#pragma once
#include "Cautator.h"
class CautatorTip1 : public Cautator {		//clasa pentru cautatorul de tip 1
	static unsigned id;

public:
	CautatorTip1();							//constructor
	void mutare();							//metoda prin care se misca pe tabla
};

