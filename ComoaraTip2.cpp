#include "ComoaraTip2.h"

ComoaraTip2::ComoaraTip2(Harta& h) : Comoara(h) {
	this->ID += "C2";

	//initializare lista cautatori compatibili
	compatibil.insert("C1");
	compatibil.insert("C2");
	compatibil.insert("C4");
}

void ComoaraTip2::gasitComoara(const string idCaut) {
	cout << "Comoara " << this->ID.substr(0, 1) + "a fost gasita de cautarorul " + idCaut.substr(0, 1) + " :) ";
	cout << "(Fireworks in the background)" << endl;
}