#pragma once
class Pozitie {								//clasa pentru retinerea pozitiei unui agent/comoara
	int lin, col;

public:
	Pozitie(int l = 0, int c = 0);			//constructor
	void setPozitie(int, int);				//setare pozitie
	int getLinie() const;					//obtinere linie
	int getColoana() const;					//obtinere coloana
	bool operator == (const Pozitie&);		//operator == supraincarcat
};