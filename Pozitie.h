#pragma once
class Pozitie {								//clasa pentru retinerea pozitiei unui agent/comoara
	int lin, col;

public:
	Pozitie(int l = 0, int c = 0);			//constructor
	bool operator == (const Pozitie& p);	//operator == supraincarcat
};