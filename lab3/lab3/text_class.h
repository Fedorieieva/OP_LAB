#pragma once
#include <iostream>
#include <string>

using namespace std;

class Text {
    string content;

public:
    Text();
    void add_str(string str);
    void print_text();
    double consonant_percentage();
};