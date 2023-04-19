#include "class_TParallelepiped.h"

TParallelepiped::TParallelepiped() { height = 1; length = 1; width = 1; }

TParallelepiped::TParallelepiped(double h_val) :TParallelepiped() {
	height = h_val;
}

TParallelepiped::TParallelepiped(double h_val, double l_val) :TParallelepiped(h_val) {
	length = l_val;
}

TParallelepiped::TParallelepiped(double h_val, double l_val, double w_val) :TParallelepiped(h_val, l_val) {
	width = w_val;
}

double TParallelepiped::area() {
	return 2 * ((height * length) + (height * width) + (length * width));
}

double TParallelepiped::volume() {
	return height * length * width;
}

ostream& operator <<(ostream& os, const TParallelepiped& p) {
	os << "height = " << setw(8) << left << p.height;
	os << "lenght = " << setw(8) << left << p.length;
	os << "width = " << setw(8) << left << p.width;
	return os;
}