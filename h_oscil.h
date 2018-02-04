#ifndef H_OSCIL
#define H_OSCIL

#include <stdint.h>
// A classical harmonic oscillator
class CHarmonic_Oscillator {
public:
	double t; // Absolute time since creation.
	double m; // Rest mass
	double k; // Hooke's Constant
	double v; // Velocity
	double x; // Current position (equilibria at 0)
	double T; // Kinetic Energy
	double V; // PE
	double U; // Total
	
	CHarmonic_Oscillator(double m, double k, double i); // i = impulse
	void Update(void); // Updates the oscillator
	
};

#endif
