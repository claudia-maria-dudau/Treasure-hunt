#include "ComoaraTip1.h"

ComoaraTip1::ComoaraTip1(Harta& h) : Comoara(h) {
	this->ID += "C1";

	//initializare lista cautatori compatibili
	compatibil.insert("LC");
	compatibil.insert("BB");
	compatibil.insert("SM");
}

void ComoaraTip1::gasitComoara(const string numeCaut) {
	cout << "Comoara " << this->ID.substr(0, 1) +  " a fost gasita de " + numeCaut + " :) ";
	cout << "Not bad pal" << endl;
}