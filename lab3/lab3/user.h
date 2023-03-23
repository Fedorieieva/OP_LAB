#pragma once
#include <iostream>
#include <string>
#include "text_class.h"

using namespace std;

void print_precent(Text* txt, int n);
void print_contents(Text* txt, int n);
int find_max_precent(Text* txt, int n);
void first_input(Text* txt, int initial, int& n);
void append(Text* txt);
void user();