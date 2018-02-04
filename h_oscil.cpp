#include "h_oscil.h"

void CHarmonic_Oscillator::Update(void) {
	double F = - this->k * this->x;
	this->v += (F / this->m);
	this->x += this->v;
	this->T = (0.5)*(this->m)*(this->v)*(this->v);
	this->V = this->U - this->T;
}

CHarmonic_Oscillator::CHarmonic_Oscillator(double m, double k, double i) {
	this->m = m;
	this->k = k;
	this->v = i / this->m; // Impulse delivered
	this->x = 0;
	this->U = (0.5)*(this->m)*(this->v)*(this->v);
	this->T = this->U;
	this->V = 0;
}
