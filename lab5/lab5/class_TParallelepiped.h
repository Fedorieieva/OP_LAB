#pragma once
#include <iostream>
#include <iomanip>
#include "class_TBody.h"

using namespace std;

class TParallelepiped : public Tbody {
private:
	double height;
	double length;
	double width;

public:
	TParallelepiped();
	TParallelepiped(double h_val);
	TParallelepiped(double h_val, double l_val);
	TParallelepiped(double h_val, double l_val, double w_val);
	double area() override;
	double volume() override;
	friend ostream& operator <<(ostream& os, const TParallelepiped& p);
};