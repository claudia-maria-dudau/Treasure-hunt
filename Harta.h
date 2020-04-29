#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Harta {											//clasa pentru gestionarea hartii
	int nrLin, nrCol;
	int nrCasuteExplorate;
	char** M;

public:
	Harta(const int, const int);						//constructor
	~Harta();											//destructor
	int getNrCasuteNeexplorate() const;					//obtinere nr de casute neexplorate
	void cresteNrCasuteExplorate();						//cresc nr de casute explorate cu 1
	void marchezVizitat(const int, const int);			//marchez pozitia ca fiind vizitata
	bool apartine(const int, const int) const;			//verific daca o pozitie apartine hartii
	friend ostream& operator <<(ostream&, Harta&);		//operator << supraincarcat

	friend class CautatorTip1;
	friend class CautatorTip2;
	friend class CautatorTip3;
	friend class CautatorTip4;
	friend class Comoara;
};

