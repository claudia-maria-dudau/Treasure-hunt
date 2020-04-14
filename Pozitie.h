#pragma once
class Pozitie {					//clasa pentru retinerea pozitiei unui agent/comoara
	int lin, col;

public:
	Pozitie(int l = 0, int c = 0);
	bool operator == (const Pozitie& p);

	friend class Cautator;
	friend class Harta;
};