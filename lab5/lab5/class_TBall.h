#pragma once
#include <iostream>
#include <iomanip>
#include "class_TBody.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class TBall : public Tbody {
private:
	double radious;

public:
	TBall();
	TBall(double val);
	double area() override;
	double volume() override;
	friend ostream& operator <<(ostream& os, const TBall& b);
};
