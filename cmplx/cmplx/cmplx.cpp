// cmplx.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "cmplx.h"

/*   M E T H O D S   */

complex::complex(double r, double i, complex_format type) {
	if (type == CARTESIAN) {
		//cartesian format a + jb
		real = r;
		imaginary = i;
		magnitude = sqrt(pow(r, 2) + pow(i, 2));
		if ((r > 0) && (i >= 0)) {
			phase = atan(i / r);
		}
		else if ((r <= 0) && (i > 0)) {
			phase = DEG_TO_RAD(90) + atan(-r / i);
		}
		else if ((r < 0) && (i <= 0)) {
			phase = DEG_TO_RAD(180) + atan(i / r);
		}
		else if ((r >= 0) && (i < 0)) {
			phase = DEG_TO_RAD(270) + atan(-r / i);
		}
		else {
			phase = 0;
		}
	}
	else {
		//polar format A/_angle 
		magnitude = r;
		phase = i;
		real = r * cos(i);
		imaginary = r * sin(i);
	}
}

double complex::re() {
	return real;
}
double complex::im() {
	return imaginary;
}
double complex::mag() {
	auto &r = real;
	auto &i = imaginary;
	magnitude = sqrt(pow(r, 2) + pow(i, 2));
	return magnitude;
}	  
double complex::ph() {
	auto &i = imaginary;
	auto &r = real;
	if ((r > 0) && (i >= 0)) {
		phase = atan(i / r);
	}
	else if ((r <= 0) && (i > 0)) {
		phase = DEG_TO_RAD(90) + atan(-r / i);
	}
	else if ((r < 0) && (i <= 0)) {
		phase = DEG_TO_RAD(180) + atan(i / r);
	}
	else if ((r >= 0) && (i < 0)) {
		phase = DEG_TO_RAD(270) + atan(-r / i);
	}
	else {
		phase = 0;
	}
	return phase;
}

/*  O P E R A T O R S  */

complex operator+(complex a, complex b) {
	return complex{ a.re() + b.re(), a.im() + b.im(), CARTESIAN };
}

complex operator+(complex a, double b) {
	return complex{ a.re() + b, a.im(), CARTESIAN };
}

complex operator+(complex a, int b) {
	return complex{ a.re() + (double)b, a.im(), CARTESIAN };
}


complex operator*(complex a, complex b) {
	return complex{ a.mag() * b.mag(), a.ph() + b.ph(), POLAR };
}

complex operator*(complex a, double b) {
	return complex{ a.mag() * b, a.ph(), POLAR };
}

complex operator*(complex a, int b) {
	return complex{ a.mag() * (double)b, a.ph(), POLAR };
}

complex cpow(complex a, double b) {
	return complex{pow(a.mag(),b), b * a.ph(), POLAR};
}


/*  C O M P A R E  */

bool operator==(complex a, complex b) {
	if ((a.re() == b.re()) && (a.im() == b.im())) {
		return true;
	}
	else {
		return false;
	}
}


