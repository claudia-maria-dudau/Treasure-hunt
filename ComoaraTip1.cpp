#include "ComoaraTip1.h"

ComoaraTip1::ComoaraTip1(Harta& h) : Comoara(h) {
	this->ID += "C1";

	//initializare lista cautatori compatibili
	compatibil.insert("C2");
	compatibil.insert("C3");
	compatibil.insert("C4");
}

void ComoaraTip1::gasitComoara(const string idCaut) {
	cout << "Comoara " << this->ID.substr(0, 1) +  "a fost gasita de cautarorul " + idCaut.substr(0, 1) + " :) ";
	cout << "Not bad pal" << endl;
}