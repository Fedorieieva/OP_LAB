#include <iostream>
#include "train_schedule.h"
#include "train_struct.h"
#include "intro.h"

using namespace std;

int main() {

	intro();
	Train_schedule train_schedule;
	string filename = train_schedule.input_for_file();
	train_schedule.read_file(filename);
	train_schedule.winter_schedule(filename);

	return 0;
}
