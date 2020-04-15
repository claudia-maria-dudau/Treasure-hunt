#pragma once
class Pozitie {														//clasa pentru retinerea pozitiei unui agent/comoara
	int lin, col;

public:
	Pozitie(int, int);												//constructor
	void setPozitie(int, int);										//setare pozitie
	int getLinie() const;											//obtinere linie
	int getColoana() const;											//obtinere coloana
	friend bool operator == (const Pozitie&, const Pozitie&);		//operator == supraincarcat
};