#include "Date.h"

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}


Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

int Date::getDayOfWeek() {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int dayOfWeek = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return dayOfWeek;
}

