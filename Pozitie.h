#pragma once
class Pozitie {			//clasa pentru retinerea pozitiei unui agent/comoara
	int lin, col;

public:
	Pozitie(int, int);												//constructor
	Pozitie(const Pozitie& p);										//constructor de copiere
	void setPozitie(int, int);										//setare pozitie
	int getLinie() const;											//obtinere linie
	int getColoana() const;											//obtinere coloana
	Pozitie operator = (const Pozitie&);							//operator = supraincarcat
	friend bool operator == (const Pozitie&, const Pozitie&);		//operator == supraincarcat
	friend bool operator !=(const Pozitie&, const Pozitie&);		//operator != supraincarcat
};