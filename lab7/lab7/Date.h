#pragma once
#include <iostream>


class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);
    int getDayOfWeek();
};