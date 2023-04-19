#include "class_TBall.h"

TBall::TBall() { radious = 1; }

TBall::TBall(double val) { radious = val; }

double TBall::area() {
	return 4 * M_PI * pow(radious, 2);
}

double TBall::volume() {
	return 4.0 / 3.0 * M_PI * pow(radious, 3);
}

ostream& operator <<(ostream& os, const TBall& b) {
	os << "radious = " << setw(8) << left << b.radious;
	return os;
}