#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "train_struct.h"

using namespace std;

class Train_schedule {
public:
	string input_for_file();
	void read_file(const string& filename, string schedule = "Summer Schedule");
	void winter_schedule(const string& filename);

private:
	void write_to_file(const string& filename, const Train& train);
	void print_title(const string& schedule);
};