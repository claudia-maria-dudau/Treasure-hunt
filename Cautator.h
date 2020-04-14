#pragma once
#include "Pozitie.h"

class Cautator {							//clasa abstracta pe care o mostenesc celelate clase de cautatori
protected:
	Pozitie poz;

public:
	Cautator(const int l, const int c);		//constructor
	virtual ~Cautator();					//destructor virtual
	virtual void mutare() = 0;				//metoda prin care fiecare cautator se muta cu o pozitie
};

