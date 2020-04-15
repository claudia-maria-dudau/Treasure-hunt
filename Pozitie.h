#pragma once
class Pozitie {								//clasa pentru retinerea pozitiei unui agent/comoara
	int lin, col;

public:
	Pozitie(int l = 0, int c = 0);			//constructor
	void setPozitie(int, int);				//setare pozitie
	bool operator == (const Pozitie& p);	//operator == supraincarcat
};